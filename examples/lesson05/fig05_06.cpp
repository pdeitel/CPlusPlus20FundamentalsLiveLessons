// fig05_06.cpp
// square function used to demonstrate the function 
// call stack and activation records.
#include <iostream>
using namespace std;

int square(int); // prototype for function square

int main() {
   int a{10}; // value to square (local variable in main)

   int result{square(a)}; // calculate s squared and store in result
} 

// returns the square of an integer
int square(int x) { // x is a local variable
   return x * x; // calculate square and return result
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
