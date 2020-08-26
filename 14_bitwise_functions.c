/*Documentation
Name        : Haegovind Singh
Date        : 20-07-2020
Description : Wap to implement bitwise functions
Input       : 
Output      :
 */
#include<stdio.h>
int get_nbits(int num, int n);//get_nbits() signature
int replace_nbits(int num, int n, int val);//replace_nbits() signature
int get_nbits_from_pos(int num, int n, int pos);//function signature
int replace_nbits_from_pos(int num, int n, int pos, int val);//function signature
int toggle_bits_from_pos(int num, int n, int pos);//function signature
int print_bits(unsigned int num, int n);//function signature
int main()
{
    //num is the number, n is the no_of_bits,
    // val is the value from which we extract n bits and pos is start position from where we will take the n bits. 
    int choice, num, no_of_bits, value, pos, decimal_value;
    char opinion;
    printf("Select bit operation from below list\n1.get_nbits\n2.set_nbits\n3.get_nbits_from_pos\n");//displaying the options to user
    printf("4.set_nbits_from_pos\n5.toggle_bits_from_pos\n6.print_bits\n");
    do
    {
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch( choice )
        {
            case 1:
                printf("Enter num : ");
                scanf("%d",&num);//reading number
                printf("Enter no_of_bits : ");
                scanf("%d",&no_of_bits);//reading no of bits
                decimal_value = get_nbits(num, no_of_bits);//calling get_nbits()
                printf("%d bits of %d->%d\n",no_of_bits,num,decimal_value);
                break;
            case 2:
                printf("Enter num : ");
                scanf("%d",&num);//reading number
                printf("Enter no_of_bits : ");
                scanf("%d",&no_of_bits);//reading no_of_bits
                printf("Enter value : ");
                scanf("%d",&value);//reading value
                decimal_value = replace_nbits(num, no_of_bits, value);//calling replace_nbits()
                printf("replace at %d[%dbits]->%d\n",num,no_of_bits,decimal_value);
                break;
            case 3:
                printf("Enter num : ");
                scanf("%d",&num);//reading number
                printf("Enter no_of_bits : ");
                scanf("%d",&no_of_bits);//reading no of bits
                printf("Enter position : ");
                scanf("%d",&pos);//reading position..where to start
                decimal_value = get_nbits_from_pos(num, no_of_bits, pos);//calling function
                printf("value at %d[%d:%d]->%d\n",num,pos,no_of_bits,decimal_value);
                break;
            case 4:
                printf("Enter num : ");
                scanf("%d",&num);//reading number
                printf("Enter no_of_bits : ");
                scanf("%d",&no_of_bits);//reading no_of_bits
                printf("Enter position : ");
                scanf("%d",&pos);//reading position
                printf("Enter value : ");
                scanf("%d",&value);//reading value
                decimal_value = replace_nbits_from_pos(num, no_of_bits, pos, value);//calling function
                printf("replace at%d[%d:%d]->%d\n",num,pos,no_of_bits,decimal_value);
                break;
            case 5:
                printf("Enter num : ");
                scanf("%d",&num);//reading number
                printf("Enter no_of_bits : ");
                scanf("%d",&no_of_bits);//reading number of bits to be toggle
                printf("Enter position : ");
                scanf("%d",&pos);//reading position
                decimal_value = toggle_bits_from_pos(num, no_of_bits, pos);//calling function
                printf("toogled at %d[%d:%d]->%d\n",num,pos,no_of_bits,decimal_value);
                break;
            case 6:
                printf("Enter num : ");
                scanf("%d",&num);//reading number
                printf("Enter no_of_bits : ");
                scanf("%d",&no_of_bits);//reading no_of_bits
                if (no_of_bits > sizeof(int)*8)
                    no_of_bits = sizeof(int)*8;
                print_bits(num, no_of_bits);//calling function
                break;
            default:
                printf("Please enter valid choice\n");
        }
        printf("Do you like to continue [yY/nN] : ");
        scanf("\n%c",&opinion);
    }while(opinion == 'y' || opinion == 'Y');    
    return 0;
}

int get_nbits(int num, int n)//get_nbits(int, int) definition
{
    // mask = ((1 << n) - 1)
    return num & ((1 << n) - 1);
}

int replace_nbits(int num, int n, int val)//replace_nbits(int, int, int) definition
{
    // mask for val ==  ( 1 << n ) - 1
    val &= ((1 << n) - 1);
    //mask for num == ~(( 1 << n ) - 1)
    num &= ~(( 1 << n ) - 1);
    return num | val;
}

int get_nbits_from_pos(int num, int n, int pos)//function definition
{
    // mask = ((1 << n) - 1) << (pos - n + 1);
    return (num & (((1 << n) - 1) << (pos -n + 1))) >> (pos - n + 1);
}

int replace_nbits_from_pos(int num, int n, int pos, int val)//function definition
{
    //mask for val = ((1 << n) - 1)
    val = (val & ((1 << n) - 1)) << (pos - n + 1);
    // mask for num = ~(((1 << n) - 1) << (pos - n + 1)) 
    num &= ~(((1 << n) - 1) << (pos - n + 1));
    return num | val;
}
//toggling bits function
int toggle_bits_from_pos(int num, int n, int pos)//definition of function
{
    int mask = num & (((1 << n) - 1) << (pos - n + 1));//creating mask
    num ^= mask;//taking xor of mask with num
    mask = ~(mask >> (pos - n + 1)) << (pos - n + 1);
    mask &= (((1 << n) - 1) << (pos - n + 1));
    return num | mask;
}
//printing bits function
int print_bits(unsigned int num, int n)//function definition
{
    printf("%d->",num);
    for (int i = 0; i < n; i++)//iterating for n times == no_of_bits
    { 
        printf("%d ",(num >> (n - 1 - i)) & 1);//ptinting bits one by one
    }
    return 0;
}
