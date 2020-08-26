/*Documentation
Name        : Hargovind Singh
Date        : 15-07-2020
Description : print the octal,hexadecimal and ascii value for 0-127 decimal values
Input       :
Output      :
 */
#include<stdio.h>//for scanf() and printf()
#include<ctype.h>//for isprint()
int main()
{
    printf("Dec    Oct    Hex    Ascii\n");
    printf("---    ---    ---    -----\n");
    for (int i = 0;i <= 127;i++)//loop from 0 to 127 decimal values
    {
        printf("%d\t",i); //print decimal value
        printf("%.3o\t",i);//print octal value
        printf("%.2X\t",i);//print hexadecimal value
        if (isprint(i))
        {
            if (i ==32)//checking for space..sine space is a controlable character
                printf("Not Printable\n");//checking whether the given number is printable or not
            else
                printf("%c\n",i);
        }
        else
            printf("Not Printable\n");
    }
    return 0;
}

