/*Documentation
  Name        : Hargovind Singh
  Date        : 16-0-2020
  Description : WAP to find the product of given matrix.
  Input       :
  Output      :
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
    char choice; //for user prompt
    do
    {
        int row, col;//no. of rows and columns
        printf("Enter number of rows: ");
        scanf("%d",&row);//reading rows
        printf("Enter number of column: ");
        scanf("%d",&col);////reading columns

        int **array;
        array = malloc(row*sizeof(int*));
        for(int i = 0; i < row; i++)
            array[i] = malloc(col*sizeof(int));
        //reading elements of array
        printf("Enter values of matrix: \n");
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
                scanf("%d",&array[i][j]);
        }
        for (int i = 0; i < row; i++)//printing matrix
        {
            for (int j = 0; j < col; j++)
            {
                printf("%d ",array[i][j]);
            }
            printf("\n");
        }

        //creating transpose
        int **array_trans;
        array_trans = malloc(col*sizeof(int*));
        for (int i = 0; i < col; i++)
            array_trans[i] = malloc(row*sizeof(int));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
                array_trans[j][i] = array[i][j];
        }
        printf("Transpose of given matrix: \n");//printing matrix
        for (int i = 0; i < col; i++)
        {
            for (int j = 0; j < row; j++)
                printf("%d ",array_trans[i][j]);
            printf("\n");
        }

        //logic for multiplicaton
        int **prod_array;
        prod_array = malloc(row*sizeof(int));
        for (int i = 0; i < row; i++)
            prod_array[i] = malloc(row*sizeof(int));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                for (int k = 0; k < col; k++)
                    prod_array[i][j] += array[i][k] * array_trans[k][j]; 
            }
        }
        printf("Product of matrix: \n");//printing matrix
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < row; j++)
                printf("%d ",prod_array[i][j]);
            printf("\n");
        }
        printf("Want to continue[y/n]: ");
        scanf("\n%c",&choice);
    }while(choice == 'y');
    return 0;
}

