#include<cstdio>
 #include<stdlib.h>
 #include<stdbool.h>
 bool palindrome(int* n){
    int* reversed = (int*)malloc(sizeof(int));
    int* orig = (int*)malloc(sizeof(int));
    *reversed = 0;
    *orig = *n;
    int *temp = (int*)malloc(sizeof(int));
    *temp = *n;
    while (*temp > 0) {
        *reversed = (*reversed) * 10 + *temp % 10;
        *temp /= 10;
    }
    bool result = (*reversed == *orig);
    free(reversed);
    free(orig);
    free(temp);
    return result;
 }
 bool armstrongnum(int* n){
    int* orig = (int*)malloc(sizeof(int));
    int* digits = (int*)malloc(sizeof(int));
    int* sum = (int*)malloc(sizeof(int));
    int* temp = (int*)malloc(sizeof(int));
    int* digit = (int*)malloc(sizeof(int));
    int* pow = (int*)malloc(sizeof(int));
    int* i = (int*)malloc(sizeof(int));
    *orig = *n;
    *digits= 0;
    *sum = 0;
    *temp = *n;
   
    while(*temp>0){
        (*digits)++;
        *temp/=10;
    }
    *temp = *n;
    while (*temp > 0) {
        *digit = *temp % 10;
        *pow = 1;
       
        for (*i = 0; *i < *digits; (*i)++) {
            *pow *= *digit;
        }
        *sum += *pow;
        *temp /= 10;
    }
    bool result = (*orig == *sum);
    free(digit);
    free(pow);
    free(orig);
    free(digits);
    free(sum);
    free(temp);
    return result;
 }
 bool perfect(int *n){
    int* sum = (int*)malloc(sizeof(int));
    int* i = (int*)malloc(sizeof(int));
    *sum = 0;
    for(*i = 1; *i <= *n/2; (*i)++){
        if((*n)% (*i) == 0)
        *sum += *i;
    }
    bool result = *sum == *n;
    free(sum);
    free(i);
    return result;
 }
 int main()
 {
    int* num = (int*)malloc(sizeof(int));
    int* choice = (int*)malloc(sizeof(int));
    printf("Enter a number: ");
    scanf("%d", num);    
    while(true)
    {
     printf("\nMenu\n");
     printf("1. Palindrome\n");
     printf("2. Armstrong Number\n");
     printf("3. Perfect Number\n");
     printf("4. exit\n");
    printf("Enter your choice: ");
    scanf("%d", choice);
   switch(*choice)
   {
    case 1:
       { if (palindrome(num)){
            printf("The number is a palindrome");
        }
        else
        printf("The number is not a palindrome");
        break; }
    case 2:
       { if(armstrongnum(num)){
            printf("The number is Armstrong number");}
        else
        printf("The number is not armstrong");    
        
        break;}
        
    case 3:
       { if (perfect(num)){
            printf("the number is a perfect number");}
        else
        printf("The number is not a perfect number");    
        
        break; }
    
     case 4:
       { free(num);
        free(choice);
        return 0;}
        default:
        printf("Invalid choice. Please try again.\n");
    }
 }
 free(num);
 free(choice);
 return 0;
}
