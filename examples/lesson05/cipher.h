// Fig. 9.37: cipher.h
// Vigenère cipher implementation. 
#pragma once
#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <string_view>
#include <cctype>
#include <stdexcept>

class Cipher {
public:
   // constructor to initialize the Vigenère square 
   Cipher() {
      // array to store the 26 characters A-Z that will be 
      // used to initialize each row of the Vigenère square
      std::array<char, m_size> alphabet{};

      // fill alphabet with A-Z
      for (size_t i{0}; i < m_size; ++i) {
         // convert 'A' + i to a char and place in alphabet
         alphabet.at(i) = static_cast<char>('A' + i);
      }

      // copy alphabet into row 0 of the Vigenère square
      m_square.at(0) = alphabet;

      // for each remaining row of the Vigenère square, move alphabet's
      // first letter to the end then copy alphabet into the row
      for (int row{1}; row < m_size; ++row) {
         // rotate alphabet, moving its first letter to the end
         std::ranges::rotate(alphabet, std::begin(alphabet) + 1);

         // copy alphabet into current row of the Vigenère square
         m_square.at(row) = alphabet;
      }
   }

   // encrypt receives the plaintext and secret key, applies 
   // the Vigenère cipher returns the encrypted ciphertext
   std::string encrypt(
      std::string_view plaintext, std::string_view secret) {

      checkKey(secret); // ensure secret key contains only letters

      std::string ciphertext{}; // stores encrypted text
      size_t keyIndex{0}; // current letter index in secret key

      // iterate through each character in plaintext
      for (size_t i{0}; i < plaintext.length(); ++i) {
         // determine whether character at i is lowercase so we can 
         // place a corresponding lowercase letter in the ciphertext
         const bool lower{std::islower(plaintext.at(i)) ? true : false};

         // convert currentChar to uppercase; for uppercase 
         // letters and non-letters the character remains the same
         const char currentChar{static_cast<const char>(
            std::toupper(plaintext.at(i)))};

         // if the current character is a letter, encrypt it  
         // and add it to cipherText in its original case
         if ('A' <= currentChar && currentChar <= 'Z') {
            // to get the row index in the Vigenère square, select the 
            // character at keyIndex in the secret key, convert it to 
            // uppercase and subtract 'A' from it
            const int row{std::toupper(secret.at(keyIndex)) - 'A'};

            // increment the keyIndex, ensuring that it is  
            // reset to 0 if keyIndex reaches secret.length()
            keyIndex = (keyIndex + 1) % secret.length();

            // to get the column index in the Vigenère square,  
            // subtract 'A' from the currentChar
            const int column{currentChar - 'A'};

            // select the substitute character from the Vigenère square
            const char substituteChar{m_square.at(row).at(column)};

            // add substituteChar to the ciphertext, ensuring that
            // it's lowercase if the plaintext character was lowerase
            ciphertext +=
               (lower ? std::tolower(substituteChar) : substituteChar);
         }
         else {
            ciphertext += currentChar; // add non-letter to ciphertext
         }
      }

      return ciphertext; // return the encrypted text
   }

   // decrypt receives the ciphertext and secret key, reverses
   // Vigenère cipher process and returns the unencrypted plaintext
   std::string decrypt(
      std::string_view ciphertext, std::string_view secret) {

      checkKey(secret); // ensure secret key contains only letters

      std::string plaintext{}; // stores unencrypted text
      size_t keyIndex{0}; // current letter index in secret key

      for (size_t i{0}; i < ciphertext.length(); ++i) {
         // determine whether character at i is lowercase so we can 
         // place a corresponding lowercase letter in plainText
         const bool lower{std::islower(ciphertext.at(i)) ? true : false};

         // convert currentChar to uppercase; for uppercase 
         // letters and non-letters the character remains the same
         const char currentChar{static_cast<const char>(
            std::toupper(ciphertext.at(i)))};

         // if current is a letter decrypt it
         if ('A' <= currentChar && currentChar <= 'Z') {
            // to get the row index in the Vigenère square, select the 
            // character at keyIndex in the secret key, convert it to 
            // uppercase and subtract 'A' from it
            const int row{std::toupper(secret.at(keyIndex)) - 'A'};

            // increment the keyIndex, ensuring that it is  
            // reset to 0 if keyIndex reaches secret.length()
            keyIndex = (keyIndex + 1) % secret.length();

            // column in the Vigenère square
            int column{-1};

            // find currentChar's column in Vigenère square's current row
            for (int i{0}; i < m_square.at(row).size(); ++i) {
               if (m_square.at(row).at(i) == currentChar) {
                  column = i;
                  break;
               }
            }

            // determine original character  
            const char originalChar{
               static_cast<const char>('A' + column)};

            // add originalChar to plaintext in the correct case
            plaintext +=
               (lower ? std::tolower(originalChar) : originalChar);
         }
         else {
            plaintext += currentChar; // add non-letter to plaintext
         }
      }

      return plaintext; // return the unencrypted text
   }
private:
   // number of rows and columns in the Vigenère square
   static constexpr size_t m_size{26};

   // 26-by-26 array of characters to store the Vigenère square
   std::array<std::array<char, m_size>, m_size> m_square;

   // utility function checks that secret key contains only letters; 
   // throws an invalid_argument exception if key contains non-letters
   static void checkKey(std::string_view secret) {
      for (size_t i{0}; i < secret.size(); ++i) {
         // if the uppercase version of the character at index i 
         // is not a letter throw an invalid_argument exception
         if (std::toupper(secret.at(i)) < 'A' ||
            std::toupper(secret.at(i)) > 'Z') {
            throw std::invalid_argument(
               "key must contain only letters A-Z or a-z");
         }
      }
   }
};

/**************************************************************************
 * (C) Copyright 1992-2022 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
