#include<iostream>
using namespace std;
void enqueue(int *p,int n,int v){
  while(*p){ //1 2 3 4 5 0
    p=p+1;
  }
  int n;
  cin>>n;
  *p=n;
}
void dequeue(int *p){
  do{
    *p = *(p+1);
    p=p+1;
  }while(*p);
}
int length(int *a){
  int i=0;
  while(*a){
    i++;
    a=a+1;
  }
  return i;
}
int main(){
  int a[100],i=0;
  while(1){
    cin>>a[i];
    if(a[i]==0)
      break;
    i++;
  }
  enqueue(a);
  dequeue(a);
  dequeue(a);
  int j=0;
  while(a[j]!=0)
    cout<<a[j++]<<" ";
  cout<<endl<<"NIIT QUIUI-iin URT: "<<length(a)<<endl;
}
