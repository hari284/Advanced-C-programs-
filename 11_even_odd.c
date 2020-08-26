/*Documentation
Name        : Hargovind Singh
Date        : 18-07-2020
Description : WAP to check whether the entered number is even or odd using bitwise operator.
Input       : 4
Output      : 4 is positive even number
 */
#include<stdio.h>
int main()
{
    char choice;//variable for the user promt for continue option
    do
    {
        int num;//number variable
        printf("Enter the value of 'N':");
        scanf("%d",&num);//reading number
        //checking for positive or negative
        //since zero(0) is even number so no need to write saperate condition for that
        if ((num & 0x80) == 0)//for positive
        {
            if ((num & 0x01) == 0)//even
                printf("%d is a positive even number\n",num);
            else//odd
                printf("%d is a positive odd number\n",num);
        }
        else//for negative
        {
            if ((num & 0x01) == 0)//for even
                printf("%d is a negative even number \n",num);
            else//odd
                printf("%d is a negative odd number\n",num);
        }
        printf("Do you want to continue(y/n):");
        scanf("\n%c",&choice);//reading choice
    }while(choice == 'y');//checking for choice whether to continue or not
    return 0;
}

