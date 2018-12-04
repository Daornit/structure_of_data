#include<iostream>
using namespace std;
typedef struct list{
  int value;
  struct list *next;;
} list;

void print_list(list *head) {
    list *current = head->next;

    while (current != NULL) {
        printf("%d\t", current->value);
        current = current->next;
    }
}

void push(list *head, int val) {
    list *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new list;
    current->next->value = val;
    current->next->next = NULL;
}

void pushFirstElement(list *head, int val) {
    list * new_list;
    new_list = new list;
    new_list->value = val;
    new_list->next = head->next;
    head->next = new_list;
}
int main(){
  list *head = NULL;
  head = new list;
  if(head==NULL){
    return 1;
  }
  head->next = new list;
  head->next->value = 2;
  head->next->next = NULL;

  int a;
  cin>>a;
  while(a){
    push(head,a);
    cin>>a;
  }
  print_list(head);
  cout<<endl;
  cin>>a;
  pushFirstElement(head,a);
  print_list(head);
  cout<<endl;
}
