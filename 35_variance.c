/*Documentation
  Name        : Hargovind Singh
  Date        : 11-08-2020
  Description : WAP to find the variance 
  Input       :
  Output      :
*/
#include<stdio.h>
#include<stdlib.h>
void variance(int *arr, int size);//prototype
int main()
{
    char choice;//for user prompt
    do
    {
        int option;//for selection
        printf("Enter choice:\n1.static memory allocation\n2.dynamic memory allocation\nchoice: ");
        scanf("%d",&option);
        if (option == 1)//static allocation
        {
            int static_array[10];
            printf("Enter 10 elements:\n"); 
            for (int i = 0; i < 10; i++)
                scanf("%d",static_array+i);//reading elements
            variance(static_array, 10);//calling function
        }
        else
        {
            if (option == 2)//dynamic allocation
            {
                int *dynamic_array,size;
                printf("Enter the size of array: ");
                scanf("%d",&size);
                dynamic_array = calloc(size,1);//memory allocation
                if (dynamic_array != NULL)//validation for memory allocation
                {
                    printf("Enter the %d elements:\n ",size);
                    for (int i = 0; i < size; i++)
                        scanf("%d",dynamic_array+i);//reading elements
                    variance(dynamic_array, size);//calling function
                    free(dynamic_array);//freeing the memory
                }
                else
                {
                    printf("memory allocation failed!\n");
                }
            }
            else
                printf("Please enter valid choice\n");
        }
        printf("Want to continue[y/n]: ");
        getchar();
        scanf("\n%c",&choice);//condition for continuity of programm
    }while(choice == 'y');
    return 0;
}
void variance(int *arr,int size)//function definition
{
    int deviation[size], variance[size],mean,sigma_variance, sum = 0;//variable decleration
    for (int i = 0; i < size; i++)//to calculate mean
    {
        sum += arr[i];
    }
    mean = (float)sum/size;
    sum = 0;
    printf("X(Input)\tD = X - mean\tD^2\n");
    for (int i = 0; i < size; i++)//to calculate elements of deviation and variance array one by one
    {
        deviation[i] = arr[i] - mean;
        variance[i] = deviation[i]*deviation[i];
        sum += variance[i];
        printf("%d\t\t%d\t\t%d\n",arr[i],deviation[i],variance[i]);
    }
    sigma_variance = (float)sum/size;
    printf("\nvariance of entered numbers is:%d\n",sigma_variance);
}

