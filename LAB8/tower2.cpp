#include<cstdio>

//Function to sort the array using Bubblesort Algorithm.
void bubblesort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1]) //Swap arr[j] and arr[j+1]
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main()
{
        int t; //t is the number of testcases.
        printf("Enter the number of testcases: \n");
        scanf("%d",&t);

        // i is the variable to track which testcase we are in.
        int i=1;

        while(i<=t)
        {
        
            // n is the no. of towers in the respective testcase.
            int n;
            printf("\nEnter the number of Towers in testcase %d : ",i);
            scanf("%d",&n);

            int arr[n];
            printf("\nEnter the number of blocks in each tower \n");
            for(int i=0;i<n;i++)
            {
                 scanf("%d",&arr[i]);
            }

            int x=arr[0]; //x is the number of blocks in the 1st tower
            //Copying all the elements in array into a new array except the 1st element.
            int b[n-1];
            for(int i=1;i<n;i++)
            {
                b[i-1]=arr[i];
            }

            //Sorting the 2nd array.
            bubblesort(b,n-1);
            //Modifying array 2 such that the 1st tower has the highest number of blocks.
            for(int i=0;i<n-1;i++)
            {
                if(b[i]>x)
                {
                    x+=(b[i]-x+1)/2;
                }
            }

            printf("The number of blocks in tower 1 after modification is: %d.\n",x);

            i++;
        }

    return 0;
}