/*Documentation
  Name        : Hargovind Singh
  Date        : 01 Aug 2020
  Description : WAP to implement my_printf() function.
  Input       : 
  Output      : 
*/
#include <stdio.h>
#include <stdarg.h>
int my_printf (const char *format, ...);//function prototype of variadic type
int main() 
{
  char choice;//for user prompt
  do
  {
    int num;
    char ch, *str;
    my_printf("Enter a number, char, string: ");//calling function
    scanf("%d",&num);
    scanf("\n%c",&ch);//reading variables
    scanf("\n%ms",&str);
    my_printf("Output: %d %c %s",num,ch,str);//calling function
    my_printf("\nWant to continue[y/n]: ");//calling function
    scanf("\n%c",&choice);
  }while(choice == 'y');
  return 0;
}
int my_printf (const char *format, ...)//function definition
{
  va_list ap;//macro for first argument
  //variables decleration
  int x,count=0;
  char *str;
  va_start(ap, format);//starting macro
  while(*format)
  {
    if (*format == '%')//checking for formare specifier
    {
      format++;
      if (*format == 'd')//for int
      {
        x = va_arg(ap, int);
        fprintf(stdout, "%d",x);//printing
        count++;
      }
      if (*format == 'c')//for char
      {
        x = va_arg(ap, int);
        fprintf(stdout, "%c",(char)x);//printing
        count++;
      }
      if (*format == 's')//for string
      {
        str = va_arg(ap, char*);
        fprintf(stdout, "%s",str);//printing
        while (*str != '\0')
        {
          count++;
          str++;
        }
        
      }
    }
    else
    {
      putchar(*format);//printing
      count++;
    }
    format++;
  }
  va_end(ap);
  return count;
}