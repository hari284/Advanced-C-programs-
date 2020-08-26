/*Documentation
  Name        : Hargovind Singh
  Date        : 01 Aug 2020
  Description : WAP to replace multi-spaces/blank by one space/blank in string
  Input       : hi     hello  how   are you
  Output      : hi hello how are you
*/
#include<stdio.h>
int main()
{
    char ch;//variable to read input from user
    int flag = 0;//status flag to keep track on space, tab or printable character 
    while((ch = getchar()) != '\n')//till new line character...
    {
        if ( ch != ' ' && ch != '\t')//cond. for no spac/blank
        {
            putchar(ch);//getting store in output buffer
            flag = 0;
        }
        if ( (ch == ' ' || ch == '\t') && flag == 0 )//cond. for spaces/tabs
        {
            putchar(' ');//getting store in output buffer
            flag = 1;
        }
    }
    putchar(ch);//printing from output buffer to stdout
    return 0;
}

