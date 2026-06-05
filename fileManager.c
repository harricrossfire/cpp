#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_SIZE 1000

char file_name[300];
char dir_name[100];

void clean_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void select_file_name() {
    char temp_file_name[100];
    printf("Please enter the name of the file you want to access(be sure to include the extension):\n");
    printf("-------------------------------------------\n");
    fgets(temp_file_name, sizeof(temp_file_name), stdin);
    temp_file_name[strcspn(temp_file_name, "\n")] = '\0';
    snprintf(file_name, sizeof(file_name), "%s/%s", dir_name, temp_file_name);
    return;
}

void write_file() {
    char user_input[MAX_SIZE];
    select_file_name();
    FILE * fptr;
    int file_exists = 0;
    fptr = fopen(file_name, "r");
    if (fptr != NULL) {
        file_exists = 1;
        fclose(fptr);
    }
    fptr = fopen(file_name,"w");
    if (fptr == NULL) {
        printf("The file could not be opened or created.");
        printf("-------------------------------------------\n");
        return;
    }
    if (file_exists) {
        printf("The file '%s' already exists. It will be overwritten.\n", file_name);
        printf("-------------------------------------------\n");
    }
    else {
        printf("The file '%s' is created successfully.\n", file_name);
    }
    printf("What would you like to write to file?:\n");
    printf("-------------------------------------------\n");
    fgets(user_input,sizeof(user_input),stdin);
    fprintf(fptr,"%s",user_input);
    printf("-------------------------------------------\n");
    printf("Your input has been written to file successfully!\n");
    printf("-------------------------------------------\n");
    fclose(fptr);
}

void read_file() {
    select_file_name();
    FILE *fptr;
    char data[MAX_SIZE];
    fptr = fopen(file_name, "r");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return;
    }
    else {
        printf("File opened successfully!\n");
        printf("The contents of the file are:\n");
        printf("-------------------------------------------\n");
        while (fgets(data, MAX_SIZE, fptr) != NULL){
            printf("%s", data);
        }
        printf("-------------------------------------------\n");
        fclose(fptr);
    }
}

void check_password() {
    char password[20] = "";
    while (strcmp(password, "christ4life\n") != 0) {
        printf("Welcome to your file manager! Please enter your password to continue:\n");
        printf("-------------------------------------------\n");
        fgets(password,sizeof(password),stdin);
        printf("-------------------------------------------\n");
        if (strcmp(password, "christ4life\n") != 0) {
            printf("Incorrect password! Try again.\n");
            printf("-------------------------------------------\n");
            continue;
        }
        else {
            printf("Password accepted! Welcome user!\n");
            printf("-------------------------------------------\n");
        }
    }
}

void list_file_options() {
    int choice;
    while(1) {
        printf("Welcome to your file manager! What would you like to select?\n");
        printf("1. Write to file\n");
        printf("2. Read from file\n");
        printf("3. Exit\n");
        printf("-------------------------------------------\n");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Try again.\n");
            printf("-------------------------------------------\n");
            clean_input_buffer();
            continue;           
        }
        clean_input_buffer();
        switch (choice) {
            case 1:
                printf("-------------------------------------------\n");
                write_file();
                break;
            case 2:
                printf("-------------------------------------------\n");
                read_file();
                break;
            case 3:
                printf("-------------------------------------------\n");
                printf("Thank you user! Exiting program...\n");
                printf("-------------------------------------------\n");
                exit(0);
            default:
                printf("Invalid input! Exiting program...\n");
                printf("-------------------------------------------\n");
                break;
        }
    }
}

void select_directory() {
    DIR *d;
    struct dirent *dir;
    int dir_exists = 0;
    while (1) {
        dir_exists = 0;
        printf("Please type the directory you want to select:\n");
        printf("-------------------------------------------\n");
        fgets(dir_name, sizeof(dir_name), stdin);
        dir_name[strcspn(dir_name, "\n")] = '\0';
        if ((d = opendir(dir_name)) != NULL) {
            dir_exists = 1;
            closedir(d);
        }
        if (dir_exists) {
            printf("Directory '%s' selected successfully!\n", dir_name);
            printf("-------------------------------------------\n");
            break;
        }
        else {
            printf("Directory '%s' does not exist! Would you like to create it? (y/n)\n", dir_name);
            printf("-------------------------------------------\n");
            char choice;
            if (scanf("%c", &choice) != 1) {
                printf("Invalid input! Try again.\n");
                printf("-------------------------------------------\n");
                clean_input_buffer();
                continue;
            }
            else if (choice == 'y' || choice == 'Y') {
                if (mkdir(dir_name, 0777) == 0) {
                    printf("Directory '%s' created successfully!\n", dir_name);
                    printf("-------------------------------------------\n");
                    break;
                }
                else {
                    perror("Error creating directory!");
                }
            }
            else if (choice == 'n' || choice == 'N') {
                printf("Please select a different directory.\n");
                printf("-------------------------------------------\n");
                continue;
            }
            else {
                printf("Invalid input! Try again.\n");
                printf("-------------------------------------------\n");
                clean_input_buffer();
                continue;
            }
        }
    }
}

int main() {
    check_password();
    select_directory();
    list_file_options();
    return 0;
}