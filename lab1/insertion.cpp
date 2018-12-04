#include <iostream>
using namespace std;
int main(){
int i,j,k,a[100],n;
cout<<"Erembleh massiviin hemjee: ";
cin>>n;
cout<<"Erembleh massiviin element buriig 1 1 eer in oruulnuu: ";
for(i=0;i<n;i++)
cin>>a[i];
i=1;
while(i<n){
	k=a[i];
	// eremblegsen taliin suuliin element
	j=i-1;
	// shift uildel
	while(k<a[j] && j>=0){
		a[j+1]=a[j];
		j--;
	}
	// tohiroh bairand in bairluulsan
	a[j+1]=k;
	i++;
}
for(i=0;i<n;i++)
cout<<a[i]<<' ';
cout<<endl;
}
