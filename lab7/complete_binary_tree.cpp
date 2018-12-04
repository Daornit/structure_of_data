#include<iostream>
using namespace std;
int root(int a[]){
  return a[0];
}
// Tuhain elementiin etsgiih in index iig butsaana.
int parent(int index){
  return (index-1)/2;
}
// Tuhain elementiin left childiin index iig butsaana.
int leftChild(int index){
  return index*2+1;
}
// Tuhain elementiin right childiin index iig butsaana.
int rightChild(int index){
  return index*2+2;
}
bool haveRightChild(int a[],int i){
  if(a[rightChild(i)])
    return true;
  return false;
}
bool haveLeftChild(int a[],int i){
  if(a[leftChild(i)])
    return true;
  return false;
}
bool haveParent(int a[],int i){
  if(a[parent(i)])
    return true;
  return false;
}
int level(int i){
  int j=0;
  do{
    i = parent(i);
    j++;
  }while(i!=0);
  return j;
}
int depth(int i){
  return level(i)-1;
}
void ancestors(int a[],int i){
  int tmp=i;
  while(i!=0){
    i=parent(i);
    cout<<"Ancestor of "<<tmp<<": "<<a[i]<<endl;
  }
}
//i = 0 oor avsan ued general tree bolno
void pre_order(int a[],int i,int& total){
  total++;
  cout<<a[i]<<" ";
  if(haveLeftChild(a,i)){
    pre_order(a,leftChild(i),total);
  }
  if(haveRightChild(a,i)){
    pre_order(a,rightChild(i),total);
  }
}
void descestors(int a[], int i,int& total){

  cout<<"Descestors of "<<i<<": ";
  pre_order(a,i,total);
  cout<<endl;
}
int leaf(int a[],int last_element_index){
  int total_of_leaf = last_element_index - parent(last_element_index);
  return total_of_leaf;
}
int subtree(int a[],int last_element_index){
  return last_element_index-leaf(a,last_element_index);
}
void sibling(int a[],int i){
    int tmp = i;
    i=parent(i);
    if(haveLeftChild(a,i)){
      cout<<"Sibling: "<<a[leftChild(i)]<<endl;
    }
    if(haveRightChild(a,i)){
      cout<<"Sibling: "<<a[rightChild(i)]<<endl;
    }
}

void balance(int a[]){
  int left,right;
  descestors(a,1,left);
  descestors(a,2,right);
  cout<<"Zuun taliin elementiin too: "<<left<<endl;
  cout<<"Baruun taliin elementiin too: "<<right<<endl;
}

void in_order(int a[],int i){
  if(!a[i])
    return;
  in_order(a, leftChild(i));
  cout<<a[i]<<" " ;
  in_order(a, rightChild(i));
}

void post_order(int a[],int i){
  if(!a[i])
    return;
  post_order(a, leftChild(i));
  post_order(a, rightChild(i));
  cout<<a[i]<<" " ;

}
void pre_order(int a[],int i){
  if(!a[i])
    return;

  cout<<a[i]<<" " ;
  pre_order(a, leftChild(i));
  pre_order(a, rightChild(i));
}

int main(){
  int a[100]={100,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
  int i=0;
  while(haveLeftChild(a,i)){
    i = leftChild(i);
  }
  cout<<a[i]<<endl;
  pre_order(a,0);
  cout<<endl;
  in_order(a,0);
  cout<<endl;
  post_order(a,0);
  cout<<endl;
  // balance(a);
  // // int p=0,k=0;
  // // cout<<"Root: "<<root(a)<<endl;
  // // cout<<"leftChild: "<<rightChild(9)<<endl;
  // // cout<<"leftChild: "<<haveRightChild(a,9)<<endl;
  // // cout<<"leftChild: "<<haveLeftChild(a,9)<<endl;
  // // cout<<"node 19 of level: "<<level(0)<<endl;
  // // cout<<"node 19 of depth: "<<depth(0)<<endl;
  // // ancestors(a,19);
  // // cout<<"Pre_ordered complete binary tree: ";
  // // pre_order(a,0,p);
  // // cout<<endl;
  // // descestors(a,4,k);
  // // cout<<"Total of leaf: "<<leaf(a,20)<<endl;
  // // cout<<"Total of subtree: "<<subtree(a,20)<<endl;
  // // sibling(a,4);
  // // cout<<"Total of elements: "<<p<<endl;

}
