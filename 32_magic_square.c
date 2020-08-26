/*Documentation
Name        : Hargovind Singh
Date        : 20-08-2020
Description : WAP to generate a n*n magic square (n is odd +ve no.)
Input       : 
Output      : 
 */
#include<stdio.h>
#include<stdlib.h>
void magic_square(int *a[],int size);//function prototype
int main()
{
    char choice;//for user prompt
    do
    {
        int size;//size 
        printf("enter the size of array: ");
        scanf("%d",&size);//reading size
        if (size > 1 && size%2 == 1)//checking for odd and positive size
        {
            int *arr[size];//declaring array
            for (int i = 0; i < size; i++)
            {
                arr[i] = malloc(size*sizeof(int));//allocating column memory dynamically for each row
            }
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    arr[i][j] = 0;//making every element of matrix 0
                }
            }
            magic_square(arr,size);//calling function
            for (int i =0 ; i < size; i++)
            {
                free(arr[i]); //freeing memory
            }
        }
        else
        {
            printf("Enter an odd positive number\n");
        } 
            
        printf("Want to continue[y/n]: ");
        scanf("\n%c",&choice);
    }while(choice == 'y');
    return 0;
}
void magic_square(int *arr[],int size)//function definition
{
   int row = 0, col = size/2, temp_r, temp_c;//local variable
    for (int i = 0; i < size*size; i++)//logic
    {
        arr[row][col] = i+1;
        if (row == 0)
        {
            temp_r = row;
            row = size-1;
        }
        else
        {
            temp_r = row;
            row = row - 1;
        }
        if (col == size - 1)
        {
            temp_c = col;
            col = 0;
        }
        else
        {
            temp_c = col;
            col = col + 1;
        }
        if (arr[row][col] != 0)
        {
            col = temp_c;
            row = temp_r + 1;
        }
    }
    //for printing the magic square of size*size
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
}