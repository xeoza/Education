//
// Created by views on 23.05.18.
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "users.h"
#include "errors.h"
#define  BUFFER_SIZE 1024


int authorizate(char *login, char *password, bool *studetns_permission, bool *books_permission) {
    /*char *db_login;
    char *db_password;
    char *db_s_p;
    char *db_b_p;*/
    char buff[BUFFER_SIZE], *line, *pch;
    bool succes = false;
    size_t len = 0;
    
    FILE *users_file = fopen("users.csv", "r");
    if (!users_file) {
        return OPEN_FILE_ERROR;
    }

    for (int i = 1; getline(&line, &len, users_file) != -1; i++ )
    {
        pch = strtok(line, ";");
        if (strcmp(pch, login) == 0 && strcmp(strtok(NULL, ";"), password) == 0) {
            *studetns_permission = *(strtok(NULL, ";")) == '1';
            *books_permission = *(strtok(NULL, ";")) == '1';

            fclose(users_file);
            return SUCCESS;            
        }
    }
    /*while (!feof(users_file)) {
        if (!fscanf(users_file, "%s", buff)) {
            continue;
        }

        db_login = strtok(buff, ";");
        db_password = strtok(NULL, ";");
        db_s_p = strtok(NULL, ";");
        db_b_p = strtok(NULL, ";");

        if (!strcmp(login, db_login) && !strcmp(password, db_password)) {
            *studetns_permission = *db_s_p == '1';
            *books_permission = *db_b_p == '1';

            fclose(users_file);
            return SUCCESS;
        }
    }*/

    fclose(users_file);
    return FAIL;
}