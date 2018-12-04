#include<iostream>
#include<string>
using namespace std;
int list_length(int a[]){
  int i=0;
  while(a[i]!=0){
    i++;
  }
  return i;
}
void list_Print(int a[]){
  int i=0;
  while(a[i]!=0){
    cout<<i<<" "<<a[i]<<endl;
    i++;
  }
}
void list_remove_element(int a[],int checker,int search_value){
  if(checker){
    int i=0;
    while(a[i]!=search_value){
      i++;
    }
    while(a[i]!=0){
      a[i]=a[i+1];
      i++;
    }
  }else{
    int i=search_value-1;
    while(a[i]!=0){
      a[i]=a[i+1];
      i++;
    }
  }
}
void list_add_element(int a[],int checker,int search_value){
  if(checker){
    int i=0;
    while(a[i]!=search_value){
      i++;
      cout<<i<<" ";
    }
    int k = a[i];
    int p;
    cout<<"Jagsaaltad nemeh utgaa oruulnu: ";
    cin>>a[i];
    i++;
    while(a[i]!=0){
      p=a[i];
      a[i]=k;
      k=p;
      i++;
    }
    a[i]=p;
  }else{
    int i = search_value-1;
    int k = a[i];
    int p;
    cout<<"Jagsaaltad nemeh utgaa oruulnu: ";
    cin>>a[i];
    i++;
    while(a[i]!=0){
      p=a[i];
      a[i]=k;
      k=p;
      i++;
    }
    a[i]=p;
  }
}
int list_search(int a[],int checker,int search_value){
  int i=0,s=0;
  if(checker){
    while(a[i]!=0){
      if(a[i]==search_value){
        cout<<endl<<i<<"=dugaar bairlald oldov.";
        s++;
      }
      i++;
    }
    if(s==0){
      cout<<"Haisan element jagsaaltad baihgui bna.";
    }
  }else{
    while(a[i]!=0){
      if(i==search_value){
        cout<<endl<<i<<"- hayagan deer utga bna";
        break;
      }
      i++;
    }
  }
  return s;
}
int main(){
  int a[100]={10,2,5,3,7,8,9,5};
  int ch,search;
  std::string command;
  cout<<"Command aa oruulnuu: ";
  cin>>command;
  if(command.compare("print")==0){
    list_Print(a);
    cout<<"Niit element: "<<list_length(a)<<endl;
  }
  if(command.compare("add")==0){
    cout<<"Ta unen bol 1 hudal bol 0 gej haruilnuu!!!"<<endl;
    cout<<"Ta jagsaaltad ugaar in haij element nemeh uu? ";
    cin>>ch;
    if(ch){
      cout<<"Haih utgaa oruulnuu: ";
      cin>>search;
    }else{
      cout<<"Hayagaa oruulnuu: ";
      cin>>search;
    }
    list_add_element(a,ch,search);
    list_Print(a);
    cout<<"Niit element: "<<list_length(a)<<endl;
  }
  if(command.compare("remove")==0){
    cout<<"Ta unen bol 1 hudal bol 0 gej haruilnuu!!!"<<endl;
    cout<<"Ta jagsaaltad ugaar in haij element hasah uu? ";
    cin>>ch;
    if(ch){
      cout<<"Haih utgaa oruulnuu: ";
      cin>>search;
    }else{
      cout<<"Hayagaa oruulnuu: ";
      cin>>search;
    }
    list_remove_element(a,ch,search);
    list_Print(a);
    cout<<"Niit element: "<<list_length(a)<<endl;
  }
  if(command.compare("search")==0){
    cout<<"Ta unen bol 1 hudal bol 0 gej haruilnuu!!!"<<endl;
    cout<<"Ta jagsaaltad ugaar in haij elementeer haih uu?";
    cin>>ch;
    if(ch){
      cout<<"Haih utgaa oruulnuu: ";
      cin>>search;
    }else{
      cout<<"Hayagaa oruulnuu: ";
      cin>>search;
    }
    list_search(a,ch,search);
  }
  return 0;
}
