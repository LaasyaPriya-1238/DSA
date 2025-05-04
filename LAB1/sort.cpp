#include<cstdio>

// Function to print array
void printarray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Case 1: Bubble Sort with step-by-step output
void Bubblesort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - 1 - i; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            printarray(arr, n);  // Print after every inner loop iteration
        }
        printf("\n");
    }
}

// Case 2: Selection Sort with step-by-step output
void Selectionsort(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        int min = i;
        for(int j = i; j < n; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;

        printarray(arr, n);  // Print after each outer loop iteration
        printf("\n");
    }
}

// Case 3: Insertion Sort with step-by-step output
void Insertionsort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int j = i;
        while(j > 0 && arr[j] < arr[j - 1]) {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;

            printarray(arr, n);  // Print after each swap
        }
        printf("\n");
    }
}

int main() {
    int n;

    // Input array size
    do {
        printf("\nEnter the size of the array: ");
        scanf("%d", &n);
        if(n <= 0) {
            printf("Size of the array cannot be negative or zero. Please enter a valid number.\n");
        }
    } while(n <= 0);

    int arr[n];

    // Input elements
    printf("\nNow start entering the elements of the array\n");
    for(int i = 0; i < n; i++) {
        printf("Enter element %d of array: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Print original array
    printf("\nThe array you entered is:\n");
    printarray(arr, n);

    // Menu for sort options
    int choose;
    do {
        printf("\n\nChoose any number from the following menu: ");
        printf("\n1 for Bubble sort\n2 for Selection sort\n3 for Insertion sort\n4 to Exit\n");
        scanf("%d", &choose);

        // Make a copy to avoid sorting already sorted array in next option
        int copy[n];
        for(int i = 0; i < n; i++) copy[i] = arr[i];

        switch(choose) {
            case 1:
                printf("\nStep-by-step Bubble Sort:\n");
                Bubblesort(copy, n);
                printf("Sorted array using Bubble Sort: ");
                printarray(copy, n);
                break;

            case 2:
                printf("\nStep-by-step Selection Sort:\n");
                Selectionsort(copy, n);
                printf("Sorted array using Selection Sort: ");
                printarray(copy, n);
                break;

            case 3:
                printf("\nStep-by-step Insertion Sort:\n");
                Insertionsort(copy, n);
                printf("Sorted array using Insertion Sort: ");
                printarray(copy, n);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while(choose != 4);

    return 0;
}
