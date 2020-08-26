/*Documentation
  Name        : Hargovind Singh
  Date        : 10-08-2020
  Description : Print bits of float and double
  Input       : 
  Output      :
*/
#include<stdio.h>
void print_bits(int ch, void *ptr);//function prototype
int main()
{
    char choice;//for user prompt
    do
    {
        int option;//for user choice
        printf("Enter the choice:\n1.float\n2.double\nchoice: ");
        scanf("%d",&option);//reading user choice
        float f_value;//variable for float value
        double d_value;//variable for double value
        switch( option )
        {
            case 1:
                printf("Enter float value: ");
                scanf("%f",&f_value);//reading float value
                print_bits(option, (int *)&f_value);//calling function
                break;
            case 2:
                printf("Enter double value: ");
                scanf("%le",&d_value);//reading double value
                print_bits(option, (long int*)&d_value);//calling function
                break;
            default:
                printf("Enter the valid choice\n");
        }
        printf("Want to continue[y/n]: ");
        scanf("\n%c",&choice);
    }while(choice == 'y');
    return 0;
}
void print_bits(int ch, void *ptr)//function definition
{
    int count = 0;//counter
    printf("sign\texponent\tmantissa\n----------------------------------------------------------\n");
    if (ch == 1)
    {
        //...since float is of 4 byte == 32 bit....
        for (int i = 0; i < 32; i++)
        {
            printf("%d",(*(int *)ptr >> (31 - i)) & 1);//printing bits
            count++;
            if (count == 1 || count == 9)
                printf("\t");
        }
    }
    else
    {
        for (int i = 0; i < 64; i++)//since double is of 8 byte == 64 bit...
        {
            printf("%ld",(*(long int *)ptr >> (63 - i)) & 1);//printing bits
            count++;
            if (count == 1 || count == 12)
                printf("\t");
        }
    }
    printf("\n");
}

