#ifdef __linux__
    #define CLEAR "clear"
#elif _WIN64 || _WIN32
    #define CLEAR "cls"
#elif __APPLE__
    #define CLEAR "clear"
#elif __unix__
    #define CLEAR "clear"
#endif

#include<stdio.h>
#include<string.h>
#include<time.h>
#include <stdlib.h>

// function prototype
int add_record(void *struct_data,int table);
int validation(char isbn[20]);
int modify_book();
int increment_id();

time_t current;
struct tm* pLocal;
int choice;

void add_book()
{
        struct books *a = malloc(sizeof(struct books));

        system(CLEAR);
        header_layout("ADD BOOK");

        gotoxy(40,11);printf("ENTER BELOW DETAILS:");

         //fields for the adding book
        gotoxy(40,14);printf("Book ID:");
            int increment = increment_id();
            //converting int into char array
            snprintf(a->book_id, sizeof(20), "%d", increment);
        gotoxy(59,14);printf("%s",a->book_id);

        gotoxy(40,16);printf("Book Name:");

    new_book:
        gotoxy(59,16);scanf("%[^\n]%*c",a->book_title);
        gotoxy(40,18);printf("Author:");
        gotoxy(59,18);scanf("%[^\n]%*c",a->author_name);
        gotoxy(40,20);printf("Quantity:");
        gotoxy(59,20);scanf("%[^\n]%*c",a->quantity);

        gotoxy(40,22);printf("ISBN No:");
   isbn_repeat:
        gotoxy(59,22);scanf("%[^\n]%*c",a->isbn_no);
        fflush(stdout);

        //duplicate isbn validation check from the database table
        if(validation(a->isbn_no)==1)
        {
            gotoxy(45,24);printf("The isbn number already exists\n");
            gotoxy(45,25);printf("Please choose one of the filter to proceed");
            gotoxy(45,26);printf("1. Move to modify page to change isbn number ");
            gotoxy(45,27);printf("2. Enter new ISBN Number ");

            gotoxy(45,28);printf("Select the filter : ");
            gotoxy(69,28);scanf("%d",&choice);

            if(choice == 1)
            {
                modify_book();
            }
            else if(choice == 2)
            {
                gotoxy(59,22);printf("                                                                           ");
                gotoxy(45,24);printf("                                                                           ");
                gotoxy(45,25);printf("                                                                           ");
                gotoxy(45,26);printf("                                                                           ");
                gotoxy(45,27);printf("                                                                           ");
                gotoxy(45,28);printf("                                                                           ");
                gotoxy(59,28);printf("                                                                           ");
                getchar();
                goto isbn_repeat;
            }
            else
            {
                gotoxy(45,30);printf("Invalid filter.Please try again");
                getchar();
                gotoxy(59,16);printf("                                                                           ");
                gotoxy(45,30);printf("                                                                           ");
                gotoxy(40,18);printf("                                                                           ");
                gotoxy(59,18);printf("                                                                           ");
                gotoxy(40,20);printf("                                                                           ");
                gotoxy(69,20);printf("                                                                           ");
                gotoxy(40,22);printf("                                                                           ");
                gotoxy(59,22);printf("                                                                           ");
                gotoxy(45,24);printf("                                                                           ");
                gotoxy(45,25);printf("                                                                           ");
                gotoxy(45,26);printf("                                                                           ");
                gotoxy(45,27);printf("                                                                           ");
                gotoxy(45,28);printf("                                                                           ");
                gotoxy(59,28);printf("                                                                           ");
                goto new_book;
            }
        }

        gotoxy(40,24);printf("Category:");
        gotoxy(59,24);scanf("%[^\n]%*c",a->category);
        gotoxy(40,26);printf("Language:");
        gotoxy(59,26);scanf("%[^\n]%*c",a->language);

        gotoxy(40,28);printf("Date of Publication (DD-MM-YYYY format):");
        gotoxy(82,28);scanf("%s",a->date_of_pub);

        gotoxy(40,30);printf("Entry Date : ");

            time(&current);
            pLocal = localtime(&current);
            strftime(a->entry_date, sizeof(a->entry_date), "%d-%m-%Y", pLocal);

        gotoxy(59,30);puts(a->entry_date);

        gotoxy(40,32);printf("Status:");
        gotoxy(59,32);scanf("%s",a->status);
        //strcpy(a->status,"Available");

        void *struct_data = a;

        if(add_record(struct_data,1) == 1)
        {
             gotoxy(40,34);printf("Book added successfully");
             gotoxy(40,36);printf("Press any key to continue to main menu...");
             getchar();
             //home_menu();
        }
        else
        {
            printf("Error in saving details");
        }
}

//isbn validation from database
int validation(char isbn[20])
{
     char buffer[255];
     int ret = 0;
     FILE *mainFile =fopen("data/bookdetails.csv","r");

     if(mainFile != NULL)
     {
        while (fgets(buffer, 1024, mainFile))
        {
            char *field = strtok(buffer, "\",\"");

            field = strtok(NULL, "\",\"");
            field = strtok(NULL, "\",\"");

                if(strcmp(field,isbn)==0)
                {
                    ret = 1;
                    break;
                }
         }
      }

  return ret;
}

//bookid increment in database whenever new book details are entered
int increment_id()
{
     struct books *a = malloc(sizeof(struct books));
     char buf[255];
     char *field;
     int increment;

     FILE *mainFile =fopen("data/bookdetails.csv","r");

     if (mainFile == NULL)
     {
       switch(errno)
       {
           case ENOENT: printf ("The file doesn't exist\n");
                        break;
               default: printf("The error number is %d\n", errno);
       }
     }

      while (fgets(buf, 1024, mainFile))
      {
         field = strtok(buf, "\",\"");

      }
      field = strtok(buf, "\",\"");
      increment = atoi(field)+1;

    return increment;

}



