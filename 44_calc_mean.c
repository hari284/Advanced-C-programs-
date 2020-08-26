/*Documentation
Name        : Hargovind Singh
Date        : 19-08-2020
Description : Implement calc_mean for all data types
Input       : 1 2 3 4 5
Output      : 3.00
 */
#include<stdio.h>
#include<stdlib.h>
double cal_mean(void *arr, int size,int option);//function prototype
int main()
{
    char choice;//for user prompt
    do
    {
        void *arr;//void pointer
        int size,option;//size and user choice for datatypes
        double mean;//variable to store returnvalue from functioncal_mean()
        printf("enter the size of array: ");
        scanf("%d",&size);//reading size
        printf("1.int\n2.short\n3.float\n4.double\nenter the choice: ");
        scanf("%d",&option);//reading option
        switch(option)
        {
            case 1:
                arr = malloc(size*sizeof(int));//allocating memory
                printf("enter %d elements:",size);
                for (int i = 0; i < size; i++)
                {
                    scanf("%d",(int *)arr+i);//reading elements
                }
                break;
            case 2:
                arr = malloc(size*sizeof(short));//allocating memory
                printf("enter %d elements:",size);
                for (int i = 0; i < size; i++)
                {
                    scanf("%hd",(short *)arr+i);//reading elements
                }
                break;
            case 3:
                arr = malloc(size*sizeof(float));//allocating memory
                printf("enter %d elements:",size);
                for (int i = 0; i < size; i++)
                {
                    scanf("%f",(float *)arr+i);//reading elements
                }
                break;
            case 4:
                arr = malloc(size*sizeof(double));//allocating memory
                printf("enter %d elements:",size);
                for (int i = 0; i < size; i++)
                {
                    scanf("%lf",(double *)arr+i);//reading elements
                }
                break;
            default:
                printf("please enter valid choice:\n");
                goto level;
        }
        mean = cal_mean(arr, size, option);//calling function
        printf("the mean value is %.2lf\n",mean);
        free(arr);//freeing memory
        level:
        printf("Want to continue[y/n]: ");
        scanf("\n%c",&choice);
    }while(choice == 'y');
    return 0;
}
double cal_mean(void *arr, int size,int option)//function definition
{
    //local variable decleration
    double mean,sum;
    switch(option)
    {
        case 1:
            for(int i = 0; i < size; i++)
            {
                sum += *((int *)arr+i);//calculating sum
            }
            mean = sum/size;
            return mean;
        case 2:
            for(int i = 0; i < size; i++)
            {
                sum += *((short *)arr+i);//calculating sum
            }
            mean = sum/size;
            return mean;
        case 3:
            for(int i = 0; i < size; i++)
            {
                sum += *((float *)arr+i);//calculating sum
            }
            mean = sum/size;
            return mean;
        case 4:
            for(int i = 0; i < size; i++)
            {
                sum += *((double *)arr+i);//calculating sum
            }
            mean = sum/size;
            return mean;
        default:
        printf("No valid data type");
    }
    return -1;
}