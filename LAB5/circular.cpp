#include<cstdio>
#include<cstdlib>
class list
{
    private:
    struct node
    {
        int data;
        struct node* next;
    }*head;

    public:
   list()
   {
    head=NULL;
   } 
   int insert_beginning(int);
    int insert_end(int);
    int insert_position(int,int);
    int delete_beginning();
    int delete_end();
    int delete_position(int);
    void display();
    int search(int);
};
int main()
{
    list l;
    int flag;
    //Writing menu of the operations to be performed in the Doubly Linked List
    int choose;
    do
    {
    printf("\nChoose the operation to be performed from the following Menu: \n");
    printf("1 To Insert at Beginning\n2 To Insert at the End\n3 To Insert at Position\n4 To Delete at Beginning\n5 To Delete at the End\n6 To Delete at Position\n7 To Search\n8 To Display\n9 To Exit\n");
    scanf("%d",&choose);
    switch (choose)
        {
            case 1:
            //a is the Element to be inserted at the beginning
            int a;
            printf("Enter the element to be inserted at the beginning of the list:\n");
            scanf("%d",&a);
            flag=l.insert_beginning(a);
            if(flag==1)
            {
                printf("%d is succesfully added at the beginning of the List\n",a);
            }
            break;

            case 2:
            //b is the element to insert at the End of the List
            int b;
            printf("Enter the element to be inserted at the End of the List: ");
            scanf("%d",&b);
            flag=l.insert_end(b);
            if(flag==-1)
            {
                flag=l.insert_beginning(b);
                if(flag==1)
                printf("%d is Successfully added at the End of the List\n",b);
            }
            else if(flag==1)
            {
                printf("%d is Successfully added at the End of the List\n",b);
            }
            break;
            
            case 3:
            //Position is the position where user wants to insert the Element
            //c is the element to be inserted at th eposition x
            int position;
            int c;
            printf("Enter the position where you want to insert the element: ");
            scanf("%d",&position);
            printf("Enter the element to be inserted at the %d position: ",position);
            scanf("%d",&c);
            if(position==1)
            {
                flag=l.insert_beginning(c);
                if(flag==1)
                {
                    printf("%d is successfully inserted at the %d position of the list\n",c,position);
                }
            }
            else
            {
                flag=l.insert_position(c,position);
                if(flag==1)
                {
                    printf("%d is successfully inserted at the %d position of the list\n",c,position);
                }
            }
            break;

            case 4:
            flag=l.delete_beginning();
            if(flag==-1)
            {
                printf("The list is already empty, and hence cannot be deleted\n");
            }
            else{
                printf("%d is successfully deleted at the beginning of the list\n",flag);
            }
            break;

            case 5:
            flag=l.delete_end();
            if(flag==-1)
            {
                printf("The list is already empty, and hence cannot be deleted\n");
            }
            else{
                printf("%d is successfully deleted at the end of the list\n",flag);
            }
            break;

            case 6:
            int del_position;
            printf("Enter the position where you want to delete the element: ");
            scanf("%d",&del_position);
            if(position==1)
            {
                flag=l.delete_beginning();
                if(flag==-1)
                {
                printf("The list is already empty, and hence cannot be deleted\n");
                }
                else
                {
                    printf("%d is successfully deleted at the beginning of the list\n",flag);
                }
            }
            else
            {
                flag=l.delete_position(del_position);
                if(flag==-1)
                {
                    printf("The list is already empty, and hence cannot be deleted\n");
                }
                else{
                    printf("%d is successfully deleted at the %x position of the list\n",flag,del_position);
                }
            }
            break;

            case 7:
            int search;
            printf("Enter the element you want to search in the list: ");
            scanf("%d",&search);
            flag=l.search(search);
            if(flag==-1)
            {
                printf("Element %d is not found in the list\n",search);
            }
            else
            {printf("The Element %d is found at %d position of the List\n",search,flag);}
            break;

            case 8:
            l.display();
            printf("\n");
            break;

            case 9:
            printf("Exiting...\n");
            break;

            default:
            printf("Please enter valid number from the Menu\n");
        }     
    } while (choose!=9);
    
    return 0;
}

//Function to Insert the element at the Beginning of the list
int list :: insert_beginning(int key)
            {
                struct node* newnode=(node*)malloc(1*sizeof(node));
                newnode->data=key;
                if(head==NULL)
                {
                    head=newnode;
                    newnode->next=head;
                }
                else
                {
                    newnode->next=head;
                    struct node* temp=head->next;
                    while(temp!=head)
                    {
                        temp=temp->next;
                    }
                    temp->next->next=newnode;
                    head=newnode;
                }
                return 1;
            }

//Function to Insert the element at the End of the List
int list :: insert_end(int key)  
            {
                struct node* newnode=(node*)malloc(1*sizeof(node));
                newnode->data=key;
                struct node* temp=head->next;
                while(temp->next!=head)
                {
                    temp=temp->next;
                }
                temp->next=newnode;
                newnode->next=head;
                return 1;
            }

//Function to Insert the element at the Position x of the List
int list :: insert_position(int key,int position)
            {
                struct node* newnode=(node*)malloc(1*sizeof(struct node));
                newnode->data=key;
                struct node*temp=head;
                for(int i=1;i<position-1;i++)
                {
                    temp=temp->next;
                }
                if(temp->next==head)
                {
                    insert_end(key);
                    return 1;
                }
                else
                {
                    newnode->next=temp->next;
                    temp->next=newnode;
                }
                return 1;
            }

//Function to Delete the element at the Beginning of the List
int list :: delete_beginning()
            {
                if(head==NULL)
                {
                    return -1;
                }
                else
                {
                    struct node* temp=head;
                    int deleted_element=temp->data;
                    struct node*temp2=temp->next;
                    while(temp2->next!=head)
                    {
                        temp2=temp2->next;
                    } 
                    temp2->next=head->next;
                    head=head->next;
                    free(temp);
                    return deleted_element;
                }
            }

//Function to Delete the Element at the End of the List
int list :: delete_end()
            {
                if(head==NULL)
                {
                    return -1;
                }
                else
                {
                struct node* temp=head->next;
                while(temp->next->next!=head)
                {
                    temp=temp->next;
                }
                int deleted_element=temp->next->data;
                free(temp->next);
                temp->next=head;
                return deleted_element;
                }
            }
//Function to Delete the element at the Position x of the List
int list :: delete_position(int position)
            {
                struct node*temp=head;
                for(int i=1;i<position-1;i++)
                {
                    temp=temp->next;
                }
                if(temp->next==head)
                {
                    int deleted_element=delete_end();
                    return deleted_element;
                }
                else
                {
                    struct node* del_node=temp->next;
                    int deleted_element=temp->next->data;
                    temp->next=temp->next->next;
                    free(del_node);
                    return deleted_element;
                }
            }
//Function to Search an Element in the List
int list :: search(int search)
            {
                struct node* temp=head;
                int i=1;
                do
                {
                  if(temp->data==search)
                  {
                    return i;
                  }
                  i++;
                  temp=temp->next;  
                } while (temp!=head);
                return -1;
            }            
//Function to Display the List
void list ::  display()
            {
                if(head==NULL)
                {
                    printf("The list is empty and hence cannot be displayed\n");
                }
                struct node* temp;
                temp=head;
                printf("The list is ");
               do
                {
                    printf("%d ",temp->data);
                    temp=temp->next;
                }while(temp!=head);
            }

