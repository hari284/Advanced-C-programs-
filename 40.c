/*Documentation
Name        : Hargovind Singh
Date        : 7-8-2020
Description : WAP to reverse thr array in recursive and no-recursive way
Input       : hello world
Output      : dlrow olleh
 */
#include<stdio.h>
//..................function prototypes....//
char *recursive_reverse(char *str, int start, int end);
char *Non_recursive_reverse(char *str, int start, int end);
int main()
{
    char choice;//variable for user prompt
    do
    {
        //variable decleration and initialization
        char string[30];//string of characters
        int option, len = 0;
        printf("1.Recursive\n2.Non-Recursive\nEnter the choice:");
        scanf("%d",&option);//reading user choice
        printf("Enter a string :");
        getchar();//clearing the buffer
        fgets(string,30,stdin);//reading string
        char *cptr = string;//for calculating the length of input string
        while(*cptr++ != '\0')//calculating length which with include \n(new line) characeter as well
            len++;
        switch( option )
        {
            case 1:
                printf("Reverse string is :%s",recursive_reverse(string,0,len-2));//calling function
                break;
            case 2:
                printf("Reverse string is :%s",Non_recursive_reverse(string,0,len-2));//calling function
                break;
            default:
                printf("Please enter the valid option:");
        }
        printf("Want to continue[y/n]: ");//user prompt
        scanf("\n%c",&choice);
    }while(choice == 'y');
    return 0;
}
char *recursive_reverse(char *str, int start, int end)//function definition
{
    while(start < end)//logic for swapping
    {
        char temp = *(str + start);
        *(str + start) = *(str + end);
        *(str + end) = temp;
        return recursive_reverse(str,++start,--end);//calling recursively
    }
    return str;
}
char *Non_recursive_reverse(char *str, int start, int end)//function definition
{
    while(start < end)//logic for swapping or reversing
    {
         char temp = *(str + start);
         *(str + start) = *(str + end);
         *(str + end) = temp;
         start++;
         end--;
    }
    return str;
}

