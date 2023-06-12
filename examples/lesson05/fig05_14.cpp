// fig05_14.cpp
// Recursive function factorial.
#include <boost/multiprecision/cpp_int.hpp>
#include <format>
#include <iostream>
using boost::multiprecision::cpp_int;
using namespace std;

cpp_int factorial(int number); // function prototype 

int main() {
   // calculate the factorials of 0 through 10
   for (int counter{0}; counter <= 10; ++counter) {
      cout << format("{:>2}! = ", counter) << factorial(counter) 
         << '\n';
   } 

   // display factorials of 20, 30 and 40
   cout << format("\n{:>2}! = ", 20) << factorial(20) 
      << format("\n{:>2}! = ", 30) << factorial(30) 
      << format("\n{:>2}! = ", 40) << factorial(40) << '\n';
} 

// recursive definition of function factorial    
cpp_int factorial(int number) {                     
   if (number <= 1) { // test for base case      
      return 1; // base cases: 0! = 1 and 1! = 1 
   }                                             
   else { // recursion step                      
      return number * factorial(number - 1);     
   }                                             
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
