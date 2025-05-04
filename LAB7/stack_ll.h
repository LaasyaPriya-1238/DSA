#ifndef STACK_LL_H
#define STACK_LL_H
#include<cstdio>
#include<cstdlib>
class stack{
  private :
  struct node{
    char data;
    struct node* next;
  }*head;
  public :
  stack(){head = NULL;}
  void push(char ch);
  char pop();
  char peek();
  bool isempty();
  void display();
};
void stack :: push(char ch){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = ch;
    if(head == NULL){
        head = newnode;
        newnode->next = NULL;
        return;
    }
    newnode->next = head;
    head = newnode;
    return;
}
char stack :: pop(){
    if(head == NULL){
        return '\0';
    }
    char s = head->data;
    struct node*temp = head;
    head = head->next;
    free(temp);
    return s;
}
char stack :: peek(){
    if(head == NULL){
        return '\0';
    }
    return head->data;
}
bool stack :: isempty(){
    return head == NULL;
}
void stack :: display(){
    if(head == NULL){
        printf("STACK UNDERFLOW \n");
        return;
    }
    struct node *temp = head;
    while(temp->next != NULL){
        printf("%c -> ",temp->data);
        temp = temp->next;
    }
    printf("%c\n",temp->data);
    return;
}
#endif