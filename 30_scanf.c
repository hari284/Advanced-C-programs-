/*Documentation
Name        : Hargovind Singh
Date        : 2nd Aug 2020
Description : WAF to read an integer without using scanf() function
Input       : Enter a number: asd123
Output      : The number is 0
 */
#include<stdio.h>
int read_int(char *);//read_int() function prototype
int is_digit(char);//is_digit() function prototype
int main()
{
    char choice;
    do
    {
        char *string;//pointer for characters
        printf("Enter a number: ");
        scanf("%ms",&string);//reading string
        read_int(string);//calling read_int() function
        printf("Want to continue[y/n]: ");
        scanf("\n%c",&choice);
    }while(choice == 'y');
    return 0;
}
int read_int(char *str)
{
    if ( ((*str == '+' || *str == '-') && is_digit(*(str+1)) == 1) || is_digit(*(str)) == 1 )//checking for the validation of string to be an number
    {
        printf("The number is ");
        if ( *str == '+' || *str == '-' )//if string contains + or -
        {
            if ( *str == '+' )//contains +
                str++;//INC in base address
            else
            {
                putchar(*str);//prinitng -
                str++;//INC in pointer or base address
            }
        }

        while(is_digit(*str))//for printing digits
        {   
            putchar(*str);
            str++;//INC address
        }

        printf("\n");
    } 
    else
        printf("The number is 0\n");;
    return 0;
}
int is_digit(char ch)//is_digit function definition
{
    if ( ch >= 48 && ch <= 59 )//range of digits in ascii table is 48 to 57
        return 1;
    else
        return 0;
}

