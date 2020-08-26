/*Documentation
Name        : Hargovind Singh
Date        : 18-07-2020
Description : WAP to find the median of two unsorted array.
Input       :
Output      :
 */
#include<stdio.h>//library for printf() and scanf()
int main()
{
    char choice;
    do
    {
        int size;// variable to store sizes of arrays
        printf("Enter the size value for array A: ");
        scanf("%d",&size);//size for first array_A
        if(size > 10)//checking whether size is below or above 10
        {
            printf("Max array elements exceeded");
            return 0;
        }
        else
        {
            int array[size];//array having no of elements == size
            printf("Enter the elements one by one for array A: ");
            for (int i = 0; i < size; i++)//loop for reading array elements one by one
            {
                scanf("%d",&array[i]);//reading elements
            }
            for (int i = 0; i < size-1; i++)//outer loop for sorting
            {
                for (int j = i+1; j < size ; j++)//inner loop for sorting
                {
                    if(array[i] > array[j])//logic for swaping
                    {
                        int temp = array[i];
                        array[i] = array[j];
                        array[j] = temp;
                    }
                }
            }
            printf("After sorting: ");
            for (int i = 0; i < size ; i++)//loop for printing the sorted elements of array_A
            {
                printf("%d ",array[i]);
            }
            float median_A;//variable to store median of array_A
            if (size%2 == 0)//for even no of elements
            {
                median_A = (float)(array[size/2] + array[size/2-1])/2;
            }
            else//odd no of elements
                median_A = array[size/2];
            printf("\nMedian of arrayA is : %g\n",median_A);//printing median of array_A

            //repeating the code for array_B
            for (int i = 0; i < size; i++)//loop for making all elements of array 0(zero)..to avoid any garvage value
            {
                array[i] = 0;
            }
            size = 0;//assigning 0 to avoid any garvage
            printf("Enter the size value for array B: ");
            scanf("%d",&size);//reading size for array_B
            if (size > 10)//checking with the limit
            {
                printf("Max array elements exceeded");
                return 0;
            }
            else
            {
                printf("Enter the element one by one for array B: ");
                for (int i = 0; i < size; i++)
                {
                    scanf("%d",&array[i]);//reading elements for array_B one by one
                }
                for (int i = 0; i < size-1; i++)//outer loop for sorting
                {
                    for (int j = i+1; j < size; j++)//inner loop for sorting
                    {
                        if (array[i] > array[j])//swaping logic
                        {
                            int temp = array[i];
                            array[i] = array[j];
                            array[j] = temp;
                        }
                    }
                }
                printf("After sorting: ");
                for (int i = 0; i < size; i++)
                {
                    printf("%d ",array[i]);//printing sorted elements one by one of array_B
                }
                float median_B;//variable to store median of array_B
                if (size%2 == 0)//for even size
                    median_B = (float)(array[size/2] + array[size/2-1])/2;
                else
                    median_B = array[size/2];//for odd size
                printf("\nMedian of arrayB is : %g\n",median_B);//printing median of array_B
                printf("Median of both arrays : %g\n",(median_A + median_B)/2);//printing median of both array(A+B)
            }

        }
        printf("Want to continue[y/n]: ");
        scanf("\n%c",&choice);
    }while(choice == 'y');
    return 0;
}

