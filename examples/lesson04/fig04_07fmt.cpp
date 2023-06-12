// fig04_07.cpp
// if statements with initializers.
#include <fmt/format.h> // C++20: This will be #include <format> 
#include <iostream>
using namespace std;

int main() {
   if (int value{7}; value == 7) {
      cout << fmt::format("value is {}\n", value);
   }
   else {
      cout << fmt::format("value is not 7; it is {}\n", value);
   }

   if (int value{13}; value == 9) {
      cout << fmt::format("value is {}\n", value);
   }
   else {
      cout << fmt::format("value is not 9; it is {}\n", value);
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
