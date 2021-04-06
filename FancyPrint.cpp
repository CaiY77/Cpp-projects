// Fancy Print

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

void PrintBoard(int q[]){

int i,j,k,l;
typedef char box[5][7];
box bb,wb,bbq,wbq,*board[8][8];

//change 1-D array into 2-D array
int a[8][8]={0};
for(int i=0;i<8;i++){
a[q[i]][i] = 1;
}


// making black and white boxes (bb & wb)
// making Black Box with Queen (bbq)
// making White Box with Queen (wbq)

for(i=0;i<5;i++)
for( j=0;j<7;j++){
wb[i][j]=' ';
bb[i][j]=char(219);

if ((i == 1) && (j%2==1)) {wbq[i][j] = char(219);}
else if ((i == 2) && (0<j && j<6)) {wbq[i][j] = char(219);}
else if ((i == 3) && (0<j && j<6)) {wbq[i][j] = char(219);}
else wbq[i][j] = ' ';

if ((i == 1) && (j%2==1)) {bbq[i][j] = ' ';}
else if ((i == 2) && (0<j && j<6)) {bbq[i][j] = ' ';}
else if ((i == 3) && (0<j && j<6)) {bbq[i][j] = ' ';}
else bbq[i][j] = char (219);

}
//fill board bb and wb while alternating
for(i=0;i<8;i++){
  for(j=0;j<8;j++){
      if((i+j)%2==0) board[i][j]=&wb;
      else if((i+j)%2!=0) board[i][j]=&bb;

    }
}
// change if depending if array has 1 or 0
for(i=0;i<8;i++){
  for(j=0;j<8;j++){
 if (((i+j)%2==0) && (a[i][j]==1)) board[i][j] = &wbq;
 if(((i+j)%2!=0) && (a[i][j]==1)) board[i][j] = &bbq;
}
}

// print boardering and board

cout<<" ";
for(i=0;i<7*8;i++)
cout<<'_';
cout<<endl;



for(i=0;i<8;i++)
for(k=0;k<5;k++){
cout<<" "<<char(179);
for(j=0;j<8;j++)
for(l=0;l<7;l++)
cout<<(*board[i][j])[k][l];
cout<<char(179)<<endl;
}

cout<<" ";
for(i=0;i<7*8;i++)
cout<<char(196);
cout<<endl;
}


// ok function

bool ok(int q[], int col){
	for (int i = 0; i < col; ++i)
if (q[i] == q[col] || (col-i) == abs(q[col]-q[i])){return false;}
return true;
};

// backtrack

void backtrack(int &col){
--col;
if (col == -1)
{exit(1);}
}


// MAIN TASK

int main () {

// 1-D backtrack with while loop

  int q[8]; q[0]=0;
  int col=0;
  bool from_backtrack=false;
  	while(true){
  	while(col<8){
  	if(!from_backtrack) {
  	col++;
  	if(col==8) break;
  	q[col] = -1;
  	}
  	from_backtrack=false;
  	while(q[col]<8){
  	q[col]++;
  	if (q[col]==8){backtrack(col);
  	from_backtrack=true;}
  	if(ok(q,col)) break;
  	}
  	}
  	PrintBoard(q);
  	backtrack(col);
  	from_backtrack=true;
  	}
}
