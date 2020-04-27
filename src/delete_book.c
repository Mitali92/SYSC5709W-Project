#include <errno.h>
#include<string.h>
#include<stdio.h>
#include <stdlib.h>

#include "delete_record.h"
#include "layout.h"
#include "manager_menu.h"
#include "messages.h"

void delete_book(){

        /**
        * The function delete the book details from the csv file.Books to delete can be search
        by using the unique book_id or isbn_no.
        */

        char search_term[20];
        int table;
        int search_field;
        int choice;
        char isbn[20];
        char bookid[20];

        system(CLEAR);
        header_layout("DELETE BOOK");

        gotoxy(40,11);printf("Choose the filter to search the book : \n\n");

        gotoxy(40,14);printf("[1]. Book ID \n");
        gotoxy(40,15);printf("[2]. ISBN Number \n\n");

        gotoxy(40,17);printf(ANSI_COLOR_YELLOW"ENTER YOUR CHOICE: "ANSI_COLOR_RESET);
    repeat:
        gotoxy(60,17);scanf("%d",&choice);
        getchar();

        if(choice == 1){
            gotoxy(40,19);printf("Enter Book ID :");
    repeat_book:
            gotoxy(60,19);scanf("%s",bookid);
            getchar();

            if(delete_record(bookid,1,1)==0){
               gotoxy(40,21);printf(ANSI_COLOR_RED"Data does not exist.Try again...!!"ANSI_COLOR_RESET);
               getchar();
               gotoxy(40,21);printf("                                                                           ");
               gotoxy(60,19);printf("                                                                           ");
               goto repeat_book;
            }
            else{
                gotoxy(40,23);printf(ANSI_COLOR_GREEN"RECORD DELETED. PRESS ENTER TO GO BACK TO THE MANAGER MENU"ANSI_COLOR_RESET);
                getchar();
                manager_menu();
            }
        }
        else if(choice == 2){
            gotoxy(40,19);printf("Enter ISBN Number :");
    repeat_isbn:
            gotoxy(60,19);scanf("%s",isbn);
            getchar();
            if(delete_record(isbn,1,2)==0){
               gotoxy(40,21);printf(ANSI_COLOR_RED"Data does not exist.Try again...!!"ANSI_COLOR_RESET);
               getchar();
               gotoxy(40,21);printf("                                                                           ");
               gotoxy(60,19);printf("                                                                           ");
               goto repeat_isbn;
            }
            else{
                gotoxy(40,23);printf(ANSI_COLOR_GREEN"RECORD DELETED. PRESS ENTER TO GO BACK TO THE MANAGER MENU"ANSI_COLOR_RESET);
                getchar();
                manager_menu();
            }
        }
        else{
            gotoxy(40,19);messages(1);
            getchar();
            gotoxy(60,17);printf("                                                                           ");
            gotoxy(40,19);printf("                                                                           ");
            goto repeat;
        }

}
