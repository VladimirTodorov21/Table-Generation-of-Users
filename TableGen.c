/* This program runs 3 C source files including a main() that prompt the user to generate a table of information regarding
User ID, first and last name, country, phone number, email, SIN Number and password in any order they wish. Once the program reads their input,
it generates the appropriate data into a .csv.txt file which contains the information separated by commas. This is the main() method
*/

//File and library inclusions
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sort.c"

//define function in main from sort.io to access it
void sortArray(size_t size,char arr[], int row, char file[20]);

int main(){
   
   //booleans required to loop through menu
   bool loop = true;
   bool backToMenu = true;
   int menuSelect;

   do{
        system("clear");
        printf("TableGen Menu\n-------------\n1. Generate new table\n2. Exit\n\nSelection: ");

        //scans user Input
        scanf("%d", &menuSelect);

        if (menuSelect == 1){
            system("clear");

            //Display of options
            printf("Column Options\n--------------\n");
            printf("%-20s %s\n", "1. User ID", "5. Phone Number");
            printf("%-20s %s\n", "2. First name", "6. Email address");
            printf("%-20s %s\n", "3. Last name", "7. SIN");
            printf("%-20s %s\n", "4. Country", "8. Password");

            printf("\nEnter column list (comma-separated, no spaces): ");
            char columnList[20];
            //Prompts user Input for columns
            scanf("%s", columnList);

            printf("Enter the row count (1 < n < 1M): ");
            int rowCount;
            //Prompts user Input for row number
            scanf("%d", &rowCount);

            printf("Enter output file name (no suffix): ");
            char fileName[20];
            //Prompts user Input for the name of the file
            scanf("%s", fileName);

            //Prints the summary of the input by the user onto the display
            printf("\nSummary of properties:\n");
            printf("%s %s\n", " Columns:", columnList);
            printf("%s %d\n", " Row count:", rowCount);
            printf("%s %s\n", " File name:", fileName);

            size_t size = sizeof(columnList)/sizeof(columnList[0]);
            //Executes function from sort.c
            sortArray(size,columnList,rowCount,fileName);

            printf("%s%s%s","\nTable written successfully to ", fileName, ".csv\n");

            printf("\nPress 'c' or 'C' to continue ");
            char proceed;
            //Prompts user to continue back to menu
            scanf("%s", &proceed);

            loop = true;

        } else if (menuSelect == 2){
            //Exits Program
            system("clear");
            printf("Goodbye and thanks for using TableGen!");
            loop = false;
        }
   } while(loop != false);
   
    return 0;
}
