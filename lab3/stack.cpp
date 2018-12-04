#include<iostream>
using namespace std;
typedef struct stuck{
  int value;
  struct stuck *next;
} stuck;


void push(stuck *head, int val) {
    stuck * new_stuck;
    new_stuck = new stuck;
    new_stuck->value = val;
    new_stuck->next = head->next;
    head->next = new_stuck;
}
int pop(stuck *head){
    stuck *p = head->next;
    int k = head->next->value;
    head->next->value = 0;
    head->next=head->next->next;

    delete p;
    return k;
};
int top(stuck *head){
    return head->next->value;
}
int main(){
  stuck *head = NULL;
  head = new stuck;
  if(head==NULL){
    return 1;
  }
  head->next = new stuck;
  head->next->value = 2;
  head->next->next = NULL;
push(head,1);
push(head,3);
  // int a;
  // cin>>a;
  // while(a){
  //   push(head,a);
  //   cin>>a;
  // }
  cout<<pop(head)<<endl;
  cout<<pop(head)<<endl;
  push(head,4);

  push(head,9);
  push(head,100);
  cout<<pop(head)<<endl;
  cout<<"top command "<< top(head);
  cout<<endl;
}
