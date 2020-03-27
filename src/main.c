#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void header_position(const char* screen_name)
    {
        int length = 0;
        int position = 0;

        //calculating the position for header label to be displayed
        length = (76-strlen(screen_name))/2;
        printf("\t\t\t");

        for(position = 0 ; position < length ; position++)
            {
                //print space
                printf(" ");
            }
        //print message
        printf(ANSI_COLOR_GREEN"%s"ANSI_COLOR_RESET,screen_name);
    }

void header_layout(const char* screen_name)
    {
            system("cls");  //clears the console screen - added stdlib.h
            printf(ANSI_COLOR_CYAN"\n=======================================================================================================================");
            printf("\n====================================                                               ====================================");
            printf("\n====================================       "ANSI_COLOR_RESET"BOOKIFY - Library management System"ANSI_COLOR_CYAN"     ====================================");
            printf("\n====================================                                               ====================================");
            printf("\n======================================================================================================================="ANSI_COLOR_RESET);
            printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
            header_position(screen_name);
            printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
    }

void welcome_message()
    {
        header_layout("WELCOME");
        printf("\n\n");
        printf(ANSI_COLOR_RED"\n\t\t\t\t***-***-***-***-***-***-***-***-***-***-***-***-***-***-***-***");
        printf("\n\t\t\t\t        =============================================");
        printf("\n\t\t\t\t        |                  "ANSI_COLOR_RESET"WELCOME"ANSI_COLOR_RED"                  |");
        printf(ANSI_COLOR_RED"\n\t\t\t\t        |                    "ANSI_COLOR_RESET"TO"ANSI_COLOR_RED"                     |");
        printf("\n\t\t\t\t        |                  "ANSI_COLOR_RESET"BOOKIFY"ANSI_COLOR_RED"                  |");
        printf("\n\t\t\t\t        |                    "ANSI_COLOR_RESET"-"ANSI_COLOR_RED"                      |");
        printf("\n\t\t\t\t        |                  "ANSI_COLOR_RESET"LIBRARY"ANSI_COLOR_RED"                  |");
        printf("\n\t\t\t\t        |                 "ANSI_COLOR_RESET"MANAGEMENT"ANSI_COLOR_RED"                |");
        printf("\n\t\t\t\t        |                  "ANSI_COLOR_RESET"SYSTEM"ANSI_COLOR_RED"                   |");
        printf("\n\t\t\t\t        =============================================\n");
        printf("\n\t\t\t\t***-***-***-***-***-***-***-***-***-***-***-***-***-***-***-***\n"ANSI_COLOR_RESET);
        printf(ANSI_COLOR_YELLOW"\n\n\t\t\t\t\t\t ENTER ANY KEY TO CONTINUE..."ANSI_COLOR_RESET);

        getch();

    }

int home_menu()
    {
        int selection = 0;
        header_display("HOME MENU");

        printf("\n\t\t\t\t\t\t[ 1 ] SIGNUP");
        printf("\n\t\t\t\t\t\t[ 2 ] LOGIN");
        printf("\n\t\t\t\t\t\t[ 0 ] CLOSE APPLICATION");
        printf(ANSI_COLOR_YELLOW"\n\n\t\t\t\t\t\t PLEASE ENTER YOUR CHOICE: "ANSI_COLOR_RESET);
        scanf("%d", &selection);

//        switch(selection)
//            {
//                case 1:
//                    sign_up();
//                    break;
//
//                case 2:
//                    log_in();
//                    break;
//
//                case 0:
//                    printf("\nThank You");
//                    exit(1);
//                    break;
//
//                default:
//                    printf("\nINVALID INPUT! PLEASE TRY AGAIN");
//            }
    }

int main()
    {
        welcome_message();
        home_menu();
        return 0;
    }
