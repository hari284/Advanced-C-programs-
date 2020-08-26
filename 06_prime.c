/*Documentation
Name        : Hargovind Singh
Date        : 19-07-2020
Description : WAP to print the prime number smaller than or equal to n(entered number) using sieve of eratosthenes method
Input       : 10
Output      : The prime less than or equal to 10 are: 2, 3, 5, 7
 */
#include<stdio.h>//for printf() and scanf()
#include<math.h>//for pow()
int main()
{
    char choice;
    do
    {
        int limit;//variable to store limit value
        printf("Enter the value of 'n' : ");
        scanf("%d",&limit);//reading limit from user
        if (limit > 0)//checking for positivity
        { 
            if (limit < (int)pow(2,20))//checking whether it is greater than 2^20 or not
            {    
                int prime[limit-1];//declaring array of limit-1 size
                for (int i = 0; i < limit-1; i++)
                {
                    prime[i] = i+2;//initializing array index by index
                }
                for (int ind = 0; ind < limit/2; ind++)//outer loop for findind out the multiples
                {
                    if (prime[ind] == 0)//checking whether element is zero or not....to avoid floating point error
                        continue; 
                    for (int j = ind+1; j < limit-1; j++)//inner loop
                    {
                        if (prime[j] == 0)//if element is zero then continue
                            continue;
                        else
                        { 
                            if (prime[j]%prime[ind] == 0)//if element is a multiple then true
                                prime[j] = 0;
                        }
                    }
                }
                printf("The prime less than or equal to %d are : 2",limit);//since 2 is the first prime number
                //also output should be like 2, 3, 5 not like 2, 3, 5,   so to avoid that comma at last, printing first prime number along the message.
                for (int ind = 1; ind < limit-1; ind++)//loop for printig the prime numbers
                {
                    if (prime[ind] == 0)//check whether the element value is 0 or not
                        continue;
                    else 
                        printf(", %d",prime[ind]);//printing the prime numbers one by one

                }
            }
            else
                printf("Number out of range");
        }
        else
            printf("Invalid input");
        printf("\n");
        printf("Want to continue[y/n]: ");
        scanf("\n%c",&choice);
    }while(choice == 'y');
    return 0;
}

