#include "layout.h"
#include "home_menu.h"

struct login details;

struct login
    {
        char user_name[20];
        char pwd[20];
    };

void log_in()
    {
        struct login details;
        header_layout("LOGIN");

        gotoxy(50,11);
        printf("FILL BELOW DETAILS TO LOGIN:");
        
//USERNAME FIELD
        gotoxy(50,14);
        printf("USER NAME:");
        gotoxy(69,14);
        scanf("%s", &details.user_name);
        getchar();

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
        gotoxy(40,18);
        printf("database-lookup function should be called. \n\n\t\t\tPRESS ENTER TO GO BACK TO HOME MENU");
        getchar();
        home_menu();
    }