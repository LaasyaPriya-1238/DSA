#include<cstdio>
#define size 5
class queue
{
    private:
    int arr[size];
    int front;
    int rear;
    int current;

    public:
    queue()
    {
        current=0;
        front=-1;
        rear=-1;
    }
    int enqueue(int);
    int dequeue();
    void display();
    int peek();
};

int main()
{
    queue q1;
    int choose;
    int flag;
    do
    {
        printf("\n\nPlease select the operation to be performed from the following Menu: \n");
        printf("\nMenu:\n1 To Enqueue\n2 To Dequeue\n3 To Peek\n4 to Exit\n");
        scanf("%d",&choose);
        switch(choose)
        {
            case 1:
            int a;  // a is the element to be inserted into the Queue
            printf("Enter the elment to be inserted into the Queue: ");
            scanf("%d",&a);
            flag=q1.enqueue(a);
            if(flag==-1)
            {
                printf("The Queue is full and hence element cannot be inserted.\n");
            }
            else if(flag==1)
            {
                printf("%d is successfully inserted in the Queue.\n",a);
            }
            break;
            
            case 2:
            flag=q1.dequeue();
            if(flag==-1)
            {
                printf("The Queue is already empty and hence the element cannot be deleted.\n");
            }
            else
            {
                printf("The element %d is successfully deleted from the Queue.\n",flag);
            }
            break;

            case 3:
            flag=q1.peek();
            if(flag==-1)
            {
                printf("The Queue is Empty and hence the Top element cannot be displayed.\n");
            }
            else
            {
                printf("The top Element of the Queue is %d\n",flag);
            }
            break;

            case 4:
            printf("Exiting...");
            break;

            // case 5:
            // q1.display();

            default:
            printf("Please choose correct number from the Menu\n");
        }
    } while (choose!=4);   
 return 0;
}

//Function to Enqueue(insert) the element in int Queue
int queue :: enqueue(int key)
            {
                if(front==-1|| current ==0)
                {
                    front+=1;
                    arr[front]=key;
                    rear+=1;
                    current+=1;
                    return 1;
                }
                else if(current==5)
                {
                    return -1;
                }
                else
                {
                    rear+=1;
                    arr[rear]=key;
                    current+=1;
                    return 1;
                }
            }

//Function to Dequeue (Delete) the element from the Queue           
int queue :: dequeue()
            {
                if(front==-1 || current==0)
                {
                    return -1;
                }
                if (current ==0)
                {
                    front=rear=-1;
                }
                else
                {
                    int del_element=arr[front];
                    front=front+1;
                    current=current-1;
                    return del_element;
                }
            }

//Function to peek the topmost element of the Queue.            
int queue :: peek()
            {
                if(front==-1 || current ==0)
                {
                    return -1;
                }
                else
                {
                    int top_element=arr[front];
                    return top_element;
                }
            }


// void queue :: display()
//                {
//                  for(int i=front;i<=rear;i++)
//                   {
//                      printf("%d ",arr[i]);
//                   }
//                }