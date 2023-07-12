// fig09_36.cpp
// Encrypting and decrypting text with a Vigenère cipher. 
#include "cipher.h"
#include <iostream>
#include <string>

int main() {
   std::string plainText;
   std::cout << "Enter the text to encrypt:\n";
   std::getline(std::cin, plainText);

   std::string secretKey;
   std::cout << "\nEnter the secret key:\n";
   std::getline(std::cin, secretKey);

   Cipher cipher;

   // encrypt plainText using secretKey
   std::string cipherText{cipher.encrypt(plainText, secretKey)};
   std::cout << "\nEncrypted:\n   " << cipherText << '\n';

   // decrypt cipherText
   std::cout << "\nDecrypted:\n   " 
      << cipher.decrypt(cipherText, secretKey) << '\n';
}


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
