/*Documentation
Name        : Hargovind Singh
Date        : 27-07-2020
Description : WAP to find the factorial of a given number using recursion and without using any other function than main
Input       : Enter the value of number : 4
Output      : Factorial of 4 is : 24
 */
#include<stdio.h>
int main()
{
    char choice;//variable to store the value for continuation of program
    static int fact = 1, flag = 1, Num, temp;//Num is for storing number,


    do
    {
        fact = 1, flag = 1;
        if ( flag == 1 )//checking if flag == 1 or not
        {
            printf("Enter the value of number : ");
            scanf("%d",&Num);//reading number
            if ( Num < 0 )//checking whether number is < 0 or not
            {
                printf("Invalid input\n");
                return 0;
            }
            if ( Num == 0 )//checking if number is 1
            {
                printf("Factorial of 0 is : 1\n");
                return 0;
            }
            else 
            {
                temp = Num;
                flag = 0;//setting flag to 0
            }
        }
        fact *= temp--;//calculating factorial
        if (temp >= 1)
            return main();//calling main() function again//recursion

        printf("Factorial of %d is : %d\n",Num,fact);
        printf("Want to continue[y/n]: ");
        scanf("\n%c",&choice);//reading choice to continue
    }while(choice == 'y');
    return 0;
}

