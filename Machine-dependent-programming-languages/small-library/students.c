//
// Created by views on 23.05.18.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include "students.h"
#include "users.h"
#include "errors.h"

#define  BUFFER_SIZE 1024

static int main() {
    students_menu(false);
}

int students_menu(bool top_level_menu) {
    int item_number;
    do {
        printf("1 - Add student\n");
        printf("2 - Remove student\n");
        printf("3 - Сreate database backup\n");
        printf("4 - Restore database\n");
        printf("5 - Find a student\n");
        printf("9 - Exit\n");

        if (top_level_menu) {
            printf("0 - Back\n");
        }

        printf("Select menu item: ");
        scanf("%i", &item_number);
        printf("\n");

        switch (item_number) {
            case 1:
                add_student_menu_item();
                break;
            case 2:
                remove_student_menu_item();
                break;
            case 3:
                create_database_backup_menu_item();
                break;
            case 4:
                restore_database_menu_item();
                break;
            case 5:
                find_students_menu_item();
                break;
            case 9:
                return EXIT;
            case 0:
                if (top_level_menu) {
                    return SUCCESS;
                }
            default:
                printf("There is no such item in the menu\n\n");
        }
    } while (item_number);
}

void add_student_menu_item() {
    char number[80];
    printf("Record-book number: ");
    scanf("%s", number);
    switch (has_student(number)) {
        case SUCCESS:
            printf("Student already exists\n\n");
            return;
        case OPEN_FILE_ERROR:
            printf("Error: cannot open file students.csv\n\n");
            return;
        case FAIL:
            break;
        default:
            return;
    }

    char last_name[80];
    printf("Last name: ");
    scanf("%s", last_name);

    char first_name[80];
    printf("First name: ");
    scanf("%s", first_name);

    char patronymic[80];
    printf("Patronymic: ");
    scanf("%s", patronymic);

    char faculty[8];
    printf("Faculty: ");
    scanf("%s", faculty);

    char specialty[80];
    printf("Specialty: ");
    scanf("%s", specialty);

    switch (add_student(number, last_name, first_name, patronymic, faculty, specialty)) {
        case OPEN_FILE_ERROR:
            printf("Error: cannot open file students.csv\n\n");
            break;
        case SUCCESS:
            printf("SUCCESS\n\n");
            break;
        default:
            break;
    }
};

void remove_student_menu_item() {
    char number[80];
    printf("Record-book number: ");
    scanf("%s", number);

    switch (remove_student(number)) {
        case OPEN_FILE_ERROR:
            printf("Error: cannot open file students.csv\n\n");
            break;
        case FILE_PERMISSION_ERROR:
            printf("Error: cannot edit file students.csv\n\n");
            break;
        case SUCCESS:
            printf("SUCCESS\n\n");
        default:
            break;
    }
}

void create_database_backup_menu_item() {
    char fname[40];

    time_t current_time = time(NULL);
    struct tm *local = localtime(&current_time);

    sprintf(fname, "students_%u.%u.%u_%u:%u:%u.csv", local->tm_mday, local->tm_mon + 1, local->tm_year + 1900,
            local->tm_hour, local->tm_min, local->tm_sec);

    switch (copy_file("students.csv", fname)) {
        case OPEN_FILE_ERROR:
            printf("Error: cannot open file students.csv\n\n");
            break;
        case SUCCESS:
            printf("SUCCESS\n\n");
            break;
        default:
            break;
    }
}

void restore_database_menu_item() {
    char fname[80];
    printf("File name: ");
    scanf("%s", fname);

    switch (copy_file(fname, "students.csv")) {
        case OPEN_FILE_ERROR:
            printf("Error: cannot open file %s\n\n", fname);
            break;
        case SUCCESS:
            printf("SUCCESS\n\n");
            break;
        default:
            break;
    }
}

void find_students_menu_item() {
    char last_name[80];
    printf("Student last name: ");
    scanf("%s", last_name);

    printf("\n");

    switch (find_students(last_name)) {
        case OPEN_FILE_ERROR:
            printf("Error: cannot open file students.csv\n\n");
            break;
        case SUCCESS:
            printf("SUCCES\n\n");
            break;
        case FAIL:
            printf("No students with the last name %s\n\n", last_name);
            break;
        default:
            break;
    }
}

int find_students(const char *student_last_name) {
    char buff[BUFFER_SIZE], *line, *pch;
    bool succes = false;
    size_t len = 0;

    FILE *students_file = fopen("students.csv", "r");
    if (!students_file) {
        return OPEN_FILE_ERROR;
    }

    for (int i = 1; getline(&line, &len, students_file) != -1; i++ )
    {
        strcpy(buff, line);
        pch = strtok(line, ";");
        pch = strtok(NULL, ";");
        if (strcmp(student_last_name, pch) == 0) {
            printf("%s", buff);
            succes = true;
        }
    }
    
    printf("\n");
    fclose(students_file);
    return succes ? SUCCESS : FAIL;
}

int has_student(const char *number) {
    char *db_number, *pch, *line = NULL;
    size_t len = 0;

    FILE *students_file = fopen("students.csv", "r");
    if (!students_file) {
        return OPEN_FILE_ERROR;
    }
    for (int i = 1; getline(&line, &len, students_file) != -1; i++ )
    {
        pch = strtok(line, ";");
        if (strcmp(number, pch) == 0) {
            fclose(students_file);
            return SUCCESS;    
            break;
        }
    }
    fclose(students_file);

    return FAIL;
}

int add_student(char *number, char *last_name, char *first_name, char *patronymic, char *faculty, char *specialty) {
    FILE *students_file = fopen("students.csv", "a");
    if (!students_file) {
        return OPEN_FILE_ERROR;
    }

    fprintf(students_file, "%s;%s;%s;%s;%s;%s\n", number, last_name, first_name, patronymic, faculty, specialty);
    fclose(students_file);

    return SUCCESS;
}

int remove_student(const char *number) {
    char buff[BUFFER_SIZE];

    FILE *students_file = fopen("students.csv", "r");
    if (!students_file) {
        return OPEN_FILE_ERROR;
    }

    FILE *result_file = fopen(".students.csv", "w");
    if (!result_file) {
        return OPEN_FILE_ERROR;
    }
    char *line = NULL, *pch = NULL;
    size_t len = 0;
    for (int i = 1; getline(&line, &len, students_file) != -1; i++ )
    {
        strcpy(buff, line);
        pch = strtok(line, ";");
        while (pch != NULL){
            if (strcmp(number, pch) != 0) {
                fprintf(result_file, "%s", buff);
            }
            break;
        }
    }
    fclose(students_file);
    fclose(result_file);

    if (remove("students.csv") != 0) {
        return FILE_PERMISSION_ERROR;
    }

    if (rename(".students.csv", "students.csv") != 0) {
        return FILE_PERMISSION_ERROR;
    }

    return SUCCESS;
}

int copy_file(const char *dest_fname, const char *src_fname) {
    char buff[BUFFER_SIZE];

    FILE *src_file = fopen(dest_fname, "r");
    if (!src_file) {
        return OPEN_FILE_ERROR;
    }

    FILE *dest_file = fopen(src_fname, "w");
    if (!dest_file) {
        return OPEN_FILE_ERROR;
    }

    while (!feof(src_file)) {
        fgets(buff, BUFFER_SIZE, src_file);
        fputs(buff, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);

    return SUCCESS;
}