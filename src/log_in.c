#include <stdio.h>
#include <stdlib.h>     //used for - system(CLEAR)
#include <string.h>

#include "layout.h"
#include "home_menu.h"
#include "database_lookup.h"
#include "manager_menu.h"
#include "pages.h"

struct login
    {
        char user_name[20];
        char pwd[20];
    };

void log_in()
    {
        /**
        * The function displays LOGIN page, takes user inputs, calls and validates it from users.csv file
        * IF USER INPUT IS VALID   --- displays either USER-menu or MANAGER-menu, based on the login details entered
        * IF USER INPUT IS INVALID --- prints respective error message and continues to take new input
        * @param[in] void
        * @param[out] void
        */
        struct login details;
        header_layout("LOGIN");

        gotoxy(50,11);
        printf("FILL BELOW DETAILS TO LOGIN:");

        //USERNAME FIELD
                gotoxy(50,14);
                printf("USER NAME:");
            username_repeat:
                gotoxy(69,14);
                scanf("%s", &details.user_name);
                getchar();
                for(int k=0;k<strlen(details.user_name);k++)
                    {
                        if(details.user_name[k] == '\n')
                            {
                                gotoxy(50,16);
                                printf("INVALID USERNAME. PRESS ENTER TO TRY AGAIN");
                                getchar();
                                gotoxy(50,16);
                                printf("                                                   ");
                                gotoxy(69,14);
                                printf("                                                   ");
                                goto username_repeat;
                            }
                    }

//PASSWORD FIELD
        gotoxy(50,16);
        printf("PASSWORD:");
        gotoxy(69,16);
        int u=0, temp=69;
        char b;
        while(b=getchar())
        {
          if(b == '\n')
          {
              break;
          }
          details.pwd[u++]=b;
          gotoxy(temp,16);
          printf("%c",'*');
          temp++;
        }
        details.pwd[u]='\0';
        getchar();

//validating login details - calling database_lookup function
        char line[255];
		int i = 0;
        //struct user *usr = malloc(sizeof(struct user));
		FILE *fp = lookup(details.user_name, 2, 2);
		struct user *usr;
        while (fgets(line, 255, fp) != NULL){

			usr = file_to_struct(line, 2);

        };

        if((strcmp(details.user_name, "admin") == 0) && (strcmp(details.pwd, "admin123") == 0))
            {
                manager_menu();
            }

        else if((strcmp(details.user_name, usr->user_name) == 0) && (strcmp(details.pwd, usr->password) == 0))
            {
                user_main_menu();
            }

        else
            {
			   printf("\n\n\t\t\tPRESS ENTER TO TRY AGAIN");
			   getchar();
			   log_in();
		    }

    }
