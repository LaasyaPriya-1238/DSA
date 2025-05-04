#include"stack_ll.h"
#include<cstdio>
#include<cstring>
const int  n=100;

// Function to check if the string is valid
int is_valid_string(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
       
        // Check if the character is not an uppercase letter, lowercase letter, digit, or '+'
        if (!((ch >= 'A' && ch <= 'Z') ||   (ch >= 'a' && ch <= 'z') ||  (ch >= '0' && ch <= '9') || (ch == '+')))
        {              
            return 0;  // Invalid character found
        }
    }
    return 1;  // String is valid
}


//Function to modify string i.e., to remove all the '+' characters and all non'+' characters at the left of '+'
void process_string(char str[],int n)
{
    stack st;
    int count =0;
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]=='+')
        {
            if(!st.isempty())
            {
                st.pop();   //pops the left non+ character.
                count--;
            }
        }
        else
        {
            st.push(str[i]);
            count++;
        }   
    }

    //Final modified string.
    char resultant_string[count+1];
    int index=count-1;
    while(!st.isempty())
    {
        resultant_string[index--]=st.pop();
    }
    resultant_string[count]='\0';

    printf("The modified string is : %s\n",resultant_string);
}

int main()
{
    char str[n];
    printf("Enter the Expression with operands and '+' operator.\n");
    scanf("%s",str);


    //Check if the string is valid... if it is valid send it for modification else print an error message.
    int flag;
    flag=is_valid_string(str);
        if(flag==0)
        {
            printf("Please enter a valid String with only '+' and alpha-numeric characters\n");
        }
        else
        {
            process_string(str,n);
        }

return 0;
    
}