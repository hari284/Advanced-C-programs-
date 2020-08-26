/*Documentation
Name        : Hargovind Singh
Date        : 23-08-2020
Description : WAP implement the solution for tower of hanoi
Input       : 
Output      : 
 */
#include<stdio.h>
void tower_Hanoi(int n, char start_rod, char end_rod, char aux_rod);//function prototype
int main() 
{ 
    char choice;
    do
    {
        int n_disk; // Number of disks 
        printf("Enter the number of disks N: ");
        scanf("%d",&n_disk);//reading no of disk
        tower_Hanoi(n_disk, 'A', 'C', 'B');  //calling function with A, B and C are names of rods 
        printf("\nWant to continue[y/n]: ");
        scanf("\n%c",&choice);
    }while(choice == 'y');
    return 0; 
} 
void tower_Hanoi(int n, char start_rod, char end_rod, char aux_rod) //function definition
{ 
    if (n == 1) //checking whether disk or left out disk is 1 or not
    { 
        printf("\n Move disk 1 from rod %c to rod %c", start_rod, end_rod); 
        return ; 
    } 
    tower_Hanoi(n-1, start_rod, aux_rod, end_rod); //recursion calling ... changed aux_rod and end_rod
    printf("\n Move disk %d from rod %c to rod %c", n, start_rod, end_rod); 
    tower_Hanoi(n-1, aux_rod, end_rod, start_rod); //recursion calling ... when each rod will have one disk
} 
  