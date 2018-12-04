#include<iostream>
using namespace std;
typedef struct queue{
  int value;
  struct queue *next;
} queue;

int length(queue *head){
  int i=0;
  queue *corrent = head->next;
  while(corrent!=NULL){
    cout<<corrent->value<<" ";
    corrent = corrent->next;
    i++;
  }
  cout<<endl;
  return i;
}
void enqueue(queue *head){
  queue *corrent = head->next;
  while(corrent->next!=NULL){
    corrent = corrent->next;
  }
  int n;
  cin>>n;
  corrent->next = new queue;
  corrent->next->value = n;
  corrent->next->next = NULL;
}
void dequeue(queue *head){
  queue *el = head->next;
  head->next->value = 0;
  head->next = head->next->next;
  delete el;
}
int main(){
  int len;
  queue *head = NULL;
  head = new queue;
  head->next = new queue;
  head->next->value=0;
  head->next->next=NULL;
  int n=0;
  while(n<10){
    enqueue(head);
    n++;
  }
  length(head);
  while(n){
    cout<<"Ta utga hasah uu ? unen 1 hudal 0"<<endl;
    cin>>n;
    if(n) {
      dequeue(head);
      len = length(head);
    }else break;

  }
  cout<<"Daraalaliin niit Urt: "<<len;
}
