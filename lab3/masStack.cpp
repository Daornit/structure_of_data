#include<iostream>
using namespace std;
int pop(int* a,int& i){
  *(a+i)=0;
  return i-1;
}
void push(int* a,int& i){
  int n;
  cin>>n;
  i++;
  *(a+i)=n;
}
int top(int* a,int& i){
  return *(a+i);
}
int main(){
  int a[100],i=0;
  while(1){
    cin>>a[i];
    if(a[i]==0)
      break;
    i++;
  }

  i = pop(a,i);
  for(int j=0;j<i+1;j++)
    cout<<a[j]<<" ";
  i = pop(a,i);
  cout<<endl;
  for(int j=0;j<i+1;j++)
    cout<<a[j]<<" ";
  cout<<endl;

  push(a,i);
  for(int j=0;j<i+1;j++)
    cout<<a[j]<<" ";
  cout<<endl;

  cout<<top(a,i)<<endl;

}
