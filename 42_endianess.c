/*Documentation
  Name        : Hargovind Singh
  Date        : 1 Aug 2020
  Description : WAP to find the endianess of system
  Input       : 1245
  Output      : Little Endian System
*/
#include<stdio.h>
int main()
{
    unsigned int number;//variable to store value
    unsigned char *cptr;//character pointer to access only one byte from given address
    printf("Please enter a integer value: ");
    scanf("%d",&number);//reading number
    cptr = (char*)&number;//giving address of integer to cptr
    int LSB_VAL = number & 0x00ff;//LSB byte of number

    if (*cptr == LSB_VAL)//comparing LSB byte with *cptr(base address)
        printf("Little Endian System\n");
    else
        printf("Big Endian System\n");

    return 0;
}

