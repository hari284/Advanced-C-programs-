/*Documentation
Name        : Hargovind Singh
Date        : 23-08-2020
Description : WAP to take n and k (1 <= k <= 10) as inputs. Generate consecutive NRPS of 
            :length n using k distinct character (0 <= k <= 9)
Input       : 
Output      : 
 */
#include<stdio.h>

int main() 
{ 
    char choice;
    do
    {
        int K;
        printf("enter the number of characters c: ");
        scanf("%d",&K);
        if (K >= 1 && K <= 10)
        {
            int N;
            char arr[N];
            printf("enter the length of string N: ");
            scanf("%d",&N);
            printf("enter %d distinct characters: ");
            for (size_t i = 0; i < K; i++)
            {
                scanf("%c",arr+i);
            }
            int start = 0;
            for (size_t i = 0; i < (N-K)/K; i++)
            {
                for (size_t j = 0; j < K; j++)
                {
                    arr[K++] = arr[++start];
                }
            }
            for (size_t i = 0; i < N; i++)
            {
                printf("%c",arr+i);
            }
            
        }
        printf("\nWant to continue[y/n]: ");
        scanf("\n%c",&choice);
    }while(choice == 'y');
    return 0; 
} 
