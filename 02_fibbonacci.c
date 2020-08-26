/*Documentation
Name        : Hargovind Singh
Date        : 14-07-2020
Description : WAP to generate fibbonacci numbers <= n
Input       : 10
Output      : 0 1 1 2 3 5 8
 */
#include<stdio.h>
#include<stdlib.h>
int main()
{
    char choice;
    do
    {
        int first_term = 0, limit;//variable declaration
        printf("Enter a number: "); // message to user
        scanf("%d",&limit);// reading highest number of fibbonacci series
        if (limit == 0) //checking whether limit is 0 or not
        {
            printf("0");
        }
        else
        {
            if (limit > 0)//checking for positive limit
            {
                int second_term = 1;//declaring and assigning second term
                printf("%d, %d",first_term,second_term);//display initial first and second term
                for(int third_term = 0; ; ) //loop till third term get greater than limit
                {
                    third_term = first_term + second_term;//calculating third term
                    if (third_term > limit)//checking for end 
                        break;
                    else
                    {
                        first_term = second_term;
                        second_term = third_term;
                        printf(", %d ",third_term);
                    }
                }
                printf("\n");
            }
            else//if limit is negative
            {
                int second_term = -1;//assigning second term 
                printf("%d, %d",first_term,second_term);
                for(int third_term = 0; ; )//loop for generating fibbonacci series
                {
                    third_term = first_term - second_term;//calculating third term
                    if (abs(third_term) > abs(limit))//condition for end term
                        break;
                    else
                    {
                        first_term = second_term;
                        second_term = third_term;
                        printf(", %d",third_term);
                    }
                }
                printf("\n");
            }
        }
        printf("Want to continue[y/n] : ");
        scanf("\n%c",&choice);
    }while(choice == 'y');
    return 0;
}

