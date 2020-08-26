/*Documentation
Name        : Hargovind Singh
Date        : 15-07-2020
Description : WAP to check whether a given number is perfect or not.
Input       : 6
Output      : Yes, entered number is perfect nummber
 */
#include<stdio.h>
#include<math.h>
int main()
{
    char choice;
    do
    {
        int num;//number to check whether it is perfect or not
        printf("Enter a number: ");
        scanf("%d",&num);//reading number
        if (num < (int)pow(2,20))//validation...n < 2^20
        {
            if (num > 0)//checking for positivity.
            {
                int sum = 0;//initializing sum variable
                for(int i = 1;i <= num/2;i++)//loop till half of the number
                {
                    if ((num%i) == 0)//checking for proper divisor
                    {
                        sum += i;//ading it to sum
                    }
                }
                if (sum == num)//comparing with original number
                {
                    printf("Yes, entered number is perfect number\n");//displaying
                }
                else
                {
                    printf("No, entered number is not a perfect number\n");
                }
            }
            else
                printf("Invalid input\n");
        }
        else
            printf("Number out of range\n");
        printf("Want to continue[y/n]: ");
        scanf("\n%c",&choice);
    }while(choice == 'y');
    return 0;
}

