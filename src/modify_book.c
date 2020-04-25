#include <errno.h>
#include<string.h>
#include<stdio.h>
#include <stdlib.h>
#include<time.h>

#include "layout.h"
#include "manager_menu.h"
#include "modify_record.h"
#include "database_lookup.h"

char bookid[20];
int edited;
int choice;
char isbn[20];

int edit_field(){

        /**
        * The function is use to select the field which is to be edited from the given choice
        */

        int search_field;
        gotoxy(40,11);printf("Choose the field to edit : \n");
        gotoxy(40,13);printf("[1]. BOOK TITLE ");
        gotoxy(40,15);printf("[2]. ISBN NO.");
        gotoxy(40,17);printf("[3]. AUTHOR NAME");
        gotoxy(40,19);printf("[4]. QUANTITY");
        gotoxy(40,21);printf("[5]. CATEGORY");
        gotoxy(40,23);printf("[6]. LANGUAGE");
        gotoxy(40,25);printf("[7]. DATE OF PUB");
        gotoxy(40,27);printf("[8]. Status");
        gotoxy(40,29);printf("Select the filter : ");
        fflush(stdout);
        gotoxy(60,29);scanf("%d",&search_field);

        return search_field;
}

int data_valid(char search_term[],int search_field){

        /**
        * The function search the isbn_no and book_id in the csv file and validates it if present or not.
        * @param[in] search_term 	Term to match in database.
        * @param[in] search_field 	A number indicating which field of the table to search
        * @param[out] isFound	Acknowledge to the calling function if isbn_no or book_id is present or not.
        */

        char buff[255];
        int isFound = 0;
        FILE *returnFile = lookup(search_term,1,search_field);

        if (returnFile == NULL){
            switch(errno){
                case ENOENT: printf ("The file doesn't exist\n");
                             break;
                    default: printf("The error number is %d\n", errno);
            }
        }

        while (fgets(buff, 1024, returnFile)){

            char *field = strtok(buff, "\",\"");
            if(strcmp(field,search_term)==0){
                    isFound = 1;
                    break;
            }

            field = strtok(NULL, "\",\"");
            field = strtok(NULL, "\",\"");

            if(strcmp(field,search_term)==0){
                    isFound = 1;
                    break;
            }
        }

    return isFound;
}

void modify_book(){
        /**
        * The function is use to modify book details.Book can be search by using book_id or isbn_no you want to modify book.
        */
        system(CLEAR);
        header_layout("MODIFY BOOK");

        gotoxy(40,11);printf("Choose the filter to search the book : \n");
        gotoxy(40,14);printf("[1]. Book ID \n");
        gotoxy(40,16);printf("[2]. ISBN Number \n");
        gotoxy(40,18);printf("Select the filter : ");
        fflush(stdout);
    repeat:
        gotoxy(60,18);scanf("%d",&choice);
        getchar();

        if(choice == 1){
            gotoxy(40,20);printf("Enter Book ID :");
            fflush(stdout);
        repeat_bookid:
            gotoxy(60,20);scanf("%s",bookid);
            getchar();

            if(data_valid(bookid,1)==1){
                gotoxy(40,11);printf("                                                                           ");
                gotoxy(40,14);printf("                                                                           ");
                gotoxy(40,16);printf("                                                                           ");
                gotoxy(60,18);printf("                                                                           ");
                gotoxy(40,18);printf("                                                                           ");
                gotoxy(60,20);printf("                                                                           ");
                gotoxy(40,20);printf("                                                                           ");

                //select the filed to edit
                edited = edit_field();

                if(modify_record(bookid,1,edited)==0){
                    getchar();
                    gotoxy(40,33);printf("Book details modified successfully");
                    gotoxy(40,35);printf("Press any key to cotinue to main menu....");
                    getchar();
                    manager_menu();
                }
            }
            else{
                gotoxy(40,22);printf("Data does not exist.Please try again");
                getchar();
                gotoxy(60,20);printf("                                                                           ");
                gotoxy(40,22);printf("                                                                           ");
                goto repeat_bookid;
            }
        }
        else if(choice == 2){
            gotoxy(40,20);printf("Enter ISBN No. :");
            fflush(stdout);
        repeat_isbn:
            gotoxy(60,20);scanf("%s",isbn);
            getchar();

            if(data_valid(isbn,3)==1){
                gotoxy(40,11);printf("                                                                           ");
                gotoxy(40,14);printf("                                                                           ");
                gotoxy(40,16);printf("                                                                           ");
                gotoxy(60,18);printf("                                                                           ");
                gotoxy(40,18);printf("                                                                           ");
                gotoxy(60,20);printf("                                                                           ");
                gotoxy(40,20);printf("                                                                           ");

                //select the filed to edit
                edited = edit_field();
                if(modify_record(isbn,1,edited)==0){
                    getchar();
                    gotoxy(40,33);printf("Book details modified successfully");
                    gotoxy(40,35);printf("Press any key to cotinue to main menu....");
                    getchar();
                    manager_menu();
                };
            }
            else{
                gotoxy(40,22);printf("Data does not exist.Please try again");
                getchar();
                gotoxy(60,20);printf("                                                                           ");
                gotoxy(40,22);printf("                                                                           ");
                goto repeat_isbn;
            }
        }
        else{
            gotoxy(40,19);printf("Invalid Filter. Please select proper filter from the given choice ");
            getchar();
            gotoxy(60,17);printf("                                                                           ");
            gotoxy(40,19);printf("                                                                           ");
            goto repeat;
        }
}

