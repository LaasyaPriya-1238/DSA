#include<cstdio>
void solve();

int main()
{
    int testcases;
    printf("Enter the number of testcases: ");
    scanf("%d",&testcases);
    int count1=1;
    while(testcases--)
    {
        printf("Testcase %d: \n",count1);
        solve();
        count1++;
    }
    return 0;
}

void solve()
{
   int n;  //n is the number of players.
   printf("Enter the number of players: ");
   scanf("%d",&n); 

   int arr[n];   //create an array to store the strength of each player.
   for(int i=0;i<n;i++)
   {
    printf("Enter the strength of player %d: ",i+1);
    scanf("%d",&arr[i]);
   }

   int max1=arr[0];
   int max2=arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max1)
        {
            max2=max1;
            max1=arr[i];
        }
        else if(arr[i]>max2)
        {
            max2=arr[i];
        }
    }

    for(int i=0;i<n;i++)
    {
        if(arr[i]==max1)
        {
            printf("%d ",arr[i]-max2);
        }
        else
        {
            printf("%d ",arr[i]-max1);
        }
    }
    printf("\n\n");
}