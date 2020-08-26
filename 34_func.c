/*Documentation
Name        : Hargovind Singh
Date        : 06-08-2020
Description : Implement getword, atoi, itoa functions
Input       :
Output      :
 */
#include<stdio.h>
int getword(char *word);//function prototype
int atoi(const char *s);//function prototype
int itoa(int n, char *s);//function prototype
int is_digit(const char *number);//function prototype
int main()
{
    char choice;//for user prompt
    do
    {
        //variable decleration
        int num;
        char *str;
        const char *cptr;
        printf("Menu :\n1.length of string\n2.string to integer\n3.integer to string\nEnter your choice: ");
        scanf("%d",&num);//reading number..user choice
        switch( num )
        {
            case 1://for getword
                printf("enter the string: ");
                scanf("%ms",&str);
                printf("The length is: %d",getword(str));//calling getword()
                break;
            case 2://for atoi
                printf("Enter the string: ");
                scanf("%ms",&cptr);
                printf("The converted string to integer is: %d",atoi(cptr));//calling atoi()
                break;
            case 3://for itoa
                printf("Enter the number: ");
                scanf("%d",&num);//overwritting to save the memory
                printf("The converted number to string is: %d",itoa(num,str));//calling itoa()
                break;
            default:
                printf("Please enter the valid choice\n");
        }
        printf("\nwanna continue[y/n]:");
        scanf("\n%c",&choice);
    }while(choice == 'y');
    return 0;
}
int getword(char *word)//function definition
{
    //local variable initialization
    int count = 0;
    while(*word++ != '\0')
        count++;//length
    return count;
}
int atoi(const char *s)//function definition
{
    if (((*s != '+' && *s != '-') && is_digit(s) == 0) || ((*s == '+' || *s == '-') && is_digit(s+1) == 0))
        return 0;
    else
    {
        if (*s == '+' || *s == '-')
        {
            int num = 0,flag = 0;
            if (*s == '+')
                flag = 1;
            else
                flag = 0;
            while(is_digit(s+1) == 1)//condition fails if the character of string is not numeric/digit
            {
                num = (num*10) + (*(s+1)-48);//storing in integer
                s++;
                printf("%d",num);
            }
            if (flag == 1)
                return num;
            else
                return -(num);
        }
        else
        {
            int num = 0;
            while(is_digit(s) == 1)
            {
                num = num*10 + (*s-48);
                s++;
            }
            return num;
        }
    }
}
int itoa(int n, char *s)
{
    char str[10];
    s = str;//giving the address of str to s
    int i = 0;
    while(n != 0)//storing digit by digit i str array
    {
       str[i] = n%10;
       n = n/10;
      i++; 
    }
    str[i+1] = '\0';//at last putting null character
    int len = i;
    i = 0;
    while(i<len)//reversing the str array
    {
        int temp = str[i];
        str[i] = str[len];
        str[len] = temp;
        len--;
        i++;
    }
    len = 0;
    while(*s++)
        len++;//calculating the array length
       
    return len;//returning length
}
int is_digit(const char *number)//is_digit() function
{
    if (*number >= 48 && *number <= 57)
        return 1;
    else
        return 0;
}
