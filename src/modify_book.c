#include "layout.h"
#include "manager_menu.h"
#include "modify_record.h"
#include "database_lookup.h"


int edit_field();
int modify_record(char search_term[], int table,int search_field);
int data_valid(char search_term[],int search_field);

char bookid[20];
int edited;
int choice;
char isbn[20];

int edit_field()
{
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

            char buff[255];
            int isFound = 0;
            FILE *returnFile = lookup(search_term,1,search_field);
            while (fgets(buff, 1024, returnFile))
            {
                char *field = strtok(buff, "\",\"");
                if(strcmp(field,search_term)==0)
                {
                    isFound = 1;
                    break;
                }
                field = strtok(NULL, "\",\"");
                field = strtok(NULL, "\",\"");

                if(strcmp(field,search_term)==0)
                {
                    isFound = 1;
                    break;
                }
            }

        return isFound;
}

int modify_book()
{
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

        if(choice == 1)
        {
            gotoxy(40,20);printf("Enter Book ID :");
            fflush(stdout);
        repeat_bookid:
            gotoxy(60,20);scanf("%s",bookid);
            getchar();

        if(data_valid(bookid,1)==1)
        {
            gotoxy(40,11);printf("                                                                           ");
            gotoxy(40,14);printf("                                                                           ");
            gotoxy(40,16);printf("                                                                           ");
            gotoxy(60,18);printf("                                                                           ");
            gotoxy(40,18);printf("                                                                           ");
            gotoxy(60,20);printf("                                                                           ");
            gotoxy(40,20);printf("                                                                           ");

            edited = edit_field();
            if(modify_record(bookid,1,edited)==0){
                getchar();
                gotoxy(40,33);printf("Book details modified successfully");
                gotoxy(40,35);printf("Press any key to cotinue to main menu....");
                getchar();
                manager_menu();
            }
        }
        else
        {
            gotoxy(40,21);printf("Data does not exist.Please try again");
            getchar();
            gotoxy(60,20);printf("                                                                           ");
            gotoxy(40,21);printf("                                                                           ");
            goto repeat_bookid;
        }
        }
        else if(choice == 2)
        {
            gotoxy(40,19);printf("Enter ISBN No. :");
            fflush(stdout);
        repeat_isbn:
            gotoxy(60,19);scanf("%s",isbn);
            getchar();

        if(data_valid(isbn,3)==1)
        {
            gotoxy(40,11);printf("                                                                           ");
            gotoxy(40,14);printf("                                                                           ");
            gotoxy(40,16);printf("                                                                           ");
            gotoxy(60,18);printf("                                                                           ");
            gotoxy(40,18);printf("                                                                           ");
            gotoxy(60,20);printf("                                                                           ");
            gotoxy(40,20);printf("                                                                           ");

            edited = edit_field();
            if(modify_record(isbn,1,edited)==0){
                getchar();
                gotoxy(40,33);printf("Book details modified successfully");
                gotoxy(40,35);printf("Press any key to cotinue to main menu....");
                getchar();
                manager_menu();
            };

        }
        else
        {
            gotoxy(40,21);printf("Data does not exist.Please try again");
            getchar();
            gotoxy(60,19);printf("                                                                           ");
            gotoxy(40,21);printf("                                                                           ");
            goto repeat_isbn;
        }
        }
        else
        {
            gotoxy(40,19);printf("Invalid Filter. Please select proper filter from the given choice ");
            getchar();
            gotoxy(60,17);printf("                                                                           ");
            gotoxy(40,19);printf("                                                                           ");
            goto repeat;
        }

    return 0;
}

