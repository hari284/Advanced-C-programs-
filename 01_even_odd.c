/*Documentation
Name        : Hargovind Singh
Date        : 13-07-2020
Description : WAP to check whether a given number is odd or even with its signedness.
Input       : -4
Output      : -4 is -ve even number.
 */
#include<stdio.h>
#include<math.h>
int main()
{
    int num; //number variable
    char choice; //user choice variable for whether he want to continue or not

    do
    {    
        printf("Please enter a number : "); //message to user
        scanf("%d",&num); //taking input
        if (num == 0)
        {
            printf("0 is neutral even number.");// since 0 is niegther positive nor negative..it s neutral
        }
        else
        {
            if (num < (int)pow(2,20)) //pow() returns double data type value so explicit typecasting 
            {
                if (num%2 == 0)//checking for even
                {
                    if (num < 0)//checking for neg or pos
                        printf("%d is -ve even number",num);
                    else
                        printf("%d is +ve even number",num);
                }
                else
                {
                    if (num < 0)//neg or pos
                        printf("%d is -ve odd number",num);
                    else
                        printf("%d is +ve odd number",num);
                }

            }
            else
                printf("Number out of range");//error message
        }
        printf("\nDo you want to continue(y/n):");//asking user to continue or not
        scanf("\n%c",&choice);//taking user choice
    }while(choice == 'y');

    return 0;
}

