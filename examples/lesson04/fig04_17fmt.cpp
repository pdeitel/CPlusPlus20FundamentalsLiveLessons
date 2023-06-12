// fig04_17.cpp
// Compound-interest example with boost::multiprecision::cpp_dec_float_50. 
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <fmt/format.h> // in C++20, this will be #include <format>
#include <iostream>
#include "decimalformatter_fmt.h" 

using namespace std;
using boost::multiprecision::cpp_dec_float_50;

int main() {
   cpp_dec_float_50 principal{1000}; // $1000 initial principal
   cpp_dec_float_50 rate{"0.05"}; // 5% interest rate
 
   cout << fmt::format("Initial principal: {:>7}\n", principal)
      << fmt::format("    Interest rate: {:>7}\n\n", rate);

   // display headers
   cout << fmt::format("{}{:>20}\n", "Year", "Amount on deposit");

   // calculate amount on deposit for each of 10 years
   for (int year{1}; year <= 10; ++year) {
      cpp_dec_float_50 amount{principal * pow(1 + rate, year)};
      cout << fmt::format("{:>4}{:>20}\n", year, amount);
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
 **************************************************************************/
