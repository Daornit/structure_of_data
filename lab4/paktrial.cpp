#include<iostream>
using namespace std;
int fagtrial(int n){
  if(n==1){
    return 1;
  }
  return n * fagtrial(n-1);
}
int main(){
  int n = 10;
  cout<<fagtrial(n)<<endl;
}

