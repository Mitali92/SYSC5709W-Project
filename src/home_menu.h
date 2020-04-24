#ifndef HOME_MENU_H
#define HOME_MENU_H

#include <stdio.h>
#include <stdlib.h>     //used for - system(CLEAR)
#include <string.h>

#define ANSI_COLOR_YELLOW  "\x1b[33m"
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

void home_menu();

#endif 