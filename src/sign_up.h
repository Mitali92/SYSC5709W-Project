#ifndef SIGN_UP_H
#define SIGN_UP_H

#include <stdio.h>
#include <stdlib.h>     //used for - system(CLEAR)
#include <string.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#ifdef __linux__
    #define CLEAR "clear"
#elif _WIN64 || _WIN32
    #define CLEAR "cls"
#elif __APPLE__
    #define CLEAR "clear"
#elif __unix__
    #define CLEAR "clear"
#endif

int char_check(char input[]);
int pwd_check(char input[]);
void sign_up();

#endif 

