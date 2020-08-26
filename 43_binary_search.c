/*Documentation
Name        : Hargovind Singh
Date        : 12-08-2020
Description : WAP to perform binary search on all data types
Input       :
Output      :
 */
#include<stdio.h>
#include<stdlib.h>
int binary_search(void *, int, int, int);
int main()
{
    char choice;
    do
    {
        int size,key,option;
        printf("Enter key element:\n");
        scanf("%d",&key);
        void *array;
        printf("Enter the size of an array: ");
        scanf("%d",&size);
        printf("Menu:\n1.int\n2.char\n3.float\n4.double\nchoice: ");
        scanf("%d",&option);
        switch (option)
        {
            case 1:
                printf("Enter %d elements of type int\n",size);
                array = (int *)calloc(size,sizeof(int));
                if (array != NULL)
                {
                    for (int i = 0; i < size; i++)
                        scanf("%d",(int *)(array+i));
                    for (int i =0; i < size; i++)
                    {
                        for (int j = 0; j < size; j++)
                        {
                            if (*((int *)(array+j)) < *((int *)(array+i)))
                            {
                                int temp = array[i];
                                array[i] = array[j];
                                array[j] = temp;
                            }
                        }
                    }
                    binary_search(array,0,size,key);
                }
                else
                    printf("Memory allocation failure\n");
                break;
            case 2:
                printf("Enter %d elements of type char\n",size);
                array = (char *)calloc(size,sizeof(char));
                if (array !=NULL)
                {
                    for (int i = 0; i < size; i++)
                        scanf("%c",(char *)array+i);
                    for (int i =0; i < size; i++)
                    {
                        for (int j = 0; j < size; j++)
                        {
                            if (array[j] < array[i])
                            {
                                char temp = array[i];
                                array[i] = array[j];
                                array[j] = temp;
                            }
                        }
                    }
                    binary_search(array,0,size,key);
                }
                else
                    printf("Memory allocation failure\n");
                break;
            case 3:
                printf("Enter %d elements of type float\n",size);
                array = (float *)calloc(size,sizeof(float));
                if (array != NULL)
                {
                    for (int i = 0; i < size; i++)
                        scanf("%f",(float *)array+i);
                    for (int i = 0; i < size; i++)
                    {
                        for (int j = 0; j < size; j++)
                        {
                            if (array[j] < array[i])
                            {
                                float temp = array[i];
                                array[i] = array[j];
                                array[j] = temp;
                            }
                        }
                    }
                    binary_search(array,0,size,key);
                }
                else
                    printf("Meomory allocation failure\n");
                break;
            case 4:
                printf("Enter %d elements of type double\n");
                array = (double *)calloc(size,sizeof(double));
                if (array !=NULL)
                {
                    for (int i = 0; i < size; i++)
                        scanf("%ld",(double *)array+i);
                    for (int i =0; i < size; i++)
                    {
                        for (int j = 0; j < size; j++)
                        {
                            if (array[j] < array[i])
                            {
                                double temp = array[i];
                                array[i] = array[j];
                                array[j] = array[i];
                            }
                        }
                    }
                    binary_search(array,0,size,key);
                }
                else
                    printf("Memory allocation failure\n");
                break;
            default:
                printf("Please enter valid choice\n");
            }
        }
        printf("Want to continue[y/n]: ");
        scanf("\n%c",&choice);
    }while(choice == 'y');
    return 0;
}
int binary_search(void *array,int start,int end,int key)
{
    int mid = (start+end)/2;
    for (int i = start; i < end; i++)
    {
        if (key == array[mid])
            printf("search element %d is at position %d of array\n",key,mid);
        else
        {
            if (key < array[mid])
                return binary_search(array,start,--end,key);
            else
                return binary_search(array,++start,end,key);
        }
    }
    return 0;
}
