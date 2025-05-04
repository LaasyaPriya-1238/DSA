#include<cstdio>

class list
{
    private:
    int arr[5];
    int size = 0;

    public:
    int insert_beginning(int key);
    int insert_end(int key);
    int insert_pos(int key,int position);
    int delete_beginning();
    int delete_end();
    int delete_pos(int position);
    int search(int a);   //a is the element user wants to search
    void display();
    void reverse(int arr[],int start,int end);
    void rotate_reverse(int k);    //where k is the no. of times user wants to rotate an array
    void rotate_by_temp(int k);
    void rotate_by_loops(int k);
   
};
int main()
{   
    class list l1;
    int choose;
    int flag;
 do
 {   
    printf("Select the operation to be performed from the following menu: \n");
    printf("1 To insert at Beginning\n2 To insert at the End\n3 To insert at a particular position\n4 To delete at Beginning\n5 to delete at the End\n6 To Delete at a particular position\n7 To Search a particular element\n8 To Display the list\n9 To rotate the list\n10 To Exit\n ");
    scanf("%d",&choose);
    switch(choose)
    {
        case 1:
        //a is the element to be inserted at the beginning of the list
        int a;
        printf("Enter the element to be inserted at the beginning of the list: \n");
        scanf("%d",&a);

        flag=l1.insert_beginning(a);
        if(flag==-1)
        {
            printf("The list is full\nElement cannot be inserted\n\n");
        }
        else if(flag==1)
        {
            printf("The element is successfully added at the Beginning of the List\n\n");
        }
        break;

        case 2:
        //b is the element to be inserted at the end of the list
        int b;
        printf("Enter the element to be inserted at the end of the list: \n");
        scanf("%d",&b);

        flag=l1.insert_end(b);
        if(flag==-1)
        {
            printf("The list is full\nElement cannot be inserted\n\n");
        }
        else if(flag==1)
        {
            printf("The element is successfully added at the end of the List\n\n");
        }
        break;

        case 3:
        //x is the position where the user wanted to add the element in the list
        int x;
        printf("Enter the position where you want to enter the element: ");
        scanf("%d",&x);

        //c is the element to be inserted at the position x of the list
         int c;
        printf("Enter the element to be inserted at the position %d of the list: \n",x);
        scanf("%d",&c);

        flag=l1.insert_pos(c,x);
        if(flag==-1)
        {
            printf("The list is full\nElement cannot be inserted\n\n");
        }
        else if(flag==1)
        {
            printf("The element is successfully added at the %d position of the List\n\n",x);
        }
        else if(flag==0)
        {
            printf("The element cannot be added at the position %d which is out of bound of the List\n\n",x);
        }
        break;

        case 4:
        flag=l1.delete_beginning();
        if(flag==-1)
        {
            printf("The list is empty already\nElement cannot be deleted\n\n");
        }
        else 
        {
            printf("The element is successfully deleted at the beginning of the List\n\n");
            printf("The deleted element at the beginning is %d \n\n",flag);
        }
        break;

        case 5:
        flag=l1.delete_end();
        if(flag==-1)
        {
            printf("The list is empty already\nElement cannot be deleted\n\n");
        }
        else 
        {
            printf("The element is successfully deleted at the end of the List\n\n");
            printf("The deleted element at the end is %d \n\n",flag);
        }
        break;

        case 6:
        //y is the position where the user wanted to delete the element in the list
        int y;
        printf("Enter the position where you want to delete the element: ");
        scanf("%d",&y);
        
        flag=l1.delete_pos(y);
        if(flag==-1)
        {
            printf("The list is empty already\nElement cannot be deleted\n\n");
        }
        else if(flag==-2)
        {
            printf("The element cannot be deleted at the position %d which is out of bound of the List\n\n",y);
        }
        else
        {
            printf("The element is successfully deleted at the position %d of the List\n\n",y);
            printf("The deleted element at the end is %d \n\n",flag);
        }

        break;

        case 7:
        int searching_for;   //searching_for is the element user wants to search for
        printf("Enter the element you wanted to search: ");
        scanf("%d",&searching_for);
        flag=l1.search(searching_for);
        if(flag== -1)
        {
            printf("The element %d is not found in the list\n\n",searching_for);
        }
        else
        {
            printf("The element %d is successfully found at %d position of the list\n\n",searching_for,flag);
        }
        break;

        case 8:
        printf("The list is\n");
        l1.display();
        break;

        case 9:
        int no_rotate;
        printf("Enter the number of times you want to rotate the list: ");
        scanf("%d",&no_rotate);
        l1.rotate_reverse(no_rotate);
        break;

        case 10:
        printf("Exiting...\n");
        break;

        default:
        printf("\nInvalid number\nPlease try again and enter the correct number from the menu\n");
    }
 }while(choose!=10);

    return 0;
}


//Function to INSERT the element at the BEGINNING
int list :: insert_beginning(int key)
            {
                if(size==5)
                {
                    return -1;
                }
                else if(size<5)
                {
                    for(int i=size;i>0;i--)
                    {
                        arr[i]=arr[i-1];
                    }
                    arr[0]=key;
                    size++;                
                }
                 return 1;
            }


//Function to INSERT the element at the END
int list:: insert_end(int key)
            {
                if(size==5)
                {
                    return -1;
                }
                else if(size<5)
                {
                    size++;
                    arr[size-1]=key;
                }
                return 1;
            }

//Function to INSERT the element at the POSITION x
int list:: insert_pos(int key,int position)
            {
                if(size==5)
                {
                    return -1;
                }
                if(position > 5 || position<0)
                {
                    return 0;
                }
                else if(size<5)
                {
                    for(int i=size;i>position;i--)
                    {
                        arr[i]=arr[i-1];
                    }
                    arr[position]=key;
                    size++;
                }
                return 1;
            }

//Function to DELETE the element at the BEGINNING
int list :: delete_beginning()
            {
                if(size==0)
                {
                    return -1;
                }
                else
                {   int deleted_element=arr[0];
                    for(int i=0;i<size;i++)
                    {
                        arr[i]=arr[i+1];
                    }
                    size--;
                    return deleted_element;
                }
                
            }

//Function to DELETE the element at the END
int list :: delete_end()
            {
                if(size==0)
                {
                    return -1;
                }
                else
                {
                    int deleted_element=arr[size-1];
                    size--;
                    return deleted_element;
                }
                
            }

//Function to DELETE the element at the POSITION x
int list :: delete_pos(int position)
            {
                if(size==0)
                {
                    return -1;
                }
                if(position > 5 || position<0)
                {
                    return -2;
                }
                else
                {   int deleted_element=arr[position];
                    for(int i=position;i<size;i++)
                    {
                        arr[i]=arr[i+1];
                    }
                    size--;
                    return deleted_element;
                }
            }

 int list :: search(int a)           // a is th element user wants to search  
            {
                for(int i=0;i<size;i++)
                {
                    if(arr[i]==a)
                    {
                        return i;
                    }
                }
                return -1;
            }

//Function to print/display an array
void list ::   display()
                {
                    if(size==0)
                    {
                        printf("The list is empty,it cannot be dislayed\n\n");
                    }
                    else if(size>0)
                    {
                        for(int i=0;i<size;i++)
                        {
                            printf("%d ",arr[i]);
                        }
                        printf("\n\n");
                    }
                }

//Function to reverse an array given start and end positions range which are to be reversed 
void list :: reverse(int arr[],int start,int end)
        {
                for(int i=start,j=end;i<j;i++,j--)
                {
                    int temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
             
            }        
//Function to rotate the list k times
void list :: rotate_reverse(int k)
            {
                if (size==0)
                {
                    printf("The list is empty, it cannot be reversed\n\n");
                    return;
                }
                    else
                    {
                        k=k%size;
                        reverse(arr,0,size-1);
                        reverse(arr,0,k-1);
                        reverse(arr,k,size-1);
                    }
                
            }


//other methods to rotate the list
 //2nd method to rotate the list
  
void list  :: rotate_by_temp(int k)
                {
                    if(size==0)
                    {
                        printf("The list is empty,it cannot be rotated\n");
                        return;
                    }
                    k=k%size;
                    int temp[5];
                    for(int i=0;i<size;i++)
                    {
                        temp[(i+k)%size]=arr[i];
                    }
                    for(int i=0;i<size;i++)
                    {
                        arr[i]=temp[i];
                    }
                }

    //3rd method to rotate the list
void list:: rotate_by_loops(int k)
            {
                if(size==0)
                {
                    printf("the list is empty so cant rotate\n");
                    return;
                }
                k=k%size;
                for(int i=0;i<k;i++)
                {
                    int last=arr[size-1];
                    for(int j=size-1;j>0;j--)
                    {
                        arr[j]=arr[j-1];
                    }
                    arr[0]=last;
                }
            }
           