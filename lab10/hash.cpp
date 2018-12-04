#include<iostream>
#include<string.h>
using namespace std;
int h(string x, int M) {
   int xlength = x.length();
   char ch[xlength+1];
   strcpy(ch,x.c_str());
   int i, sum;
   for (sum=0, i=0; i < x.length(); i++)
     sum += ch[i];
   return sum % M;
 }
int main(){
  string test[]={"apple","banana","rassberry","cherry","berry","orange","rassberry","rassberry"};
  int hash[29];
  for(int i=0;i<29;i++){
    hash[i]=-1;
  }
  int count;
  for(int i=0;i<8;i++){
    count = 0;
    while(hash[h(test[i],29)+count] != -1){
      count++;
    }
    hash[h(test[i],29)+count] = i;
  }
  cout<<test[hash[h("banana",29)]]<<endl;
  for(int i=0;i<29;i++){
    cout<<hash[i]<<" ";
  }
  cout<<endl;
}
