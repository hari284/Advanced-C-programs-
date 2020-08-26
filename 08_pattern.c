/*Documentation
Name        : Hargovind Singh
Date        : 17-07-2020
Description : WAP to print Hello in X pattern
Input       : 
Output      :
 */
#include<stdio.h>
#include<math.h>
int main()
{
    char choice;
    do
    {
        int lines;//variable to store number of lines
        printf("Enter a number lines: ");
        scanf("%d",&lines);//reading no of lines
        if(lines > 2 && lines < (int)pow(2,5))//checking for limit...N < 2^5 and greater than 1
        {
            for(int i = 0; i < lines ; i++)//loop for row
            {
                for(int j = 0; j < lines; j++)//loop for columns
                {
                    if(lines%2 != 0)//checking for odd no of lines
                    {
                        if(i == lines/2)//in the mid line
                        {
                            if(i == j)
                                printf("HelloHello");//priting in middle line
                            else
                            {
                                if(i+j == lines-2 || i+j == lines)//checking for previous and jst ahead element of middle element of middle line
                                    printf(" ");
                                else
                                    printf("  ");
                            }
                        }
                        else
                        {
                            if(i == j || j == (lines-1-i))//other than middle line ..it is same for both odd and even no of lines
                                printf("Hello");
                            else 
                                printf("  ");

                        }
                    }
                    else
                    {
                        if(i == j || j == (lines-1-i))//for even no of lines
                            printf("Hello");
                        else
                            printf("  ");
                    }
                }
                printf("\n");
            }
        }
        else
            printf("Invalid input");
        printf("Want to continue[y/n]: ");
        scanf("\n%c",&choice);
    }while(choice == 'y');
    return 0;
}

