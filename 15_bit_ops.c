/*Documentation
Name        : Hargovind Singh
Date        : 21-07-2020
Description : Replace n bits of a number from bits of another number from given position
Input       :
Output      :
 */
#include<stdio.h>
int set_nbits_from_pos(int ,int , int, int);//function signature
int main()
{
    char choice;//variable for choice of user whether he wamts to continue or not
    do
    {
        int num, val, lower_pos, upper_pos;
        printf("Enter the value of 'Val' : ");
        scanf("%d",&val);//reading value / number from which we will take last some bits 
        printf("Enter the value of 'num' : ");
        scanf("%d",&num);//reading number of which we are going to replace bits
        printf("Enter the value of 'lower_pos' : ");
        scanf("%d",&lower_pos);//lower-position
        if (lower_pos > 0 && lower_pos < 31)//checking whether it is in range or not
        {
            printf("Enter the value of 'upper_pos' : ");
            scanf("%d",&upper_pos);//reading upper_position
            if (upper_pos <= 0 && upper_pos >= 31)//checking whether it is in range or not
            {
                printf("Please enter valid value of upper limit");
                goto last;
            }
            else
            {
                printf("The binary form of 'val' : ");
                for (int ind = 0; ind < 32; ind++)
                {
                    printf("%d ",(val >> (31 - ind)) & 1);//printing msb bits one by one of val
                }
                printf("\n");
                printf("The binary form of 'num' : ");
                for (int ind = 0; ind < 32; ind++)
                {
                    printf("%d ",(num >> (31 - ind)) & 1);//printing msb bits of num one by one
                }
                printf("\n");
                num = set_nbits_from_pos(num, upper_pos-lower_pos+1, upper_pos, val);//function calling
                printf("The new binary form of 'num' : ");
                for (int ind = 0; ind < 32; ind++)
                {
                    printf("%d ",(num >> (31 - ind)) & 1);//printing msb bits of new number one by one
                }
                printf("\n");
            }
        }
        else
        {
            printf("Please enter valid value of position");
            goto last;
        }
last:
        printf("Do you want to continue[yY/nN] : ");
        scanf("\n%c",&choice);//reading choice
    }while(choice == 'y' || choice == 'Y');
    return 0;
}

int set_nbits_from_pos(int num, int no_of_bits, int upper_pos, int val)//function definition
{
    val = (val & ((1 << no_of_bits) - 1)) << (upper_pos - no_of_bits + 1);//getting mask from val
    num ^= num & (((1 << no_of_bits) - 1) << (upper_pos - no_of_bits + 1));//doing xor operation with masked num and num
    return num | val;
}
