//Eight Number in a Cross
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

void backtrack(int &col){
    col--;
    if (col == -1) {
        exit(1);
    }
}


void print ( int cross[]){
  cout << "  " << cross[0] << " " << cross[1] << endl;
  cout << cross[2] << " " << cross[3] << " " << cross[4] << " " << cross[5] << endl;
  cout << "  " << cross[6] << " " << cross[7] << endl;
  cout << "-------" << endl;
}

bool ok(int adj_table[8], int box, int adj_value) {
    for(int i=0; i<box; i++) {

        if ( adj_table[i] == adj_table[box] ) return false;
        if ( ( abs(adj_table[box] - adj_table[adj_value] ) == 1)) return false;

    }
    return true;
}


int main() {
    int cross[8]={0}, box = 0;
    int adj_table[8][5] =  {
      {-1},
      {0, -1},
      {0, 1, -1},
      {0, 2, -1},
      {1, 2, -1},
      {1, 2, 3, 4, -1},
      {2, 3, 5, -1},
      {4, 5, 6, -1}
    };

  while(true){

      while(box<8) {
          cross[box]++;

          if (cross[box]>8) {
              cross[box]=0;
              backtrack(box);
              continue;
          }

for(int i=0; i<5; i++) {
    if(adj_table[box][i]==-1){//check if number is fine
        box++;
        if(box==8) {//found solution
            print(cross);
            backtrack(box);
        }
        break;
    }

              if( !ok(cross , box , adj_table[box][i]) ) break;

          }//for

      }//while(box<8)

  }//while(true)


}//main
