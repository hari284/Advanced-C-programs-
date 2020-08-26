/*Documentation
Name        : Hargovind Singh 
Date        : 6-8-2020
Description : wap to print sorted values of float array without modifying the array
Input       :
Output      :
 */
#include<stdio.h>
void print_elements_asc(float *array,int size);//function prototype
int main()
{
    char choice;//for user prompt
    do
    {
        int size;//array size
        printf("Enter the count of float elements need to store:  ");
        scanf("%d",&size);//reading size
        float store[size];//decleration of array
        for (int i = 0; i < size; i++)
        {
            scanf("%f",&store[i]);//reading array elements
        }
        print_elements_asc(store,size);//calling function
        printf("\nWant to continue[y/n]: ");
        scanf("\n%c",&choice);
    }while(choice == 'y');
    return 0;
}
void print_elements_asc(float *array,int size)//function definition
{
    float min2, min1 = array[0], max = array[0];//variable decleration
    for (int i = 1 ;i < size; i++)//calculating minimum of elements
    {
        if (array[i] < min1)
            min1 = array[i];
    }
    printf("After sorting: %.2f ",min1);//printing first minimum element
    for (int i = 0; i< size; i++)//calculating maximum element of all
    {
        if (array[i] > max)
            max = array[i];
    }
    for (int i = 0; i < size-1; i++)
    {
        min2 = max;
        for (int j = 0; j < size; j++)
        {
            if (array[j] <= min2 && array[j] != min1 && array[j] > min1)
            {
                min2 = array[j];
            }
        }
        printf("%.2f ",min2);//printing in ascending order
        min1 = min2;

    }
}
