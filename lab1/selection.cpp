#include <iostream>
using namespace std;
int main(){
int n,a[100],i,j,k,s,m; // 2n+16 SC
// TC n*n;
cin>>n;
for(i=0;i<n;i++)
cin>>a[i];
i=0;
while(i<n){
	m = a[i];
	s=i;
	j=i+1;
	while(j<n){
		if(m>a[j]){
			s=j;
			m=a[j];
		}
		j++;
	}
	k = a[i];
	a[i] = a[s];
	a[s] = k;
	i++;
}

for(i=0;i<n;i++)
cout<<a[i]<<endl;
}


