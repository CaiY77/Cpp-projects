// Stable Marriage
#include <iostream>
#include <cstdlib>
#include <cmath>


using namespace std;

bool ok(int q[3], int c){

static int mp[3][3] = {{0,2,1},
                       {0,2,1},
                       {1,2,0}};
static int wp[3][3] = {{2,1,0},
                       {0,1,2},
                       {2,0,1}};
int nm = c;
int nw = q[c];


for(int i = 0; i < c; i++) {

  int cm = i;
  int cw = q[i];

  if (nw == cw) return false;

  if(( mp[cm][nw]<mp[cm][cw]) && ( wp[nw][cm] < wp[nw][nm] ))
        return false;

  if(( mp[nm][cw] < mp[nm][nw] ) && ( wp[cw][nm]<wp[cw][cm]))
        return false;

      } // end of loop

      return true;
}

void backtrack(int &col){
     col--;
     if(col==-1) exit(1);
   } // backtrack

void print(int q[])
     {
        cout << "Man" << "  " << "Woman" << endl;

        for( int i = 0; i < 3; i++){
           cout << " " << i << "     " << q[i] << endl;
        }
cout << endl;
     }

// MAIN TASK

int main () {

  int q[3];
  q[0]= 0;
  int c = 1;

  bool from_backtrack=false;

  while(true){
    while( c < 3 ) {
      if(!from_backtrack) q[c]=-1;

from_backtrack=false;

    while( q[c] < 3 ){
            q[c]++;

          while( q[c] == 3 ){
              backtrack(c);
              q[c]++;
            } // while on 4th column

if ( ok(q, c) ) break;

    } // while column less than 4

      c++; //next column

 } // while row is less than 4

 print(q);
 backtrack(c);
 from_backtrack=true;

  } // while (true) loop

}// Main
