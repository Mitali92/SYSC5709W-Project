#include <stdio.h>
#include <errno.h>

int edit_field();

char bookid[20];
int edited;
int choice;
char isbn[20];
char buff[255];

int modify_book()
{
        system(CLEAR);
        header_layout("MODIFY BOOK");

        gotoxy(40,11);printf("Choose the filter to search the book : \n");
        gotoxy(40,14);printf("1. Book ID \n");
        gotoxy(40,15);printf("2. ISBN Number \n");
        gotoxy(40,17);printf("Select the filter : ");
        fflush(stdout);
    repeat:
        gotoxy(60,17);scanf("%d",&choice);
        getchar();

        if(choice == 1)
        {
            gotoxy(40,19);printf("Enter Book ID :");
            fflush(stdout);
            gotoxy(60,19);scanf("%s",bookid);
            getchar();
            display_table(lookup(bookid,1,1));

            int isFound = 0;
    FILE *returnFile = lookup(bookid,1,1);

    while (fgets(buff, 1024, returnFile))
    {
        char *field = strtok(buff, "\",\"");
        if(strcmp(field,bookid)==0)
        {
            isFound = 1;
            break;
        }
        field = strtok(NULL, "\",\"");
        field = strtok(NULL, "\",\"");

        if(strcmp(field,bookid)==0)
        {
            isFound = 1;
            break;
        }
    }

    if(isFound==1)
    {
//        edited = edit_field();
//
//            char *comp_result;
//            char editedValue[255];
//
//            switch (edited)
//            {
//                case 1: gotoxy(40,29);printf("Enter Title");
//                        fflush(stdout);
//                        gotoxy(60,29);scanf("%s",editedValue);
//                        break;
//                case 2: gotoxy(40,29);printf("Enter ISBN No.");
//                        fflush(stdout);
//                        gotoxy(60,29);scanf("%s",editedValue);
//                        break;
//                case 3: gotoxy(40,29);printf("Enter Author Name");
//                        fflush(stdout);
//                        gotoxy(60,29);scanf("%s",editedValue);
//                        break;
//                case 4: gotoxy(40,29);printf("Enter Quantity");
//                        fflush(stdout);
//                        gotoxy(60,29);scanf("%s",editedValue);
//                        break;
//                case 5: gotoxy(40,29);printf("Enter Category");
//                        fflush(stdout);
//                        gotoxy(60,29);scanf("%s",editedValue);
//                        break;
//                case 6: gotoxy(40,29);printf("Enter Language");
//                        fflush(stdout);
//                        gotoxy(60,29);scanf("%s",editedValue);
//                        break;
//                case 7: gotoxy(40,29);printf("Enter Date of Publication");
//                        fflush(stdout);
//                        gotoxy(60,29);scanf("%s",editedValue);
//                        break;
//                case 8: gotoxy(40,29);printf("Status");
//                        fflush(stdout);
//                        gotoxy(60,29);scanf("%s",editedValue);
//                        break;
//               default: gotoxy(40,29);printf("Invalid Filed. Please select proper field from the given choice ");
//                        getchar();
//                        gotoxy(60,29);printf("                                                                           ");
//                        gotoxy(40,32);printf("                                                                           ");
//                        //goto repeat;
//            }
//
//            fflush(stdout);
//            FILE *mainFile =fopen("data/bookdetails.csv","r");
//            if (mainFile == NULL)
//            {
//                switch(errno)
//                {
//                    case ENOENT: printf ("The file doesn't exist\n");
//                                 break;
//                    default: printf("The error number is %d\n", errno);
//                }
//            }
//
//            fflush(stdout);
//
//            FILE *temp =fopen("data/bookdetail.csv","w+");
//            if (temp == NULL)
//            {
//                switch(errno)
//                {
//                    case ENOENT: printf ("The file doesn't exist\n");
//                                 break;
//                    default: printf("The error number is %d\n", errno);
//                }
//            }
//            char buf[255];
//
//            while (fgets(buf, 1024, mainFile))
//            {
//                struct books db_record = file_to_struct(buf);
//
//                if(strcmp(db_record.book_id,bookid)==0)
//                {
//                    switch (edited)
//                    {
//                        case 1: comp_result = strcpy(db_record.book_title, editedValue);
//                                break;
//                        case 2: comp_result = strcpy(db_record.isbn_no, editedValue);
//                                break;
//                        case 3: comp_result = strcpy(db_record.author_name, editedValue);
//                                break;
//                        case 4: comp_result = strcpy(db_record.quantity, editedValue);
//                                break;
//                        case 5: comp_result = strcpy(db_record.category, editedValue);
//                                break;
//                        case 6: comp_result = strcpy(db_record.language, editedValue);
//                                break;
//                        case 7: comp_result = strcpy(db_record.date_of_pub, editedValue);
//                                break;
//                        //case 8: comp_result = strcpy(db_record.status, editedValue);
//                         //       break;
//                        default: gotoxy(40,32);printf("Invalid Filed. Please select proper field from the given choice ");
//                                 getchar();
//                                 gotoxy(60,29);printf("                                                                           ");
//                                 gotoxy(40,32);printf("                                                                           ");
//                                //goto repeat;
//
//                    }
//                    comp_result = strcpy(db_record.book_id, bookid);
//                    comp_result = strcpy(db_record.entry_date, editedValue);
//
//                    if (comp_result != NULL)
//                    {
//                        fprintf(temp, "\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\"\n",
//                        db_record.book_id, db_record.book_title, db_record.isbn_no, db_record.author_name,
//                        db_record.quantity, db_record.category, db_record.language, db_record.date_of_pub,
//                        db_record.entry_date);
//                    }
//                }
//                else
//                {
//                    fprintf(temp, "\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\"\n",
//                    db_record.book_id, db_record.book_title, db_record.isbn_no, db_record.author_name,
//                    db_record.quantity, db_record.category, db_record.language, db_record.date_of_pub,
//                    db_record.entry_date);
//                }
//
//            }
//
//            remove("data/bookdetails.csv");
//            rename("data/bookdetail.csv","data/bookdetails.csv");
        }
        else
        {
            gotoxy(40,21);printf("Data does not exist.Please try again");
            getchar();
            gotoxy(60,17);printf("                                                                           ");
            gotoxy(40,21);printf("                                                                           ");
            gotoxy(60,19);printf("                                                                           ");
            gotoxy(40,19);printf("                                                                           ");
            //goto repeat;
        }
        }
        else if(choice == 2)
        {

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

int edit_field()
{
        int search_field;
        gotoxy(40,17);printf("Choose the field to edit : \n");
        gotoxy(40,19);printf("1. BOOK TITLE ");
        gotoxy(40,20);printf("2. ISBN NO.");
        gotoxy(40,21);printf("3. AUTHOR NAME");
        gotoxy(40,22);printf("3. QUANTITY");
        gotoxy(40,23);printf("5. CATEGORY");
        gotoxy(40,24);printf("6. LANGUAGE");
        gotoxy(40,25);printf("7. DATE OF PUB");
        gotoxy(40,26);printf("8. Status");
        gotoxy(40,27);printf("Select the filter : ");
        fflush(stdout);
        gotoxy(60,27);scanf("%d",&search_field);

        return search_field;
}
