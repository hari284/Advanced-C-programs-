/*Documentation
Name        : Hargovind Singh
Date        : 21-08-2020
Description : To define a macro SIZEOF(x), where x is a variable, without using sizeof operator
Input       : 
Output      : 
 */
#include <stdio.h>
#define SIZEOF(x) printf("%zu bytes\n",(char*)(x+1) - (char *)(x))//macro definition
int main()
{
    char choice;//for user prompt
    do
    {
        void *ptr;//void pinter

        //for integer
        printf("Size of int : ");
        SIZEOF((int *)ptr);//substituting macro for integer

        //for character
        printf("Size of char : ");
        SIZEOF((char *)ptr);//substituting macro for character
        
        //for float
        printf("Size of float : ");
        SIZEOF((float *)ptr);//substituting macro for float
        
        //for double
        printf("Size of double : ");
        SIZEOF((double *)ptr);//substituting macro for double

        //for unsigned int;
        printf("Size of unsigned int : ");
        SIZEOF((unsigned int *)ptr);//substituting macro for unsigned int

        //for long int
        printf("Size of long int : ");
        SIZEOF((long int *)ptr);//substituting macro for long int

        printf("\nWant to continue[y/n]: ");
        scanf("\n%c",&choice);
    } while (choice == 'y');//checking condition for continuity of program
    
    return 0;
}