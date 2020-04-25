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

#include "layout.h"
#include "messages.h"
#include "sign_up.h"
#include "log_in.h"

void home_menu()
    {
        /**
        * The function prints home-page with 3 options for the user to 
        * choose from and calls different functions based on the user-input. 
        * This function doesn't take any input arguments. It will be called
        * directly from main() after the welcome_message()
        * @param[in] void
        */
        int selection = 0;
        header_layout("HOME MENU");

        gotoxy(50,15);
        printf("[ 1 ] SIGNUP");
        gotoxy(50,17);
        printf("[ 2 ] LOGIN");
        gotoxy(50,19);
        printf("[ 0 ] CLOSE APPLICATION");
        gotoxy(50,21);
        printf(ANSI_COLOR_YELLOW"\n\n\t\t\t\t\t\t PLEASE ENTER YOUR CHOICE: "ANSI_COLOR_RESET);
    selection_repeat:
        gotoxy(77,23);
        scanf("%d", &selection);
        getchar();

        switch(selection)
             {
                case 1:
                     sign_up();
                     break;

                case 2:
                    log_in();
                    break;

                case 0:
                    printf("\nEXIT FUNCTION CALLING");
                    //exit(1);
                    break;

                default:
                    gotoxy(50,25);
                    messages(1);
                    getchar();
                    gotoxy(77,23);
                    printf("                                        ");
                    gotoxy(50,25);
                    printf("                                                                                  ");
                    goto selection_repeat;
             }
    }
