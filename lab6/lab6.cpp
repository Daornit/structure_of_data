#include <iostream>
#include <fstream>
using namespace std;

void mergeSort( char *a, const char *b, const char *result ){
  int x=1,y=1;
  ifstream file1,file2;
  ofstream res;
  file1.open(a);
  file2.open(b);
  res.open(result);

  file1 >> x;
  file2 >> y;
  while(!file1.eof() && !file2.eof()){
    if(y>x){
      res << x;
      res << " ";
      file1 >> x;
    }else{
      res << y;
      res << " ";
      file2 >> y;
    }
    cout<<" "<<x<<" "<<y<<endl;
  }
  if(file1.eof()){
    cout<<"x file duussan";
    while(!file2.eof()){
      res << y;
      res << " ";
      file2 >> y;
    }
  }
  if(file2.eof()){
    cout<<"y file duussan";
    while(!file1.eof()){
      res << x;
      res << " ";
      file2 >> x;
    }
  }
  file1.close();
  file2.close();
  res.close();
}
int main(){
  ifstream myfile;
  mergeSort((char*)"x.txt",(char*)"y.txt",(char*)"result.txt" );
}
