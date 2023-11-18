/* This source file runs an algorithm that changes character array into an integer array and sorts it afterwards.
Next, eight 2-D character arrays are declared and their content is stored based on the user input. Once the program stores their respective data,
the program then opens a file in write mode to write the content of each array (according to user input) onto the .csv.txt file.
*/

//File and library inclusions
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "io.c"

//define function in main from io.c to access it
void inputOutput(char arrRow[][100],int rows,int num);

void sortArray(size_t size, char arr[], int row, char file[20]){
    
    //new char array to copy contents of the char array parameters
    char array1[] = "";
    
    //Copy the content into the new char array
    for (int a=0;a<size;a++){
        if (arr[a] == ','){
            array1[a] = arr[a+1];
        } else {
            array1[a] = arr[a];
        }
    }

    //Removes any duplicate character in the char Array
    for (int b=0;b<size;b++){  
        for (int c=b+1;c<size;c++){   
            if (array1[b] == array1[c]){
                for (int d=c;d<size-1; d++){  
                    array1[d] = array1[d+1];  
                }  
                size--;  
                c--;      
            }  
        }  
    } 

    //Converts the char array to a long array using strtol
    char *ptr;
    long longArray = strtol(array1, &ptr, 10);

    //Access index of long array in int array
    int intArray = floor(log10(longArray)) + 1;
    int array[intArray];

    //Converts the content of long array into int array
    for (int i=intArray;i>0;i--){
        array[intArray-i] = (int)(longArray/pow(10,i-1))%10;
    }
    
    size_t sizeArray = sizeof(array)/sizeof(array[0]);

    //Sorts the int array in ascending order of integers
    for (int i = 0; i < sizeArray; i++) { 
        int min_index = i; 
        for (int j = i + 1; j < sizeArray; j++) {
            if (array[j] < array[min_index]) {
                min_index = j; 
            }
        }
        //Pointers used for garbage collection
        int *xp = &array[min_index];
        int *yp = &array[i];

        int temp = *xp;
        *xp = *yp;
        *yp = temp;
    }  

    //Removes any duplicate integer in the int array and adjusting the size of the array accordingly
    for (int k=0;k<sizeArray;k++){  
        for (int l=k+1;l<sizeArray;l++){   
            if (array[k] == array[l]){
                for (int m=l;m<sizeArray-1;m++){  
                    array[m] = array[m+1];
                }  
                sizeArray--;  
                l--;      
            }  
        }
    }

    //Char array declarations for content storing and other variables required to store the content in the respective arrays
    char userID[row][100];
    char uid[10];

    char firstNames[1000][100];
    char lastNames[1000][100];
    char countries[195][100];
    int threeDigits[] = {398,270,925,867,209,429,908,997,444,219};
    char phoneNumber[row][100];
    char td[10],pd[10],phoneNum[20],phoneDigit[4];
    int tD,pD,phoneDigits;

    char emails[100][100];
    char sinNumber[row][100];
    char sd1[10],sd2[10],sd3[10],sd4[10],sd5[10],sd6[10],sd7[10],sd8[10],sd9[10];

    char password[row][100];
    char randomChar;
    int passwordLength, randomNum;

    //Setting the time to 0 for randomizer from math.h library
    srand(time(0));

    int rowCount;
    int number;

    //Looks through the content of the int array and based on the integer at its indexes, stores contain in the respective char arrays
    for (int n=0;n<sizeArray;n++){
        switch(array[n]){
            //User ID: increments the user Id in the array based on the size of the row from user input
            case 1:
                for(int p=0;p<row;p++){
                    sprintf(uid,"%d",p+1);
                    strcpy(userID[p], uid);
                }
                break;
            //First Name (executes the function from io.c to read the input from the .txt file and store it into the array)
            case 2:
                number = 2;
                rowCount = 1000;
                inputOutput(firstNames,rowCount,number);
                break;
            //Last Name (executes the function from io.c to read the input from the .txt file and store it into the array)
            case 3:
                number = 3;
                rowCount = 1000;
                inputOutput(lastNames,rowCount,number);
                break;
            //Country (executes the function from io.c to read the input from the .txt file and store it into the array)
            case 4:
                number = 4;
                rowCount = 195;
                inputOutput(countries,rowCount,number);
                break;
            // Phone Number: picks 3 valid integers from an array containing the valid ones and randomizing a 4-digit number,
            //               then the integers are converted into characters using sprintf() and concatenates each character together
            //               to form the new row inside a 2D char array containing the 3 valid digits followed by a hyphen '-' and the randomized 4 digits
            case 5:
                for (int q=0;q<row;q++){
                    phoneDigits = (rand()%10);
                    tD = (int)threeDigits[phoneDigits];
                    sprintf(td,"%d",tD);

                    pD = (rand()%10000);
                    sprintf(pd,"%d",pD);

                    strcpy(phoneNumber[q], td);
                    strcat(phoneNumber[q], "-");
                    strcat(phoneNumber[q], pd);
                }
                break;
            //Email (executes the function from io.c to read the input from the .txt file and store it into the array)
            case 6:
                number = 6;
                rowCount = 100;
                inputOutput(emails,rowCount,number);
                break;
            //SIN Number: randomizes 9 digits from 0 to 9 and converts each int to char array, then each character is
            //            concatenated until all 9 characters from an entire row in the 2-D char array
            case 7:
                for (int r=0;r<row;r++){
                    sprintf(sd1,"%d", rand()%10);
                    sprintf(sd2,"%d", rand()%10);
                    sprintf(sd3,"%d", rand()%10);
                    sprintf(sd4,"%d", rand()%10);
                    sprintf(sd5,"%d", rand()%10);
                    sprintf(sd6,"%d", rand()%10);
                    sprintf(sd7,"%d", rand()%10);
                    sprintf(sd8,"%d", rand()%10);
                    sprintf(sd9,"%d", rand()%10);
                    
                    strcpy(sinNumber[r],sd1);
                    strcat(sinNumber[r],sd2);
                    strcat(sinNumber[r],sd3);
                    strcat(sinNumber[r],sd4);
                    strcat(sinNumber[r],sd5);
                    strcat(sinNumber[r],sd6);
                    strcat(sinNumber[r],sd7);
                    strcat(sinNumber[r],sd8);
                    strcat(sinNumber[r],sd9);
                }
                break;
            //Password: randomized password length from 6 to 16 characters. Next, in the for-loop, an integer is randomized
            //          and inserted as a character (that understands the integer as an ASCII code index in the table) but
            //          excludes the comma. Then, the character is concatenated into the 2-D array until it reaches the randomized
            //          password length. Thus, the passwords in each row will have different random lengths
            case 8:
                for(int s=0;s<row;s++){
                    passwordLength = (rand()%10)+6;
                    strcpy(password[s], "");

                    for (int t=0;t<passwordLength;t++){
                        do {
                            randomNum = (rand()%93);
                            randomChar = randomNum + '!';
                        } while (randomChar == ',');

                        strcat(password[s], &randomChar);
                    }
                }
                break;
            default:
                break;
        }
    }


    char fileName[100];
    strcpy(fileName, file);
    strcat(fileName, ".csv.txt");

    //Opens a new file in write mode and .csv.txt 
    FILE *newFile = fopen(fileName,"w");

    //First for-loop prints the header of the table for user readability
    for (int u=0;u<sizeArray;u++){
        switch (array[u]){
            case 1:
                fprintf(newFile, "UserID, ");
                break;
            case 2:
                fprintf(newFile, "First Name, ");
                break;
            case 3:
                fprintf(newFile, "Last Name, ");
                break;
            case 4:
                fprintf(newFile, "Country, ");
                break;
            case 5:
                fprintf(newFile, "Phone Number, ");
                break;
            case 6:
                fprintf(newFile, "Email, ");
                break;
            case 7:
                fprintf(newFile, "SIN Number, ");
                break;
            case 8:
                fprintf(newFile, "Password");
                break;
            default:
                break;
        }
    }
    fprintf(newFile, "\n");

    int fn,ln,count,em;

    //Second for-loop prints the content separated by commas and according to which columns the user wished to create a file with
    for (int v=0;v<row;v++){
        for (int w=0;w<sizeArray;w++){
            switch (array[w]){
                case 1:
                    fprintf(newFile, "%s, ",userID[v]);
                    break;
                case 2:
                    fn = rand()%100;
                    fprintf(newFile, "%s, ",firstNames[fn]);
                    break;
                case 3:
                    ln = rand()%1000;
                    fprintf(newFile, "%s, ",lastNames[ln]);
                    break;
                case 4:
                    count = rand()%195;
                    fprintf(newFile, "%s, ",countries[count]);
                    break;
                case 5:
                    fprintf(newFile, "%s, ",phoneNumber[v]);
                    break;
                case 6:
                    em = rand()%100;
                    fprintf(newFile, "%c%s@%s, ",firstNames[fn][0],lastNames[ln],emails[em]);
                    break;
                case 7:
                    fprintf(newFile, "%s, ",sinNumber[v]);
                    break;
                case 8:
                    for (int x=0;x<16;x++){
                        fprintf(newFile, "%c",password[v][2*x]);
                    }
                    break;
                default:
                    break;
            }
        }
        fprintf(newFile,"\n");
    }
    //close the file to avoid errors, looping of the program or leakage
    fclose(newFile);
}
