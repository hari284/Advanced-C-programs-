/*Documentation
  Name        : Hargovind Singh
  Date        : 9-08-200
  Description : WAP to implement squeeze function
  Input       : Dennis Ritchie
  Output      : Des Rtche
*/
#include<stdio.h>
#include<stdlib.h>
char *squeeze(char *, char *);//function prototype
int main()
{
    char choice;//variable for user prompt
    do
    {
        char *str1,*str2;//pointers for strings
        printf("Enter string1 : ");
        scanf("%m[^\n]s",&str1);//reading string 1
        getchar();//clearing input buffer
        printf("Enter string2 : ");
        scanf("%m[^\n]s",&str2);//reading string 2
        printf("After squeeze string1 : %s",squeeze(str1,str2));//calling and then printing the squeezed string
        printf("\nWant to continue[y/n]: ");
        scanf("\n%c",&choice);
        getchar();//clearing input buffer
    }while(choice == 'y');
    return 0;
}
char *squeeze(char *str1, char *str2)//function definition
{
    char *cptr;//pointer of character type
    cptr = calloc(10,1);//dynamic memory allocation
    int i = 0, j = 0, flag = 0, len1 = 0, len2 = 0, ind = 0;//variable initialization
    while(*str1++)//calculating length of first string
        len1++;
    str1 = str1-len1-1;
    while(*str2++)//length of second string
        len2++;
    str2 = str2-len2-1;
    //........deleting the same characters.........//
    for(i = 0; i < len1; i++)
    {
        char ch = *(str1+i);
        for(j = 0; j < len2; j++)
        {
            if (ch == *(str2+j))
            {
                flag = 1;
                break;
            }
            else
                flag = 0;
        }
        if (flag == 0)
            *(cptr+(ind++)) = ch;
    }
    return cptr;
}

