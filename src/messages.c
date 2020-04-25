#ifdef __linux__
    #define CLEAR "clear"
#elif _WIN64 || _WIN32
    #define CLEAR "cls"
#elif __APPLE__
    #define CLEAR "clear"
#elif __unix__
    #define CLEAR "clear"
#endif

#include <stdio.h>
#include <stdlib.h>     //used for - system(CLEAR)
#include <string.h>

#include "messages.h"

void messages(int msg_id)
    {
        switch(msg_id)
            {
                case 1:
                    printf(ANSI_COLOR_RED"INVALID INPUT! PLEASE PRESS ENTER TO TRY AGAIN"ANSI_COLOR_RESET);
                    break;

                case 2:
                    printf(ANSI_COLOR_RED"INVALID NAME! PLEASE PRESS ENTER TO TRY AGAIN"ANSI_COLOR_RESET);
                    break;

                case 3:
                    printf(ANSI_COLOR_RED"NAME CANNOT BE MORE THAN 20 CHARACTERS. PLEASE PRESS ENTER TO TRY AGAIN"ANSI_COLOR_RESET);
                    break;

                case 4:
                    printf(ANSI_COLOR_RED"INVALID USERNAME. PLEASE PRESS ENTER TO TRY AGAIN"ANSI_COLOR_RESET);
                    break;

                case 5:
                    printf(ANSI_COLOR_RED"NAME CANNOT BE MORE THAN 20 CHARACTERS. PLEASE PRESS ENTER TO TRY AGAIN"ANSI_COLOR_RESET);
                    break;

                case 6:
                    printf(ANSI_COLOR_RED"INVALID PASSWORD. PLEASE PRESS ENTER TO TRY AGAIN"ANSI_COLOR_RESET);
                    break;

                case 7:
                    printf(ANSI_COLOR_RED"PASSWORD CANNOT BE MORE THAN 20 CHARACTERS. PLEASE PRESS ENTER TO TRY AGAIN"ANSI_COLOR_RESET);
                    break;

                case 8:
                    printf(ANSI_COLOR_RED"PASSWORD MIS-MATCH. PLEASE PRESS ENTER TO TRY AGAIN"ANSI_COLOR_RESET);
                    break;

                case 9:
                    printf(ANSI_COLOR_GREEN"\n\t\t\t SIGNUP SUCCESSFUL. PRESS ENTER TO GO BACK TO THE HOME MENU"ANSI_COLOR_RESET);
                    break;

                case 10:
                    printf(ANSI_COLOR_RED"INVALID EMAIL ADDRESS. PLEASE PRESS ENTER TO TRY AGAIN"ANSI_COLOR_RESET);
                    break;

                case 11:
                    printf(ANSI_COLOR_RED"SIGNUP FAILED. PLEASE PRESS ENTER TO GO BACK TO HOME PAGE"ANSI_COLOR_RESET);
                    break;

                default:
                    printf("ARE YOU SURE YOU WANT TO EXIT ? (Y/N)");
                    break;
            }
    }
