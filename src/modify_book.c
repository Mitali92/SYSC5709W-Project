#include <stdio.h>
#include <errno.h>
#include "layout.h"

int edit_field();
int int_check(char input[]);

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
            edited = edit_field();

            char *comp_result;
            char editedValue[255];

            switch (edited)
            {
                case 1: gotoxy(40,29);printf("Enter Title");
                        fflush(stdout);
                        gotoxy(60,29);scanf("%s",editedValue);
                        break;
                case 2: gotoxy(40,29);printf("Enter ISBN No.");
                        fflush(stdout);
                        gotoxy(60,29);scanf("%s",editedValue);
                        break;
                case 3: gotoxy(40,29);printf("Enter Author Name");
                        fflush(stdout);
                        gotoxy(60,29);scanf("%s",editedValue);
                        break;
                case 4: gotoxy(40,29);printf("Enter Quantity");
                        fflush(stdout);
                    quantity:
                        gotoxy(60,29);scanf("%s",editedValue);
                        getchar();
                        if(int_check(editedValue)!=0) {
                            gotoxy(40,31);printf("Enter valid quantity");
                            getchar();
                            gotoxy(60,29);printf("                                                                           ");
                            gotoxy(40,31);printf("                                                                           ");
                            goto quantity;
                        }
                        break;
                case 5: gotoxy(40,29);printf("Enter Category");
                        fflush(stdout);
                        gotoxy(60,29);scanf("%s",editedValue);
                        break;
                case 6: gotoxy(40,29);printf("Enter Language");
                        fflush(stdout);
                        gotoxy(60,29);scanf("%s",editedValue);
                        break;
                case 7: gotoxy(40,29);printf("Enter Date of Publication");
                        fflush(stdout);
                        gotoxy(60,29);scanf("%s",editedValue);
                        break;
                case 8: gotoxy(40,29);printf("Status");
                        fflush(stdout);
                        gotoxy(60,29);scanf("%s",editedValue);
                        break;
               default: gotoxy(40,29);printf("Invalid Filed. Please select proper field from the given choice ");
                        getchar();
                        gotoxy(60,29);printf("                                                                           ");
                        gotoxy(40,32);printf("                                                                           ");
                        //goto repeat;
            }
            //actual logic for modification is pending
        }
        else
        {
            gotoxy(40,21);printf("Data does not exist.Please try again");
            getchar();
            gotoxy(60,17);printf("                                                                           ");
            gotoxy(40,21);printf("                                                                           ");
            gotoxy(60,19);printf("                                                                           ");
            gotoxy(40,19);printf("                                                                           ");
            goto repeat;
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
        gotoxy(40,22);printf("4. QUANTITY");
        gotoxy(40,23);printf("5. CATEGORY");
        gotoxy(40,24);printf("6. LANGUAGE");
        gotoxy(40,25);printf("7. DATE OF PUB");
        gotoxy(40,26);printf("8. Status");
        gotoxy(40,27);printf("Select the filter : ");
        fflush(stdout);
        gotoxy(60,27);scanf("%d",&search_field);

        return search_field;
}

int int_check(char input[])
{
    int size, x = 0;
    size = strlen(input);

    for(int i=0;i<size;i++)
    {
      if(input[i]=='0'||input[i]=='1'||input[i]=='2'||input[i]=='3'||input[i]=='5'||input[i]=='6'||input[i]=='7'||input[i]=='8'||input[i]=='9')
      {
           return 0;
      }
      else
      {
           continue;
      }
    }
   return 1;
}
