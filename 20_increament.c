/*Documentation
  Name        : Hargovind Singh
  Date        : 25-07-2020
  Description : WAF for pre and post increament and passing int pointer as their parameter
  Input       :
  Output      :
*/
#include<stdio.h>
int pre_increament(int*);//function prototype
int post_increament(int*);//function prototype
int main()
{
    char choice = 'n';//variable to store the choice of user for continue 
    do
    {
        int num;//variable to store number
        int return_value;//variable to store return value from function call
        int option;//variable to select the choice user selected
        printf("Enter the value of number : ");
        scanf("%d",&num);//reading number from user
        printf("Enter the operation :\n1. Pre-Increament\n2. Post-Increament\nChoice : ");
        scanf("%d",&option);//reading option(pre or post increament)
        switch ( option )
        {
            case 1:
                return_value = pre_increament(&num);//calling function
                printf("return_value = %d\nnum = %d\n",return_value,num);
                break;
            case 2:
                return_value = post_increament(&num);//calling function
                printf("return_value = %d\nnum = %d\n",return_value,num);
                break;
            default:
                printf("please enter valid choice\n");
        }
        printf("Want to continue[y/n] :");
        scanf("\n%c",&choice);//reading choice to continue option
    }while(choice == 'y');//checking codition for continue
    return 0;
}
int pre_increament(int* num_add)//function definition
{
    //*num_add = -(~(*num_add));//.........compliment and then negative
    
    int count = 0;//to count the no of shift
    if ((*num_add & 1) == 1)//checking that number is 0 or not
    {
        while((*num_add & 1) != 0)//loop for checking lsb's bit by bit
        {
            *num_add = *num_add >> 1;
            count |= 1;//increamenting the count
        }
    }
    *num_add |= 1;//adding one
    *num_add <<= count;//left shift operation*/
    return *num_add;
}
int post_increament(int* num_add)//function definition
{
    int temp = *num_add, count = 0;//temp variable for storing original(entered value by user)
    if ((*num_add & 1) == 1)//checking that the number is 0 or not
    {
        while ((*num_add & 1) != 0)//loop for checking lsb's bit by bit
        {
            *num_add = *num_add >> 1;
            count |= 1;//INC
        }
    }
    *num_add |= 1;//adding one
    *num_add <<= count;//left shift operation
    return temp;//returning original or previous or user entered value
}
