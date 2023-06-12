// fig03_05.cpp
// Conveniently creating and manipulating super-sized integers
// with objects of the Boost Multiprecision library's cpp_int class.
#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
using namespace std;
using boost::multiprecision::cpp_int;
	
int main() {
   // initializing cpp_ints
   const cpp_int value1{"100000000000000000000000000000"}; // 30 digits
   const cpp_int value2{9223372036854775807LL}; // long long max
   const int value3{3}; 
   
   cout << "INITIAL VALUES"
      << "\ncpp_int value1: " << value1
      << "\ncpp_int value2: " << value2
      << "\n    int value3: " << value3;
   
   // arithmetic with cpp_ints
   cout << "\n\nADD, SUBTRACT AND MULTIPLY CPP_INT OBJECTS"
      << "\nvalue1 + value2: " << value1 + value2
      << "\nvalue1 - value2: " << value1 - value2
      << "\nvalue1 * value2: " << value1 * value2;
   
   // arithmetic mixing cpp_ints and integers
   cout << "\n\nMULTIPLY A CPP_INT OBJECT BY INT VALUES"
      << "\nvalue1 * value3: " << value1 * value3
      << "\n    value1 * 17: " << value1 * 17 << "\n";
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

