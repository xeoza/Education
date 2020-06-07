//
// Created by views on 23.05.18.
//

#ifndef LABS_STUDENTS_H
#define LABS_STUDENTS_H

int students_menu(bool top_level_menu);


void add_student_menu_item();

void remove_student_menu_item();

void create_database_backup_menu_item();

void restore_database_menu_item();

void find_students_menu_item();

int has_student(const char *number);

int add_student(char *number, char *last_name, char *first_name, char *patronymic, char *faculty, char *specialty);

int remove_student(const char *number);

int copy_file(const char *dest_fname, const char *src_fname);

int find_students(const char *student_last_name);

#endif //LABS_STUDENTS_H
