#include<cstdio>
#include"sort.h"
//headerfile is included which has all the 3 types of search and print array functions

//Function to search an element in the array using linearsearch 
void LinearSearch(int arr[],int n,int a)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==a)
        {
            printf("\nThe element is found at index %d of array\n",i);
            return;
        }
    } 
      printf("\nElement not found\n");
}

//Function to search an element in the array using binarysearch 
void BinarySearch(int arr[],int n,int a)
{
  int low=0;
  int high=n-1;
  while(low<=high)
  {
    int mid=low+(high-low)/2;
     if(arr[mid]==a)
     {
        printf("\n%d is found in the index %d of the sorted array\n",a,mid);
        return;
     }
     if(arr[mid]<a)
     {low=mid+1;}
     else {
        high=mid-1;
     }
  }
  printf("\n%d is not found in the array\n",a);
}
int main()
{
    int n;
    //inputing the size of array with boundary condition
   do{ 
    printf("Enter the size of the array:");
    scanf("%d",&n);
    if(n<=0)
    {
        printf("Size of the array cannot be negative ,Please enter valid number");
    }
   }while(n<=0);
     int arr[n];

     //inputing the elements of the array
     printf("\nNow start entering the elements of the array\n");
    for(int i=0;i<n;i++)
     {
      printf("\nEnter element%d of array:",i+1);
      scanf("%d",&arr[i]);
     }
        

    //printing the array the user entered 
    printf("\nThe array you entered is:\n");
    printarray(arr,n);

int a;
//creating menu to allow the user to select the type of search 
int choose_search;
do{                      //running the loop infinitely till user asks to exit(4) i.e. done using do while loop
    printf("\nChoose any number from the following menu: ");
    printf("\n1 for LinearSearch\n2 for BinarySearch\n3 to Exit\n");
    scanf("%d",&choose_search);
    switch(choose_search){
        case 1:
            printf("\nEnter element you wanted to search in the given data: ");
            scanf("%d",&a);
            LinearSearch(arr,n,a);
            break;
        case 2:
            printf("\nEnter element you wanted to search in the given data: ");
            scanf("%d",&a);
            int choose;

            printf("\nChoose any number from the following menu to sort the array: ");
            printf("\n1 for Bubble sort\n2 for Selection sort\n3 for Insertion sort\n4 to Exit\n");
            scanf("%d",&choose);
        
                //creating menu to allow the user to select the type of sort before doing binarysearch
                
            switch(choose)
            {
                case 1:
                    Bubblesort(arr,n);
                    printf("The sorted array using Bubblesort  ");
                    printarray(arr,n);
                    break;
                case 2:
                    Selectionsort(arr,n);
                    printf("The sorted array using Selectionsort  ");
                    printarray(arr,n);
                    break;
                case 3:
                    Insertionsort(arr,n);
                    printf("The sorted array using Insertionsort  ");
                    printarray(arr,n);
                    break;
                case 4:
                    printf("EXITING...");
                    break;
            }
                BinarySearch(arr,n,a);
                break;
        case 3:
            printf("\nExiting...");
            break;
 }

}while(choose_search!=3);       //running the loop infinitely till user asks to exit(4)
return 0;
}