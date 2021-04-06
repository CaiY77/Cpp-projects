#include <iostream>
#include "SquareMatrix.h"

using namespace std;
int main () {

   SquareMatrix left;
   SquareMatrix right;
   left.resize(4);
   right.resize(4);
   left.at(1,1) = 5;
   right.at(1,1) = 5;
   right.at(1,2) = 7;

   SquareMatrix test = right + left;
   test.print(1,2);
   if(left == right){
      cout<<"yes";
   }else{
      cout<<"no";
   }
   
   // test.print(1,1);
   // left.print(1,1);
   // right.at(1,1) = 6;

   // left.at(9,9) = 7;
   // left.print(9,9);
   // right.at(9,9) = 3;
   // right.at(1,1) = 4;
   // right.print(1,1);

   // SquareMatrix sum = left + right;
   // sum.print(1,1);
   // sum.print(9,9);

   // cout << right.size()<< endl;
   // right.resize(20);
   // cout << right.size()<< endl;

   // SquareMatrix assign = left;
   // assign.print(1,1);

   // if(left == right) {
   //    cout << "yes";
   // } else {
   //    cout << "no";
   // }

   return 0;
}