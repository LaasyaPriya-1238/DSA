//Menu driven program of implementing a stack using Linked List.
#include<cstdio>
#include<cstdlib>
class stack
{
    private:
    struct node
    {
        char data;
        node* next;
    }*top;

    public:
    stack()
    {
        top=NULL;
    }
    void push(char);
    char pop();
    char peek();
}; 

int main()
{
    stack st;
    int choose;
    do
    {
        //MENU to perform respective operation in the stack.
        printf("\nChoose an operation to be performed in Stack from the following Menu:\n");
        printf("1 To PUSH an Element into the Stack\n2 To POP an Element from the stack\n3 To PEEK the top Element of the Stack\n4 To Exit\n");
        scanf("%d",&choose);

        switch(choose)
        {
            case 1:
            //ch is the character that user wants to push/insert into the stack.
            char ch;
            printf("Enter a Character to be pushed into the Stack: ");
            scanf(" %c",&ch);
            st.push(ch);
            printf("The Element %c is successfully Pushed into the Stack.\n",ch);
            break;

            case 2:
            char pop_ch;
            pop_ch=st.pop();
            if(pop_ch==-1)
            {
                printf("The Stack is Empty and hence the element cannot be Popped out\n");
            }
            else{
                printf("The Element popped from the Stack is %c\n",pop_ch);
            }
            break;

            case 3:
            //c is the top character of he Stack.
            char c;
            c=st.peek();
            if(c==-1)
            {
                printf("The Stack is Empty\n");
            }
            else{
                printf("The topmost Element of the Stack is %c\n",c);
            }
            break;

            case 4:
            printf("Exiting...\n");
            break;

            default:
            printf("Invalid choice. Please Try Again\n");
        }
    }while(choose!=4);
    return 0;
}

//Function to Push a Character into the Stack.
void stack :: push(char ch)
                {
                    struct node* newnode=(struct node*)malloc(1*sizeof(node*));    
                    newnode->data=ch; 
                    if(top==NULL)
                    {
                        newnode->next=NULL;
                        top=newnode;
                    }
                    else
                    {
                        newnode->next=top;
                        top=newnode;
                    }
                    return;
                }

//Function to Pop the top Element from the stack.
char stack :: pop()
                {
                    if(top==NULL)
                    {
                        return -1;
                    }
                    struct node* temp=(node*)malloc(1*sizeof(node*));
                    temp=top;
                    char popped_element=temp->data;
                    top=top->next;
                    free(temp);
                    return popped_element;
                }

//Function to Peek the top Element of the Stack.
char stack :: peek()
                {
                    if(top==NULL)
                    {
                        return -1;
                    }
                    return top->data;
                }   
                             