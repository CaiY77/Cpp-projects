// shortest path
#include<iostream>
using namespace std;
const int rows = 5;
const int cols = 6;
int cost(int i, int j){ // i is the row, j is the column
 int weight[rows][cols]={
 {3,4,1,2,8,6},
 {6,1,8,2,7,4},
 {5,9,3,9,9,5},
 {8,4,1,3,2,6},
 {3,7,2,8,6,4}};

 //base case
 if(j==0)
 return weight[i][0];

 // recursive call
 int left = cost( i , j-1 );
 int up = cost( (i - 1 + rows ) % rows , j-1 );
 int down = cost( (i + 1) % rows, j-1);

 // find the value of the shortest path through cell (i,j)
 int min = weight[i][j] + left; // set initial min as the left

if (weight[i][j] + up < min){ // check if up is smaller than min
  min = weight[i][j] + up;
}
if (weight[i][j] + down < min){ // chceck if down is smaller than min
  min = weight[i][j] + down;
}

 return min;
 }





int main(){
 int ex[rows];

 // get the shortest path out of each cell on the right
 for( int i=0; i<rows; i++)
 ex[i]=cost(i,cols-1);

 // now find the smallest of them
int min = ex[0]; // set initial shorest path as first path
int path = 0;
// cycle through all paths to see if there is a shorter path than the inital
for( int i=0; i<rows; i++){
  if (ex[i] < min){
    min = ex[i];
    path = i;
  }
}


 cout <<"The sortest path is path number: "<< path << endl;
 cout <<"The length of this path is: "<< min <<endl;
return 0;

}
