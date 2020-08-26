/*Documentation
Name        : Hargovind Singh
Date        : 1 Aug 2020
Description : WAP to calculate no of lines, word, character
Input       :
Output      :
 */
#include<stdio.h>
int main()
{
    char ch;//variable to read character
    int character_count = 0;//to store the character count
    int line_count = 0;//to store the line count
    int word_count = 0;//variable to store the word counts
    int flag = 0, start = 0;//status variable
    while((ch = getchar()) != EOF)
    {
        character_count++;//INC charcter count
        if ( ch == '\n' )
            line_count++;//INC line count
        if (start == 0)//this condition to check whether user has entered a space, newline or table as a first character
        {//checking for first valid printable character from starting
            if ( ch == ' ' || ch == '\n' || ch == '\t' )
                continue;
            else
                start = 1;
        }
        if ( (flag == 1) && (ch != ' ' && ch != '\n' && ch != '\t') )
        {
            word_count++;//INC word count
            flag = 0;
        }        
        if ( start == 1 )
        {
            if ( ch == ' ' || ch == '\n' || ch == '\t' )//cond. for non-pritable character for INC in count
                flag = 1;//Setting flag
        } 
    }
    line_count++;//as at last EOF encounters so it will not go inside loop and will not get INC
    word_count++;//same as above
    printf("\nCharacter count :%d\n",character_count);
    printf("Line count :%d\n",line_count);
    printf("Word count :%d\n",word_count);
    return 0;
}

