#include<cstdio>
#include<cstdlib>
class queue
{
private:
int size; //Size is the number of Elements in the List.
struct node
{
int data;
struct node* next;
}*head,*tail;
public:
queue()
{
head=NULL;
tail=NULL;
size=0;
}
int enqueue(int);
int dequeue();
int peek();
//void display();
};
int main()
{
queue q1;
int choose;
int flag;
do
{
printf("\nMenu:\n1 To Enqueue\n2 To Dequeue\n3 To Peek\n4 To Exit\n");
printf("\nChoose a number from the above Menu to perform respective operation on the Queue.\n");
scanf("%d",&choose);

switch(choose)
{
case 1:
int a; // a is the element user wanted to insert in the Queue.
printf("Enter the Element to be inserted into the Queue: ");
scanf("%d",&a);
flag=q1.enqueue(a);
if(flag==1)
{
printf("The element %d is successfully inserted in the Queue.\n",a);
}
break;

case 2:
flag=q1.dequeue();
if(flag==-1)
{
printf("The Queue is empty and hence the element cannot be removed from the Queue.\n");
}
else
{
printf("The element dequeued from the Queue is %d.\n",flag);
}
break;

case 3:
flag=q1.peek();
if(flag==-1)
{
printf("The Queue is empty and hence the element top element cannot be shown.\n");
}
else
{
printf("The element on the top of the Queue is %d.\n",flag);
}
break;

case 4:
printf("Exiting...\n");
break;

// case 5:
// printf("The Queue is: ");
// q1.display();
// printf("\n");
// break;

default:
printf("Please choose a correct number from the Menu.\n");
}
}while(choose!=4);
return 0;
}

//Function to Enqueue(insert) an element in the Queue.
int queue :: enqueue(int key)
{
if(head==NULL||size==0)
{
struct node* newnode=(node*)malloc(1*sizeof(struct node));
newnode->data=key;
newnode->next=NULL;
head=newnode;
tail=newnode;
size++;
return 1;
}
else
{
struct node* newnode=(node*)malloc(1*sizeof(struct node));
newnode->data=key;
newnode->next=NULL;
tail->next=newnode;
tail=newnode;
size++;
return 1;
}
}

//Function to Dequeue(delete) an Element in the Queue.
int queue :: dequeue()
{
if(head==NULL || size==0)
{
return -1;
}
struct node* temp=head;
int dequeued_element=head->data;
head=head->next;
free(temp);
size--;
return dequeued_element;
}

//Function to Peek the topmost Element of the Queue.
int queue :: peek()
{
if(head==NULL || size==0)
{
return -1;
}
else
{
int top_element;
top_element=head->data;
return top_element;
}
}

//Function to Display Queue
// void queue :: display()
// {
// if(head==NULL)
// {
// printf("The Queue is empty and hence cannot be displayed\n");
// }
// else
// {
// struct node* temp=head;
// while(temp!=NULL)
// {
// printf("%d ",temp->data);
// temp=temp->next;
// }
// }
// }