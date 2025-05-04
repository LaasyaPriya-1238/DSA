#include<cstdio>
#include<cstdlib>
class list
{
	private:
    	struct node
    	{
        	int data;
        	node* next;
    	};
	public:
    	struct node* head=NULL;
    	int insert_beginning(int);
    	int insert_end(int);
    	int insert_position(int,int);
    	int delete_beginning();
    	int delete_end();
    	int delete_position(int);
        int search(int);
        void display_reverse();
        void reverse_list();
    	void display();
};
int main()
{   
	list l1;
	int flag;
	//Writing Menu of the operations
	int choose;
	do
	{
    	printf("\nChoose any number from the following menu for the operation to be performed:\n");
    	printf("\n1 To Insert at the Beginning\n2 To Insert at the End\n3 To Insert at Position\n4 to Delete at the Beginning\n5 To Delete at the End\n6 To Delete at Position\n7 To Search\n8 To Display the List\n9 To Display Reverse List\n10 To Reverse the List\n11 To Exit\n");
    	scanf("%d",&choose);
    	switch(choose)
    	{
        	case 1:
        	//a is he element which user wanted to insert at the beginning of the list
        	int a;
        	printf("Enter a number to insert it at the beginning of the list: ");
        	scanf("%d",&a);
        	flag=l1.insert_beginning(a);
        	if(flag==1)
        	{
            	printf("%d is Successfully inserted at the Begnning of the List\n\n",a);
        	}
        	break;

        	case 2:
        	//b is he element which user wanted to insert at the beginning of the list
        	int b;
        	printf("Enter a number to insert it at the end of the list: ");
        	scanf("%d",&b);
        	flag=l1.insert_end(b);
        	if(flag==0)
        	{
            	flag=l1.insert_beginning(b);
            	if(flag==1)
            	{
                	printf("%d is Successfully inserted at the End of the List\n\n",b);
            	}
        	}
        	else if(flag==1)
        	{
            	printf("%d is Successfully inserted at the End of the List\n\n",b);
        	}
        	break;

        	case 3:
        	int c;
        	//c is the element user wanted to insert at the position x of the list
        	int position;
        	printf("Enter the position where you wanted to enter the element: ");
        	scanf("%d",&position);
        	if(position<=0)
            	{
                	printf("Enter valid position\n");
            	}
        	else if(position==1)
            	{
                	flag=l1.insert_beginning(c);
                	if(flag==1)
                	{
                    	printf("%d is Successfully inserted at the position 1 of the List\n\n",c);
                	}
            	}    
        	else
            	{
            	printf("Enter a number to be inserted at the position %x: ",position);
            	scanf("%d",&c);
            	flag=l1.insert_position(c,position);
            	if(flag==1)
                	{
                    	printf("%d is Successfully inserted at the position %x of the List\n\n",c,position);
                	}
            	}
        	break;

        	case 4:
        	flag=l1.delete_beginning();
        	if(flag==-1)
            	{
                	printf("The List is already empty and hence the element cannot be deleted\n");
            	}
        	else
        	{
            	printf("The element is %d is Successfully Deleted at the Beginning of the List\n",flag);
        	}
        	break;

        	case 5:
        	flag=l1.delete_end();
        	if(flag==-1)
            	{
                	printf("The List is already empty and hence the element cannot be deleted\n");
            	}
        	else
        	{
            	printf("The element is %d is Successfully Deleted at the End of the List\n",flag);
        	}
        	break;
        	case 6:
        	int position_del;
        	printf("Enter the position where you wanted to delete the element: ");
        	scanf("%d",&position_del);
        	if(position_del<=0)
            	{
                	printf("Enter valid position\n");
            	}
        	else if(position_del==1)
            	{
                	flag=l1.delete_beginning();
                	printf("The element %d is Successfully deleted at the position 1 of the List\n\n",flag);    
            	}    
        	else
            	{
            	flag=l1.delete_position(position);
                if(flag==-1)
                {
                    printf("Position is out of range\n");
                }
            	
                else
                {
                    printf("%d is Successfully deleted at the position %x of the List\n\n",flag,position_del);
            	}
                }
        	break;
        	case 7:
            int search_for;
            printf("Enter the element you wanted to search in the List");
            scanf("%d",&search_for);
            l1.search(search_for);
        	break;
        	case 8:
        	printf("The list is: ");
        	l1.display();
        	printf("\n\n");
        	break;
        	case 9:
            l1.display_reverse();  
        	break;
        	case 10:
            l1.reverse_list();
            printf("The list is Successfully reversed\n");
        	break;
        	case 11:
        	printf("Exiting...\n");
        	break;
        	default:
        	printf("Please try again by entering valid number from the Menu\n");
    	}
	}while(choose!=11);
	return 0;
}
//Function to Insert element at the Beginning
int list :: insert_beginning(int key)        	//key is the element user wanted to insert in the list
        	{
            	struct node* newnode=(node*)malloc(1*sizeof(struct node));
            	newnode->data=key;
            	newnode->next=head;
            	head=newnode;
            	return 1;    
        	}
//Function to Insert the element at the End of the List
int list :: insert_end(int key)
        	{
            	struct node* newnode=(node*)malloc(1*sizeof(struct node));
            	if(head==NULL)
            	{
                	return 0;
            	}
            	else if(head!=NULL)
            	{
                	newnode->data=key;
                	newnode->next=NULL;
                	struct node* temp=head;
                	while(temp->next!=NULL)
                	{
                    	temp=temp->next;
                	}
                	temp->next=newnode;
            	}    
            	return 1;
        	}    
//Function to Insert an element at position x of the List
int list :: insert_position(int key,int position)
        	{
            	struct node* newnode=(node*)malloc(1*sizeof(node));
            	newnode->data=key;
            	struct node* temp=head;
            	for(int i=1;i<position-1 && temp->next!=NULL;i++)
            	{
                	temp=temp->next;
            	}
            	newnode->next=temp->next;
            	temp->next=newnode;
            	return 1;
        	}
//Function to Delete the element in the Beginning of the List
int list :: delete_beginning()
        	{
            	if(head==NULL)
            	{
               	return -1;
            	}
            	else
            	{
                	struct node* temp=head->next;
                	int deleted_element=head->data;
                	free(head);
                	head=temp;
                	return deleted_element;
            	}    
        	}  
//Function to Delete the element at the End of the List
int list :: delete_end()
        	{
            	if(head==NULL)
            	{
               	return -1;
            	}
            	else
            	{
                	struct node* temp=head;
                	while(temp->next->next!=NULL)
                	{
                    	temp=temp->next;
                	}
                	int deleted_element=temp->next->data;
                	free(temp->next);
                	temp->next=NULL;
                	return deleted_element;
            	}
        	}
//Function to Delete the element at the Position x of the List  
int list :: delete_position(int position)
        	{
            	struct node* temp=head;
            	for(int i=1;i<position-1&&temp->next!=NULL;i++)
            	{
                	temp=temp->next;
            	}
            	if(temp==NULL||temp->next==NULL)
                {
                  return -1;
                }
                struct node*delete_node=temp->next;
                int deleted_element=delete_node->data;
                temp->next=delete_node->next;
                free(delete_node);
                return deleted_element;
        	}             
//Function to Search an element in the List
int list :: search(int key)
            {
                struct node* temp = head;
                int position = 1;  // Start at position 1

                while (temp != NULL) {
                    if (temp->data == key) {
                        return position; // Element found
                    }
                    temp = temp->next;
                    position++;
                }

                return -1; // Element not found
            }

//Function to Display the elements of the List
void list :: display()
        	{
            	if(head==NULL)
            	{
                	printf("The list is empty and hence cannot be displayed\n");
            	}
            	else
            	{
                	struct node* temp=head;
                	while(temp!=NULL)
                	{
                    	printf("%d ",temp->data);
                    	temp=temp->next;
                	}
            	}
        	}
//Function to Display the list reverse            
void list :: display_reverse()
            {
                int count=0;
                struct node* temp=(struct node*)malloc(sizeof(struct node*));
                temp=head;
                while(temp!=nullptr)
                {
                   count++;
                   temp=temp->next; 
                }
                for(int i=count;i>0;i--)
                {
                    temp=head;
                    for(int j=i-1;j>0;j--)
                    {
                        temp=temp->next;
                    }
                    printf("%d ",temp->data);
                }
                printf("\n");   
            }   
//Function to Reverse the List            
void list :: reverse_list()
            {
                struct node* prev = NULL;
                struct node* current = head;
                struct node* next = NULL;
                while (current != NULL)
                 {
                        next = current->next;  
                        current->next = prev;  
                        prev = current;        
                        current = next;        
                }
                head = prev;  
            }