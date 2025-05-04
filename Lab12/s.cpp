#include<stdio.h>
int main()
{
int i,j;
for(i=0;i<8;i++)
printf("\n");
printf("\t");
for(i=1;i<=25;i++)
{
    //printf("\t");
    if(i>2&&i<10)
    printf(" ");
    else if(i>11&&i<13)
    printf(" ");
    else if(i>14&&i<=20)
    printf(" ");
    else printf("*");
    }
    printf("\n");
    printf("\t");
for(i=1;i<=28;i++)
    {
    if(i>2&&i<10)
        printf(" ");
        else if(i>11&&i<13)
        printf(" ");
        else if(i>14&&i<=17)
        printf(" ");
        else if(i>=18&&i<21)
        printf("*");
        else if(i>20&&i<26)
        printf(" ");
        else printf("*");
    }
    printf("\n");
    printf("\t");
    for(i=1;i<=29;i++)
    {
        if(i>2&&i<10)
        printf("=");
        else if(i>11&&i<13)
        printf(" ");
        else if(i>14&&i<=16)
        printf(" ");
        else if(i>19&&i<27)
        printf(" ");
        else
        printf("*");
    }
printf("\n");printf("\t");

for(i=1;i<=28;i++)
{
    if(i>2&&i<10)
    printf(" ");
    else if(i>11&&i<13)
    printf(" ");
    else if(i>14&&i<=17)
    printf(" ");
    else if(i>=18&&i<21)
    printf("*");
    else if(i>20&&i<26)
    printf(" ");
    else printf("*");
}
printf("\n");printf("\t");
for(i=1;i<=25;i++)
{
    if(i>2&&i<10)
    printf(" ");
    else if(i>11&&i<13)
    printf(" ");
    else if(i>14&&i<=20)
    printf(" ");
    else printf("*");
}
printf("  ..........");
for(i=0;i<25;i++)
printf("\n");
}
