/*
 * File: AddThree.cpp
 * ------------------
 * This programs generates the sum
 * of three numbers received
 * from the user
 */

#include <iostream>
using namespace std;
int main() {
   double n1, n2, n3;

   cout << "This program generates the sum of three numbers." << endl
        << "Please enter the first number: ";
   cin >> n1;
   cout << "Second number: ";
   cin >> n2;
   cout << "Third number: ";
   cin >> n3;
   double sum = n1 + n2 + n3;
   cout << "Their sum is " << sum << endl;
   return 0;
}