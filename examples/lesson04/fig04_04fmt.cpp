// fig04_04.cpp
// Compound-interest calculations with for.
#include <fmt/format.h> // C++20: This will be #include <format> 
#include <iostream>
#include <cmath> // for pow function
using namespace std;

int main() {
   double principal{1000.00}; // initial amount before interest
   double rate{0.05}; // interest rate

   cout << fmt::format("Initial principal: {:>7.2f}\n", principal)
        << fmt::format("    Interest rate: {:>7.2f}\n", rate);

   // display headers
   cout << fmt::format("\n{}{:>20}\n", "Year",  "Amount on deposit");

   // calculate amount on deposit for each of ten years              
   for (int year{1}; year <= 10; ++year) {                           
      // calculate amount on deposit at the end of the specified year
      double amount{principal * pow(1.0 + rate, year)} ;             
                                                                     
      // display the year and the amount                             
      cout << fmt::format("{:>4d}{:>20.2f}\n", year, amount);
   }                                                                 
}



/**************************************************************************
 * (C) Copyright 1992-2023 by Deitel & Associates, Inc. and               *
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
 *************************************************************************/
