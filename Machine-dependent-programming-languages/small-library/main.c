#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <errno.h>
#include "users.h"
#include "books.h"
#include "students.h"
#include "errors.h"

int top_level_menu();

int main() {
    char login[80];
    printf("login: ");
    scanf("%s", login);

    char password[80];
    printf("password: ");
    scanf("%s", password);
    printf("\n");

    bool students_permission;
    bool books_permission;

    switch (authorizate(login, password, &students_permission, &books_permission)) {
        case SUCCESS:
            break;
        case OPEN_FILE_ERROR:
            printf("Error: cannot open file users.csv\n");
            return -1;
        case FAIL:
            printf("Error: login or password error\n");
            return 0;
        default:
            return -1;
    }

    if (students_permission && books_permission) {
        top_level_menu();
    } else if (students_permission) {
        students_menu(false);
    } else if (books_permission) {
        books_menu(false);
    } else {
        printf("You do not have permissions");
    }

    return 0;
}

int top_level_menu() {
    int item_number;
    do {
        printf("1 - Books\n");
        printf("2 - Students\n");
        printf("0 - Exit\n");
        printf("Select menu item: ");
        scanf("%i", &item_number);
        printf("\n");

        switch (item_number) {
            case 1:
                switch (books_menu(true)) {
                    case EXIT:
                        return EXIT;
                    case SUCCESS:
                        break;
                    default:
                        return FAIL;
                }
                break;
            case 2:
                switch (students_menu(true)) {
                    case EXIT:
                        return EXIT;
                    case SUCCESS:
                        break;
                    default:
                        return FAIL;
                }
                break;
            case 0:
                break;
            default:
                printf("There is no such item in the menu");
        }
    } while (item_number);

    return 0;
}