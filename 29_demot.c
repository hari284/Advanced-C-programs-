/*Documentation
  Name        : Hargovind Singh
  Date        : 10-08-2020
  Description : WAP to demote the type of given float number to integer using
              :bitwise operators and bitfields.
  Input       : 
  Output      :
*/
#include<stdio.h>
float get_nbits_from_pos(void *ptr, int n, int pos);//function prototype
float convert(int x);//function prototype
int main()
{
    char choice;//for user prompt
    do
    {
        float f_value;//variable for float value
        int temp;
        printf("enter any float value:");
        scanf("%f",&f_value);
        int n = get_nbits_from_pos((int*)&f_value, 8, 30);//fetching exponent bits
        n = n - 127;
        temp = 1 << n;
        if (n < 0)//if n-127 < 0 means int value is 0
        {
          n = 0;
        }
        else
        {
          n = get_nbits_from_pos((int*)&f_value, n, 22);//fetching n bits of mantissa
          if (f_value < 0)//if number is negative
          {
            n |= temp;
            n = -(n);
          }
          else
          {
            n |= temp;
          }
        }
        printf("Demoted value is %f",convert(n));//printing
        printf("\nWant to continue[y/n]: ");
        scanf("\n%c",&choice);
    }while(choice == 'y');
    return 0;
}
float get_nbits_from_pos(void *ptr, int n, int pos)//function definition
{
    // mask = ((1 << n) - 1) << (pos - n + 1);
    return (*(int*)ptr & (((1 << n) - 1) << (pos -n + 1))) >> (pos - n + 1);
}
float convert(int x)//function to convert int to float
{
    return x;
}
