#include<stdio.h>
#include<conio.h>
#include<string.h>

struct Empl{
    char name[100];
    int empl_id;
};
void main(){
    struct Empl e[10];
    FILE *file_append, *file_read;
    char buff[1000];
    int i;

    file_append = fopen("employee-details.txt", "a+");
    file_read = fopen("employee-details.txt", "r");

    /* Getting Input from User and Appending to the file employee-details. */
    if (file_append != NULL) {
        for(i = 0; i < 10; i++){
            printf("Enter Name of Employee and Employee ID of the Employee:\n");
            scanf("%s%d", &e[i].name, &e[i].empl_id);
            fprintf(file_append, "Employee %s has Employee ID %d.\n", e[i].name, e[i].empl_id);
        }
        printf("File Created.\n");
        fclose(file_append);
    }
    else {
        printf("The file wasn't Created.\n");
    }

    /* Reading from the employee-details And Displaying It. */
    printf("Contents of file are: \n");
    while (fgets(buff, 1000, file_read) !=NULL) {
       printf("%s", buff);
   }
   fclose(file_append);
   getch();
}
