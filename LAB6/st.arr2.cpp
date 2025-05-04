//Menu driven program of implementing a stack using an array.
#include<cstdio>
#define size 5
class stack
{
    private:
    char arr[size];
    int top;

    public:
    stack()
    {
        top=-1;
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

//Function to Push an Element into the Stack.
void stack :: push(char ch)
                {
                   if(top==size-1)
                   {
                    printf("The Stack is overflowed.\n");
                   } 
                   else
                   {
                    top=top+1;
                    arr[top]=ch;
                    printf("The Character %c is Successfully pushed into the Stack\n",ch);
                   }
                   return;
                }

//Function to POP out the Element from the Stack.
char  stack ::  pop()
                {
                    if(top==-1)
                    {
                        return -1;
                    }
                    else
                    {
                        char ch=arr[top];
                        top=top-1;
                        return ch;
                    }
                }  

//Function to peek the top most element of the Stack.
char stack :: peek()
                {
                    if(top==-1)
                    {
                        return -1;
                    }
                    else
                    {
                        return arr[top];
                    }
                }
                