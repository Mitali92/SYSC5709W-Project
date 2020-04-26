#ifndef ADD_BOOKS_H
#define ADD_BOOKS_H

#ifdef __linux__
    #define CLEAR "clear"
#elif _WIN64 || _WIN32
    #define CLEAR "cls"
#elif __APPLE__
    #define CLEAR "clear"
#elif __unix__
    #define CLEAR "clear"
#endif

int isbn_validation(char search_term[],int search_field);
int increment_id();
void add_book();

#endif