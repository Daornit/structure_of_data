#include <iostream>
#include <limits.h>
#include <string.h>
using namespace std;

struct StackNode
{
    int data;
    struct StackNode* next;
};

struct StackNode* newNode(int data)
{
    struct StackNode* stackNode =
              (struct StackNode*) malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

int isEmpty(struct StackNode *root)
{
    return !root;
}

void push(struct StackNode** root, int data)
{
    struct StackNode* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
}

int pop(struct StackNode** root)
{
    if (isEmpty(*root))
        return INT_MIN;
    struct StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);

    return popped;
}

int top(struct StackNode* root)
{
    if (isEmpty(root))
        return INT_MIN;
    return root->data;
}

int main()
{
    struct StackNode* root = NULL;
    char postFix[100],bodoh[100];
    cin>>bodoh;
    int count = 0;
    for(int i = 0;i<strlen(bodoh);i++){
      switch (bodoh[i]) {
        //neeh haalt
        case '(' :
          if(!isEmpty(root)){
            if(top(root) == '*' || top(root) == '/'){
              while(!isEmpty(root)){
                postFix[count++] = pop(&root);
              }
            }
          }
          push(&root,(int)bodoh[i]);
          break;
        //haah haalt
        case ')' :
          while(!isEmpty(root)){
            if(top(root)!='(')
              postFix[count++] = pop(&root);
            else
              pop(&root);
          }
          break;
        // urjih
        case '*' :
          push(&root,(int)bodoh[i]);
          break;
        // huvaah
        case '/' :
          push(&root,(int)bodoh[i]);
          break;
        // nemeh
        case '-':
          if(!isEmpty(root)){
            if(top(root) == '*' || top(root) == '/'){
              while(!isEmpty(root)){
                postFix[count++] = pop(&root);
              }
            }
          }
          push(&root,(int)bodoh[i]);
          break;
        // hasah
        case '+':
          if(!isEmpty(root)){
            if(top(root) == '*' || top(root) == '/'){
              while(!isEmpty(root)){
                postFix[count++] = pop(&root);
              }
            }
          }
          push(&root,(int)bodoh[i]);
          break;
        default:
          postFix[count++] = bodoh[i];
          break;
      }
    }
    while(!isEmpty(root)){
      postFix[count++] = pop(&root);
    }
    for(int i=0;i<count;i++)
    cout<<postFix[i];
    cout<<endl;
    return 0;
}

// A+B*C+V-G+P/K
// +B*C+V-G+P/K    "" "A"
// B*C+V-G+P/K     "+" "A"
// *C+V-G+P/K      "+" "AB"
// C+V-G+P/K       "+*" "AB"
// +V-G+P/K        "+*" "ABC"
// V-G+P/K         "+" "ABC*+"
// -G+P/K          "+" "ABC*+V"
// G+P/K           "+-" "ABC*+V"
// +P/K            "+-" "ABC*+VG"
// P/K             "+-+" "ABC*VG"
// /K              "+-+" "ABC*VGP"
// K               "+-+/" "ABC*VGP"
//                 "ABC*VGPK/+-+"
