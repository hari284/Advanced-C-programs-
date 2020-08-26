/*Documentation
  Name        : Hargovind Singh
  Date        : 25-07-2020
  Description : WAP to swap two variables by using pass by refrence method
  Input       :
  Output      :
*/
#include<stdio.h>
void swap(int*, int*);//function prototype
int main()
{
    char choice;//variable to store the choice of user whether user want to continue or not
    do
    {
        int Num1, Num2;
        printf("Enter Num1 : ");
        scanf("%d",&Num1);//reading number1
        printf("Enter Num2 : ");
        scanf("%d",&Num2);//reading number2

        swap(&Num1, &Num2);//calling function

        printf("After swapping,\n");
        printf("Num1 = %d\nNum2 = %d",Num1,Num2);//printing numbers after swapping
        printf("\nWant to continue[y/n]: ");
        scanf("\n%c",&choice);//asking to continue
    }while(choice == 'y');//checkig condition to continue the loop
    return 0;
}
void swap(int *num1, int *num2)//function definition
{
    *num1 = *num1 ^ *num2;//xor operation between num1 and num2
    *num2 = *num2 ^ *num1;//xor between num2 and num1
    *num1 = *num1 ^ *num2;//xor between num1 and num2
}

    

