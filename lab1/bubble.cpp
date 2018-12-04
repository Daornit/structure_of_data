#include<iostream>
using namespace std;
int main(){
int i,n,a[100],m,l;
cin>>n;
l=n;
for(i=0;i<n;i++)
cin>>a[i];
while(0<n){
	i=1;
	while(i<n){
		if(a[i]<a[i-1]){
			m=a[i-1];
			a[i-1]=a[i];
			a[i]=m;
		}		
		i++;
	}
	n--;	
}
cout<<endl;
for(i=0;i<l;i++)
cout<<a[i]<<' ';
cout<<endl;
}
