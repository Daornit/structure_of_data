#include<iostream>
using namespace std;
void quicksort(int *p,int si,int ei){
  int n = ei-si;
  int i=0, *m=p+n-1, tmp, chiglel=0, counterOfLeft=0, counterOfRight=0;
  while(m!=p){
    // baruun talaas hailt
    if(chiglel%2==0){
      if(*p>*m){
        tmp = *p;
        *p = *m;
        *m = tmp;
        p++;       
        chiglel++;
        counterOfLeft++;
      }else{
        m--;
        counterOfRight++;
      }
    }
    // zuun talaasaa hailt
    else{
      if(*p>*m){
        tmp = *m;
        *m = *p;
        *p = tmp;
        m--;
        chiglel++;
        counterOfRight++;
      }else{
        p++;
        counterOfLeft++;
      }
    }
  }
  if(counterOfLeft!=0){
    quicksort(p-counterOfLeft,0,counterOfLeft);
  }
  if(counterOfRight!=0){
    quicksort(p+1,0,counterOfRight);
  }
}
int main(){
  int a[100],i=0;
  while(1){
    cin>>a[i];
    if(a[i]==0)
      break;
    i++;
  }
  quicksort(a,0,i);
  for(int j=0;j<i;j++){
    cout<<a[j]<<" ";
  }
  cout<<endl;
}
