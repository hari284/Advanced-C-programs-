/*Documentation
Name        : Hargovind Singh
Date        : 18-07-2020
Description : Given the number from 1 to 365, WAP to find which day of the year.
Input       : 
Output      :
 */
#include<stdio.h>
int main()
{
    char choice = 'n';//initially making choice as No(n).
    do
    {
        int day_value;//variable to store no of day
        printf("Enter the value of 'n':");
        scanf("%d",&day_value);//reading no of day
        if(day_value >= 1 && day_value <= 365)//validating, whether day_value is <=1 and <=365
        {
            int option;
            if(choice == 'n')
                printf("Choose First Day:\n1. Sunday\n2. Monday\n3. Tuesday\n4. Wednesday\n5. Thursday\n6. Friday\n7. Saturday\n");//display to user
            printf("Enter the option to set the first day:");
            scanf("%d",&option);
            if(option >= 1 && option <= 7)//checking for the option whether it is in between 1 to 7 or not
            {
                int temp_value = day_value, first_day = option; //temporary variable's as the original value will required in future
                for(int i = 1; i <= temp_value; i++) //loop for no of days
                {
                    if(option > 7)//checking whether option is 7 or have gone over the 7
                    {
                        temp_value = temp_value - option + first_day;//udation
                        option = 1;
                        i = 1;
                        first_day = 1;
                    }
                    if(i == temp_value)//checking for the last end point
                    {
                        switch( option )//switch case
                        {
                            case 1:
                                printf("The %d day is Sunday\n",day_value);//for sunday
                                break;
                            case 2:
                                printf("The %d day is Monday\n",day_value);//for monday
                                break; 
                            case 3:
                                printf("The %d day is Tuesday\n",day_value);//for tuesday
                                break;
                            case 4:
                                printf("The %d day is Wednesday\n",day_value);//for wednesday
                                break;
                            case 5:
                                printf("The %d day is Thursday\n",day_value);//for thursday
                                break;
                            case 6:
                                printf("The %d day is Friday\n",day_value);//for friday
                                break;
                            default:
                                printf("The %d day is Saturday\n",day_value); //for saturday
                        }
                        break;
                    }
                    option++;//increament in option

                }
            }
            else
                printf("Invalid input");//error msg
        }
        else
            printf("Invalid input");//error msg
        printf("Do you want to continue (y/n): ");
        scanf("\n%c",&choice);//asking for the continuation
    }while(choice == 'y');
    return 0;
}

