/*Documentation
   Name        : Hargovind Singh
   Date        : 18-8-2020
   Description : WAP to implement fragments using Array of Pointers (First Static Second
                 Dynamic).
   Input       :
   Output      :
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char choice;//for user promt
  do{
    int row,col,sum=0;//variable initioalization
    printf("Enter the no. of rows: ");
    scanf("%d",&row);
    float *x[row];//declaring array
    int p_col[row];
    for (int i =0 ; i < row; i++){
      printf("Enter the no. of columns in row[%d] : ",i);
      scanf("%d",&col);//raeding column value one by one for each row
      x[i] = calloc((col+1),sizeof(float));//allocating the memory
      printf("Enter %d values for row[%d] : ",col,i);
      for (int j= 0; j < col; j++){
        scanf("%f",&x[i][j]);
        sum += x[i][j]; 
      }
      x[i][col] = (float)sum/col;//average
	  sum = 0;
      p_col[i] = col;//storing no of column value
    }
    //printing the array values
    printf("Before Sorting output is:\n");
    for (int i = 0; i < row; i++){
      for (int j = 0; j < p_col[i]+1; j++){
        printf("%.2f ",x[i][j]);
      }
      printf("\n");
    }
    //logic for sorting(swaping)
    for (int i =0 ; i < row; i++){
      for (int j = i+1; j < row; j++){
		  //swapping
        if (x[i][p_col[i]] > x[j][p_col[j]]){
          float *ptr = x[i];
          x[i] = x[j];
          x[j] = ptr;
          int temp = p_col[i];
          p_col[i] = p_col[j];
          p_col[j]= temp;   
        }
      }
    }
    printf("After Sorting output is:\n");
    for (int i = 0; i < row; i++){
      for (int j = 0; j < p_col[i]+1; j++){
        printf("%.2f ",x[i][j]);
      }
      printf("\n");
    }
	//freeing the memory
	for (int i =0 ;i < row;i++){
        free(x[i]);
    }
    printf("Want to continue[y/n]: ");
    scanf("\n%c",&choice);
  }while(choice == 'y');
  return 0;
}