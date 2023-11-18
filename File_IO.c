/* This source file access a character array, opens a file and stores its content into the respective 2D char array.
*/

//Library inclusions
#include <stdio.h>
#include <string.h>

void inputOutput(char arrRow[][100],int rows,int num){
    FILE *file;

    //Opens a file based on which character array is passed as a parameter
    if (num == 2){
        file = fopen("first_names.txt","r");
    } else if (num == 3){
        file = fopen("last_names.txt","r");
    } else if (num == 4){
        file = fopen("countries.txt","r");
    } else if (num == 6){
        file = fopen("email_suffixes.txt","r");
    }

    int i = 0;

    //gets the content inside the chosen file and stores it into the 2D char array
    while(fgets(arrRow[i],rows,file)){
        if (num == 2){
            arrRow[i][strlen(arrRow[i])-1] = '\0';
            i++;
        } else if (num == 3){
            arrRow[i][strlen(arrRow[i])-1] = '\0';
            i++;
        } else if (num == 4){
            arrRow[i][strlen(arrRow[i])-1] = '\0';
            i++;
        } else if (num == 6){
            arrRow[i][strlen(arrRow[i])-1] = '\0';
            i++;
        }

        //Once the file reader has reached the end, it exists the file
        if (feof(file)){
            break;
        }
    }
    //close the file to avoid errors, looping of the program or leakage
    fclose(file);
}
