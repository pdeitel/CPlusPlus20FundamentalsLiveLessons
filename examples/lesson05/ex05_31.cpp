// ex05_31.cpp
// What does this program do?
#include <iostream>
using namespace std;

int mystery(int, int); // function prototype
      
int main() {
   cout << "Enter two integers: ";
   int x{0};
   int y{0};
   cin >> x >> y;
   cout << "The result is " << mystery(x, y) << endl;
} 
   
// Parameter b must be a positive integer to prevent infinite recursion
int mystery(int a, int b) {
   if (1 == b) { // base case
      return a;
   } 
   else { // recursion step
      return a + mystery(a, b - 1);
   } 
} 


/*************************************************************************
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
*************************************************************************/
