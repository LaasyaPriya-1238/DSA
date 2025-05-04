#include <cstdio>

void process(int t);

// Function to find minimum of two numbers.
int findmin(int a, int b)
{
    return (a < b) ? a : b;
}

int main()
{
    int t; // t is the number of testcases
    printf("Enter the number of testcases: ");
    if (scanf("%d", &t) != 1 || t <= 0) {
        printf("Invalid number of testcases.\n");
        return 1;
    }
    process(t);
    return 0;
}

void process(int t)
{
    for (int count1 = 1; count1 <= t; count1++)
    {
        printf("Testcase %d : \n\n", count1);
        int n, q;
        
        printf("Enter the number of positions: ");
        scanf("%d", &n);
        
        printf("Enter the number of rows: ");
        scanf("%d", &q);
        printf("\n");

        int arr[n];
        for (int i = 0; i < n; i++)
        {
            printf("Enter the position %d: ", i + 1);
            scanf("%d", &arr[i]);
        }
        printf("\n");

        for (int count2 = 1; count2 <= q; count2++)
        {
            int y;
            printf("Enter the number of players in row %d: ", count2);
            scanf("%d", &y);

            int result = findmin(arr[0] - 1, y);
            printf("Result: %d\n", result);
        }
        printf("\n");
    }
}
