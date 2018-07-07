//
// Created by views on 23.05.18.
//

#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "books.h"
#include "errors.h"
#define  BUFFER_SIZE 1024

static int main() {
    books_menu(false);
}

int books_menu(bool top_level_menu) {
    int item_number;
    do {
        printf("1 - Add book\n");
        printf("2 - Remove book\n");
        printf("3 - Find book\n");
        printf("4 - Show books\n");
        printf("9 - Exit\n");

        if (top_level_menu) {
            printf("0 - Back\n");
        }

        printf("Select menu item: ");
        scanf("%i", &item_number);
        printf("\n");

        switch (item_number) {
            case 1:
                add_book_menu_item();
                break;
            case 2:
                remove_book_menu_item();
                break;
            case 3:
                find_book_menu_item();
                break;
            case 4:
                show_books_menu_item();
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

void add_book_menu_item() {
    char isbn[80];
    printf("Book ISBN: ");
    scanf("%s", isbn);

    switch (has_book(isbn)) {
        case SUCCESS:
            printf("book already exists\n\n");
            return;
        case OPEN_FILE_ERROR:
            printf("Error: cannot open file books.csv\n\n");
            return;
        case FAIL:
            break;
        default:
            return;
    }

    char authors[80];
    printf("Authors: ");
    scanf("%s", authors);

    char title[80];
    printf("Title: ");
    scanf("%s", title);

    char count[10];
    printf("Books count: ");
    scanf("%s", count);

    char available_count[10];
    printf("Available books count: ");
    scanf("%s", available_count);

    switch (add_book(isbn, authors, title, count, available_count)) {
        case OPEN_FILE_ERROR:
            printf("Error: cannot open file books.csv\n\n");
            break;
        case SUCCESS:
            printf("SUCCESS\n\n");
            break;
        default:
            break;
    }
};

void remove_book_menu_item() {
    char isbn[80];
    printf("Book ISBN: ");
    scanf("%s", isbn);

    switch (remove_book(isbn)) {
        case OPEN_FILE_ERROR:
            printf("Error: cannot open file books.csv\n\n");
            break;
        case FILE_PERMISSION_ERROR:
            printf("Error: cannot edit file books.csv\n\n");
            break;
        case SUCCESS:
            printf("SUCCESS\n\n");
        default:
            break;
    }
}

void find_book_menu_item() {
    char isbn[80];
    printf("Book ISBN: ");
    scanf("%s", isbn);

    printf("\n");

    switch (find_books(isbn)) {
        case OPEN_FILE_ERROR:
            printf("Error: cannot open file books.csv\n\n");
            break;
        case SUCCESS:
            printf("SUCCES\n\n");
            break;
        case FAIL:
            printf("No books with ISBN %s\n\n", isbn);
            break;
        default:
            break;
    }
}

void show_books_menu_item() {

    switch (show_books()) {
        case OPEN_FILE_ERROR:
            printf("Error: cannot open file books.csv\n\n");
            break;
        case SUCCESS:
            printf("SUCCES\n\n");
            break;
        case FAIL:
            printf("No books \n\n");
            break;
        default:
            break;
    }
}

int show_books(){
    char *line, *pch, arr[BUFFER_SIZE][BUFFER_SIZE], str[80];
    long unsigned int i = 0, keys[BUFFER_SIZE];
    size_t len = 0;
    bool succes = false;
    
    FILE *books_file = fopen("books.csv", "r");
    if (!books_file) {
        return OPEN_FILE_ERROR;
    }

    for (; getline(&line, &len, books_file) != -1 && i < BUFFER_SIZE; i++ )
    {
        pch = strtok(line, ";");
        strcpy(arr[i], pch);
        keys[i] = atoi(arr[i]);
    }

    fclose(books_file);
    if (i > 0){
        succes = true;
        qsort(keys, i, sizeof(keys[0]), compare_integer);
        for (int j = 0; j < i; j++)
        {
            itoa(keys[j], str);
            find_books(str);
        }  
    }
    return succes ? SUCCESS : FAIL;
}
void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0)  
        n = -n;          
    i = 0;
    do {       
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int i, j;
    char c;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

int compare_integer(const void *a, const void *b)
{
    const int *c = a;
    const int *d = b;
    int difference = *c - *d;
    if (difference > 0)
        return 1;
    else if (difference == 0)
        return 0;
    else
        return -1;
}

int compare_char(const void *p, const void *q)
{
    const char *a = p;
    const char *b = q;
    int res = strcmp(a, b);//*a - *b;
    if (res > 0)
        return 1;
    else if (res == 0)
        return 0;   
    else
        return -1;
}

int has_book(const char *isdn) {
    char *db_isdn;
    char *pch, *line = NULL;    
    char buff[80];
    size_t len = 0;    

    FILE *books_file = fopen("books.csv", "r");
    if (!books_file) {
        return OPEN_FILE_ERROR;
    }
    for (int i = 1; getline(&line, &len, books_file) != -1; i++ )
    {
        pch = strtok(line, ";");
        if (strcmp(isdn, pch) == 0) {
            fclose(books_file);
            return SUCCESS;    
            break;
        }
    }
    fclose(books_file);

    return FAIL;
}

int find_books(const char *book_isbn) {
    char buff[BUFFER_SIZE], *line, *pch;
    bool succes = false;
    size_t len = 0;

    FILE *books_file = fopen("books.csv", "r");
    if (!books_file) {
        return OPEN_FILE_ERROR;
    }

    for (int i = 1; getline(&line, &len, books_file) != -1; i++ )
    {
        strcpy(buff, line);
        pch = strtok(line, ";");
        if (strcmp(book_isbn, pch) == 0) {
            printf("%s", buff);
            succes = true;
        }
    }
    printf("\n");
    fclose(books_file);
    return succes ? SUCCESS : FAIL;    
    //return FAIL;
}

int add_book(char *isbn, char *authors, char *title, char *count, char *available_count) {
    FILE *books_file = fopen("books.csv", "a");
    if (!books_file) {
        return OPEN_FILE_ERROR;
    }

    fprintf(books_file, "%s;%s;%s;%s;%s\n", isbn, authors, title, count, available_count);
    fclose(books_file);

    return SUCCESS;
}

int remove_book(const char *isbn) {
    char buff[BUFFER_SIZE];

    FILE *books_file = fopen("books.csv", "r");
    if (!books_file) {
        return OPEN_FILE_ERROR;
    }

    FILE *result_file = fopen(".books.csv", "w");
    if (!result_file) {
        return OPEN_FILE_ERROR;
    }
    char *line = NULL, *pch = NULL;
    size_t len = 0;
    for (int i = 1; getline(&line, &len, books_file) != -1; i++ )
    {
        strcpy(buff, line);
        pch = strtok(line, ";");
        while (pch != NULL){
            if (strcmp(isbn, pch) != 0) {
                fprintf(result_file, "%s", buff);
            }
            break;
        }
    }
    fclose(books_file);
    fclose(result_file);

    if (remove("books.csv") != 0) {
        return FILE_PERMISSION_ERROR;
    }

    if (rename(".books.csv", "books.csv") != 0) {
        return FILE_PERMISSION_ERROR;
    }

    return SUCCESS;
}