/*Documentation
Name        : Hargovind Singh
Date        : 23-07-2020
Description : WAP to implement own ctype library
Input       :
Output      :
 */
#include<stdio.h>
int is_alpha(char);//function signature
int is_alnum(char);//function signature
int is_ascii(char);//function signature
int is_blank(char);//function signature
int main()
{
    char option;
    do
    {
        char ch;//variable to store user input
        int choice;//vaiable to store the user choice for function call
        printf("Enter the character: ");
        scanf("%c",&ch);//reading character from user
        printf("Select any option:\n1 - isalpha\n2 - isalnum\n3 - isascii\n4 - isblank\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);//reading choice of user
        switch ( choice )
        {
            case 1:
                if ( is_alpha(ch) )//is_alpha(ch) will return 0 or 1
                    printf("The character %c is alphabetic character\n",ch);
                else
                    printf("The character %c is not alphabetic character\n",ch);
                break;
            case 2:
                if ( is_alnum(ch) )//check condition according what is_alnum(ch) function return
                    printf("The character %c is alnum character\n",ch);
                else
                    printf("The character %c is not alnum character\n",ch);
                break;
            case 3:
                if ( is_ascii(ch) )//checking what value is_ascii(ch) returning
                    printf("The character %c is ascii character\n",ch);
                else
                    printf("The character %c is not ascii character\n",ch);
                break;
            case 4:
                if ( is_blank(ch) )//checking the value is_blank(ch) returning
                    printf("The character %c is blank characeter\n",ch);
                else
                    printf("The character %c is not blank character\n",ch);
                break;
            default:
                printf("Please enter valid choice\n");
        }
        printf("Want to continue[y/n]: ");
        scanf("\n%c",&option);
    }while(option == 'y');
    return 0;
}

int is_alpha(char ch)//function definition
{
    return ((ch >= 65 && ch <= 91) || (ch >= 97 && ch <= 123)) ? 1 : 0;//return 1 if codition true else return 0
}
int is_alnum(char ch)//function definition
{
    return (is_alpha(ch) || (ch >= 48 && ch <= 57)) ? 1 : 0;//return 1 if condition true else return 0
}
int is_ascii(char ch)//function definition
{
    return (ch >= 0 && ch <= 127) ? 1 : 0;//return 1 if condition is true else return 0
}
int is_blank(char ch)//function definition
{
    return (ch == ' ' || ch == '\t') ? 1 : 0;//return 1 if condition is true else return 0
}
