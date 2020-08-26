/*Documentation
   Name        : Hargovind Singh
   Date        : 17-8-2020
   Description : wap to sort the strings
   Input       :
   Output      :
*/
#include<stdio.h>
#include<stdlib.h>
//function protypes
void reorder(int n,char *x[]);
int my_strcmp(char *strg1, char *strg2);
void *my_strcpy(char *destination, char *source);
void main()
{
    char choice;//for user prompt
    do
    {
        int i,n=0;
        printf("Enter no. of String : ");
        scanf("%d",&n);//reading no of rows
        char *x[n];//array of string of 'n' rows 
        for(i=0;i<n;i++)
        {
            printf("Enter the Strings %d : ",i+1);
            x[i]=(char *)malloc(32*sizeof(char));//creating memory space for max 32 bytes in each
            scanf("%s",x[i]);//reading string
        }
        reorder(n,x);//calling function
        printf("\nreorder list is :  \n");
        for(i=0;i<n;i++)
        {
            printf("%d %s\n",i+1,x[i]);//to print
        }
        printf("Wat to continue[y/n]: ");
        scanf("\n%c",&choice);
    }while(choice == 'y');
}
void reorder(int n,char *x[])
{
    //local variable decleration
    int i,j;
    char t[32];
    //logic for sorting
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(my_strcmp(x[i],x[j])>0)
            {
                my_strcpy(t,x[j]);//calling function
                my_strcpy(x[j],x[i]);
                my_strcpy(x[i],t);
            }
        }
    }
    return;
}
int my_strcmp(char *strg1, char *strg2)//strcmp function definition
{
    while( ( *strg1 != '\0' && *strg2 != '\0' ) && *strg1 == *strg2 ) //logic
    {
        strg1++;
        strg2++;
    }

    if(*strg1 == *strg2)
    {
        return 0; // strings are identical
    }

    else
    {
        return *strg1 - *strg2;
    }
}
void *my_strcpy(char *destination, char *source)//strcpy definition
{
    char *start = destination;

    while(*source != '\0')//logic
    {
        *destination = *source;
        destination++;
        source++;
    }

    *destination = '\0'; // add '\0' at the end
}