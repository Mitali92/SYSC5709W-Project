#ifndef MODIFY_BOOK_H
#define MODIFY_BOOK_H

#ifdef __linux__
    #define CLEAR "clear"
#elif _WIN64 || _WIN32
    #define CLEAR "cls"
#elif __APPLE__
    #define CLEAR "clear"
#elif __unix__
    #define CLEAR "clear"
#endif


int modify_book();
int edit_field();
int data_valid(char search_term[],int search_field);

#endif