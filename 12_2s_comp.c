/*Documentation
Name        : Hargovind Singh
Date        : 18-07-2020
Description : To print bits of signed and unsigned type for given number and check for 2's compliment.
Input       : 12
Output      : +12 -> 00000000000000000000000000001100
            : -12 -> 11111111111111111111111111110100
 */
#include<stdio.h>
#include<stdbool.h>
int main()
{
    char choice;//variable for promting user to continue or not
    do
    {
        int num;//number variable
        int flag = 0;//variable to assume the entered number is initially negative
        printf("Enter the number : ");
        scanf("%d",&num);//reading number
        //suppose user have entered negative number than we need to print 32bits
        //for negative first then positive of that number for the user convinience.
        //so took flag variable.
        if(num > 0)
        {
            flag=1;
            printf("+%d -> ",num);
        }
        else
            printf("%d -> ",num);
        for (int i = 0; i < 32; i++)//looping 32 times as 32 bit formate
        {
            bool bit = (num >> (31 - i)) & 1;
            printf("%d ",bit);//printing MSB
        }
        num = -num;//making number negetive of entered number
        if(flag == 1)
        {
            printf("\n%d -> ",num);
        }
        else
            printf("\n+%d -> ",num);
        for(int i = 0; i < 32; i++)//looping 32 times
        {
            bool bit = (num >> (31-i)) & 1;
            printf("%d ",bit);//printinf MSB
        }
        printf("\nDo you want to continue(y/n):");
        scanf("\n%c",&choice);//reading user choice whether he/she want to continue or not
    }while(choice == 'y');//condition checking
    return 0;
}

