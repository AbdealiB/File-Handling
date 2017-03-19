#include<stdio.h>
#include<conio.h>
#include<string.h>

//Creating Empl structure
struct Empl{
    //Adding data types to store name and id's of the Employee's
    char name[100];
    int empl_id;
};

void main(){

    struct Empl e[10]; // Defining array of structure variables
    FILE *file_append, *file_read; 
    char buff[1000];
    int i;

    file_append = fopen("employee-details.txt", "a+"); // fileobject to append employee details into employee-details.txt
    file_read = fopen("employee-details.txt", "r"); // fileobject to read the created employee-details.txt
    
    /* Getting Input from User and Appending to the file employee-details. */
    if (file_append != NULL) {
        // Asking users to enter 10 employee name's and id's

        for(i = 0; i < 10; i++){
            printf("Enter Name of Employee and Employee ID of the Employee:\n");
            scanf("%s%d", &e[i].name, &e[i].empl_id);
            // Printing it to the employee-details.txt file
            fprintf(file_append, "Employee %s has Employee ID %d.\n", e[i].name, e[i].empl_id);
        }
        printf("File Created.\n");
        fclose(file_append); // Closing the file
    }
    else {
        printf("The file wasn't Created.\n");
    }

    /* Reading from the employee-details.txt line by line  And Displaying It. */
    printf("Contents of file are: \n");
    while (fgets(buff, 1000, file_read) !=NULL) {
       printf("%s", buff);
   }
   fclose(file_read); // Closing the file
    
   getch();
}
