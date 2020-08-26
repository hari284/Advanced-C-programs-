/*Documentation
Name        : Hargovind Singh
Date        : 14-07-2020
Description : WAP to generate fibbonacci numbers <= n, using recursion concept
Input       : 10
Output      : 0, 1, 1, 2, 3, 5, 8,
 */
#include<stdio.h>
#include<stdlib.h>
int pos_fibonacci_recursion(int);//function prototype for positive series
int neg_fibonacci_recursion(int);//function prototype for negative series
int main()
{
    int limit, n = 0;//local variables
    printf("Enter a number: ");
    scanf("%d",&limit);//reading highest number of series
    if (limit >= 0)//for positive series
    {
        while(1)
        {
            int term = pos_fibonacci_recursion(n);//calling function
            if( term > limit )//checking for the end point
                break;
            printf("%d, ",term);
            n++;//INC term number
        }
    }
    else//for negative series
    {
        while(1)
        {
            int term = neg_fibonacci_recursion(n);//calling function
            if( abs(term) > abs(limit) )//checking for the end term or point
                break;
            printf("%d, ",term);
            n++;//INC term number
        }
    }
    return 0;
}
int pos_fibonacci_recursion(int n)//function definition
{
    if ( n == 0 || n == 1 )//if n is 0 or 1
        return n;
    else
            return pos_fibonacci_recursion(n-1) + pos_fibonacci_recursion(n-2);//calling recursively
    return 0;
}
int neg_fibonacci_recursion(int n)//function definitiion
{
    if ( n == 0 || n == 1 )//if n is 0 or 1
        return n;
    else
        return neg_fibonacci_recursion(n-2) - neg_fibonacci_recursion(n-1);//calling recursively
    return 0;
}
