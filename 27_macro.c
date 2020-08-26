/*Documentation
Name        : Hargovind Singh
Date        : 21-08-2020
Description : To define a macro swap (t, x, y) that interchanges two arguments of type t
Input       : 
Output      : 
 */
#include<stdio.h>
int my_strcmp(char *,char *);//my_strcmp function prototype
//macro definition
#define swap(t,x,y)                          \
if (my_strcmp(t,"int") == 0)                 \
{                                            \
    int temp = x;                            \
    x = y;                                   \
    y = temp;                                \
}                                            \
else if (my_strcmp(t,"char") == 0)           \
{                                            \
    char temp = x;                           \
    x = y;                                   \
    y = temp;                                \
}                                            \
else if (my_strcmp(t,"float") == 0)          \
{                                            \
    float temp = x;                          \
    x = y;                                   \
    y = temp;                                \
}                                            \
else if (my_strcmp(t,"double") == 0)         \
{                                            \
    double temp = x;                         \
    x = y;                                   \
    y = temp;                                \
}                                            \
else                                         \
{                                            \
    puts("please pass the valid data type"); \
}                                            \

int main()
{
    char choice;
    do
    {
        //for integer
        int num1,num2;
        printf("Enter num1: ");
        scanf("%d",&num1);//reading first number
        printf("Enter num2: ");
        scanf("%d",&num2);//reading second number 
        swap("int",num1,num2);//macro substitution
        printf("After swapping:\n");
        printf("num1 is %d\n",num1);//printing
        printf("num2 is %d\n",num2);
        getchar();
        //for character
        char ch1,ch2;
        printf("Enter character1: ");
        scanf("%c",&ch1);//reading first character
        getchar();
        printf("Enter character2: ");
        scanf("%c",&ch2);//reading second carater
        swap("char",ch1,ch2);//macro substitution
        printf("After swapping:\n");
        printf("character1 is %c\n",ch1);//printing
        printf("character2 is %c\n",ch2);
        
        //for float
        float n1,n2;
        printf("Enter num1: ");
        scanf("%f",&n1);//reading forst float value
        printf("Enter num2: ");
        scanf("%f",&n2);//reading second float value
        swap("float",n1,n2);//macro substitution
        printf("After swapping:\n");
        printf("num1 is %.2f\n",n1);//printing
        printf("num2 is %.2f\n",n2);
        getchar();
        
        //for double
        double double_n1,double_n2;
        printf("Enter num1: ");
        scanf("%lf",&double_n1);//reading first double value
        printf("Enter num2: ");
        scanf("%lf",&double_n2);//reading second double value
        swap("float",double_n1,double_n2);//macro substitution
        printf("After swapping:\n");
        printf("num1 is %lf\n",double_n1);//printing
        printf("num2 is %lf\n",double_n2);
        getchar();
        printf("\nWant to continue[y/n]: ");
        scanf("\n%c",&choice);
    } while (choice == 'y');//checking condition for continuity of program
    
    return 0;
}
int my_strcmp(char *strg1,char*strg2)//my_strcmp function definition
{
    while( ( *strg1 != '\0' && *strg2 != '\0' ) && *strg1 == *strg2 )//till the end of small string 
    {
        strg1++;//INC
        strg2++;//INC
    }

    if(*strg1 == *strg2)
    {
        return 0; // strings are identical
    }

    else
    {
        return *strg1 - *strg2;//stings are not identical
    }
}