/*Documentation
Name        : Hargovind Singh
Date        : 22-07-2020
Description : Read an integer(num) and a number(n) then do circular left & right shift by n
Input       :
Output      :
 */
#include<stdio.h>
#define INT_BITS 32//macro ... for no of bits representation....here 32 bit representation
int circular_right_shift(int, unsigned int);//function signature...second parameter will always be +ve
int circular_left_shift(int, unsigned int);//function signature...unsigned becouse its always gonna positive
int main()
{
    char choice = 'n';//variable to store user responce whether he/she wants to continue or not
    do
    {   
        int num, option;//num variable is to store number, option is to take choice from user about shift
        unsigned int n;//variable to store the shift value
        printf("Enter num : ");
        scanf("%d",&num);//reading number
        printf("Enter n : ");
        scanf("%d",&n);//reading shift value
        if (choice == 'n')
        {
            printf("Possible operations\n1.Circular right shift\n2.Circular left shift\n");
        }
        printf("Enter your choice : ");
        scanf("%d",&option);//reading user option
        printf("The binary form of number : ");
        for (int ind = 0; ind < INT_BITS; ind++)//loop to print binary form of number
        {
            if ( ind != 0 && ind%8 == 0 )//condition to put space between each 8 bits in whole 32 bits
                printf(" ");//11001100 11111111 ...like wise space after each byte
            printf("%d",(num >> (INT_BITS - 1 - ind)) & 1);
        }
        switch( option )
        {
            case 1:
                printf("\nAfter circular right shift by %d\nThe binary form of number : ",n);
                num = circular_right_shift( num, n );           //function calling
                for (int ind = 0; ind < INT_BITS; ind++)//printing binary form of num
                {
                    if ( ind != 0 && ind%8 == 0 )//for put space after each byte
                        printf(" ");
                    printf("%d",(num >> (INT_BITS - 1 - ind)) & 1);
                }
                break;
            case 2:
                printf("\nAfter circular left shift by %d\nThe binary form of number : ",n);
                num = circular_left_shift( num, n );//function calling
                for (int ind = 0; ind < INT_BITS; ind++)//loop to print binary form of number
                {
                    if ( ind != 0 && ind%8 == 0 )//to put space after each byte
                        printf(" ");
                    printf("%d",(num >> (INT_BITS - 1 - ind)) & 1);
                }
                break;
            default:
                printf("Please enter valid choice");
        }
        printf("\nWant to continue[yY/nN]");
        scanf("\n%c",&choice);
    }while(choice == 'y' || choice == 'Y');//checking for continuation of loop
    return 0;
}
int circular_right_shift(int num, unsigned int rotation)//function definition
{
    rotation %= (INT_BITS - 1);//if rotation is greater than 31 then that is equal to  rotation - 31
    while ( rotation-- )
    {
        num = ((num >> 1) & (~(1 << (INT_BITS - 1))) | ((num & 1) << (INT_BITS - 1)));//performing circular right shift
    }
    return num;
}
int circular_left_shift(int num, unsigned int rotation)//function definition
{
    rotation %= (INT_BITS - 1);//if rotation > 31 then rotation = rotation - 31
    while ( rotation-- )
    {
        num = (num << 1) | ((num >> (INT_BITS - 1)) & 1);//performing circular left shift
    }
    return num;
}
