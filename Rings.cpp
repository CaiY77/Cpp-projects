#include<iostream>
#include <cstdlib>
#include<vector>

using namespace std;
int main(){

          vector<int> t[3];
          int n, candidate,to, from, move=0;
          cout<<"Please enter ODD number of rings: ";
          cin>>n;
          cout<<endl;

          for(int i = n+1;i >=1;i--)
          t[0].push_back(i);
          t[1].push_back(n+1);
          t[2].push_back(n+1);

          from=0;
          to=1;
          candidate=1;



         while( t[1].size() !=n+1) {
           move++;
    cout<<"Step "<<move<<": Move ring "<<candidate<<" from "<<  char(from+65)<<" to "<<char(to+65)<<endl;

                      t[from].pop_back();
                      t[to].push_back(candidate);

                      int a,b , c[5]={2,0,1,2,0};

                      for(int i=1;i<4;i++)
                      {  if(to==c[i])
                           {  a= c[i-1];
                              b= c[i+1];
                           }
                      }

                      if(t[a].back() < t[b].back() )
                          from = a;
                      else
                          from = b;

                    for(int i=1;i<4;i++)
                      {  if(n%2!=0){
                            if(from==c[i])
                            {    if(t[from].back() < t[c[i+1]].back()  )
                                 to=c[i+1]   ;
                              else
                                 to= c[i-1]   ;

                            }
                          }// (n%2!=0)
                           else {

                           if(from==c[i])
                           {  if(t[from].back() < t[c[i-1]].back()  )
                                 to=c[i-1]   ;
                              else
                                 to= c[i+1]   ;

                            }
                         }//else
                      }//for loop


                  candidate= t[from].back() ;
              } //while loop
          return 0;
}
