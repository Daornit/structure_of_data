#include<iostream>
using namespace std;
int hieh(int n,int m){
  while (m!=0 && n!=0)
    { if(n>m) n=n-m;
    else m=m-n;
    }
  return n+m;
}

int main(){
  int a,b,s=0;
  cin>>a>>b;
  for(a;a<b;a++){
      if(hieh() == 1){
        s++;
    }
  }
  cout<<s<<endl;
  return 0;
}
