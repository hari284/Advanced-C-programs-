/*Documentation
Name        : Hagovind Singh
Date        : 16-07-2020
Description : WAP to read 3 numbers a,r,n. generate AP, GP, HP
Input       :  
Output      :
 */
#include<stdio.h>
#include<math.h>
int main()
{
    char choice;
    do
    {
        int A,R,N;//A->first term, R->common diff for AP AND HP, R-> common ratio for GP, N->no of terms
        printf("Enter the first number 'A':");
        scanf("%d",&A);//reading first term
        printf("Enter the common difference/Ratio 'R':");
        scanf("%d",&R);//reading common diff/ratio
        printf("Enter the number of terms 'N':");
        scanf("%d",&N);//reading number of terms

        if ((A > 0 && R > 0) && N > 0)//checking whether inputs are positive or not
        {
            if ((A < (int)pow(2,10) && R < (int)pow(2,10)) && N < (int)pow(2,10))//checking whether numbers are less than 2^10
            {
                printf("AP = %d",A);//reducing number of iteration by 1
                for( int i = 2; i <= N; i++ )//loop to print AP
                {
                    int AP_term = A + (i-1)*R;
                    printf(", %d",AP_term);
                }
                printf("\nGP = %d",A);//reducing number of iteration by 1
                for( int i = 2; i <= N; i++ )//loop for GP, while compiling this .c file we need to add -lm command lile gcc ...c -lm
                {//becoz we are providing variable to pow()
                    int GP_term = A*pow(R,i-1);
                    printf(", %d",GP_term);
                }
                printf("\nHP = %f",(float)1/A);//reducing number of iteration by 1
                for( int i = 2; i <= N; i++ )//loop for HP
                {
                    float HP_term = (float)1/(A+(i-1)*R);
                    printf(", %g",HP_term);//%g for exact value anf u can use %f also
                }
                printf("\n");
            }
            else
                printf("Input(s) out of range");
        }
        else
            printf("Invalid input(s)");
        printf("Want to continue[y/n]: ");
        scanf("\n%c",&choice);
    }while(choice == 'y');
    return 0;
}

