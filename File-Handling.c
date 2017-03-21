/*
  Simple File Handling in C using Structure
  By AbdealiB
  https://github.com/AbdealiB/File-Handling
*/

#include<stdio.h>
#include<conio.h>
#include<string.h>

// Declaration of structure Empl
struct Empl{
    // Adding data types to store name and id's of the Employees
    char name[100];
    int empl_id;
    char Address[1000];
};

void main(){

    struct Empl e[10]; // Declaring array of structure variables
    FILE *file_append, *file_read; // Pointers to The File
    char buff[1000];
    int i;

    file_append = fopen("employee-details.txt", "a+"); // employee-details.txt opened in append mode
    file_read = fopen("employee-details.txt", "r"); // employee-details.txt opened in read mode
    
    /* Getting Input from User and Appending to the file employee-details. */
    if (file_append != NULL) {
        // Asking users to enter 10 employee name's and id's
        for(i = 1; i <= 9; i++){
            printf("Enter Name of Employee %d: ", i);
            gets(e[i].name);
            printf("Enter ID of the Employee %d: ", i);
            scanf("%d", &e[i].empl_id);
            getchar();
            printf("Enter address of the Employee %d: ", i);
            gets(e[i].Address);
            // Printing it to the employee-details.txt file
            fprintf(file_append, "Employee %s has Employee ID %d and Address: %s.\n", e[i].name, e[i].empl_id, e[i].Address);
        }
        printf("File Created.\n");
        fclose(file_append); // Closing the file
    }
    else {
        printf("The file wasn't Created.\n");
    }

    /* Reading from the employee-details.txt line by line And Displaying It. */
    printf("Contents of file are: \n");
    while (fgets(buff, 1000, file_read) !=NULL) {
       printf("%s", buff);
   }
   fclose(file_read); // Closing the file
   getch();
}
