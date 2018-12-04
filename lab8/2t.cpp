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
    int k = head->next->next->value;
    head->next->value = 0;
    head->next=head->next->next;

    delete p;
    return k;
};
int top(stuck *head){
    return head->next->value;
}
int main(){
  int n;
  cin>>n;
  stuck *head = NULL;
  head = new stuck;
  if(head==NULL){
    return 1;
  }
  head->next = new stuck;
  head->next->value = 2;
  head->next->next = NULL;

  while(n!=0){
    push(head,n%2);
    n=n/2;
  }
  int k=0;
  while(k!=2){
    cout<<top(head);
    k = pop(head);
  }
  cout<<endl;
}
