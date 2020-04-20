struct signup new_user;

struct signup
    {
        char name[20];
        char user_name[20];
        char pwd[20];
        char c_pwd[20];
        char email[20];
    };

int char_check(char input[])
    {
        
        int size, x=0;
        size = strlen(input);

        for(int i=0; i <size; i++)
            {
                if((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') || (input[i] == ' '))
                    {
                        continue;
                    }

                else
                    {
                        return 0;
                    }

            }
        return 1;
    }

int pwd_check(char input[])
    {
        int size, x = 0;
        size = strlen(input);

        for(int i=0;i<size;i++)
            {
                if(input[i] == ' ')
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

void sign_up()
    {
        struct signup new_user;

        header_layout("SIGN UP");

        gotoxy(50,11);
        printf("FILL THE BELOW DETAILS:");

// FULL NAME FIELD
        gotoxy(50,14);
        printf("FULL NAME:");
    name_repeat:
        gotoxy(69,14);
        scanf("%s", &new_user.name);
        getchar();
        //validating the user input for FULL NAME field
        if(char_check(new_user.name) == 0)
            {
                gotoxy(45,17);
                messages(2);
                getchar();
                gotoxy(69,14);
                printf("                                                                           ");
                gotoxy(45,17);
                printf("                                                                           ");
                goto name_repeat;
            }

        else if(strlen(new_user.name) >= 20)
            {
                gotoxy(45,17);
                messages(3);
                getchar();
                gotoxy(69,14);
                printf("                                                                           ");
                gotoxy(45,17);
                printf("                                                                           ");
                goto name_repeat;
            }

// USERNAME FIELD
        gotoxy(50,16);
        printf("User name:");
    username_repeat:
        gotoxy(69,16);
        scanf("%s", &new_user.user_name);
        getchar();
        //validating the user input for USER NAME field
        if(char_check(new_user.user_name) == 0)
            {
                gotoxy(45,19);
                messages(4);
                getchar();
                gotoxy(69,16);
                printf("                                                                           ");
                gotoxy(45,19);
                printf("                                                                           ");
                goto username_repeat;
            }

        else if(strlen(new_user.user_name) > 20)
            {
                gotoxy(45,19);
                messages(5);
                getchar();
                gotoxy(69,16);
                printf("                                                                           ");
                gotoxy(45,19);
                printf("                                                                           ");
                goto username_repeat;
            }

// PASSWORD FIELD
        gotoxy(50,18);
        printf("Password:");
    pwd_repeat:
        gotoxy(69,18);
        //validating the user input for PASSWORD field
        int z=0, temp=69;
        char c;
        while(c=getchar())
        {
          if(c == '\n')
          {
              break;
          }
          new_user.pwd[z++]=c;
          gotoxy(temp,18);
          printf("%c",'*');
          temp++;
        }
        new_user.pwd[z]='\0';
        //getchar();

        //validating entered password
        if(pwd_check(new_user.pwd) == 0)
            {
                gotoxy(55,20);
                messages(6);
                getchar();
                gotoxy(69,18);
                printf("                                                                           ");
                gotoxy(55,20);
                printf("                                                                           ");
                goto pwd_repeat;
            }

        else if(strlen(new_user.pwd) > 20)
            {
                gotoxy(55,20);
                messages(7);
                getchar();
                gotoxy(69,18);
                printf("                                                                           ");
                gotoxy(55,20);
                printf("                                                                           ");
                goto pwd_repeat;
            }

// CONFIRM PASSWORD FIELD
        getchar();
        gotoxy(50,20);
        printf("Confirm Password:");
    cnf_pwd_repeat:
        gotoxy(69,20);
        //validating the user input for CONFIRM PASSWORD field
        int y=0, temp2 = 69;
        char d;
        while(d=getchar())
        {
          if(d == '\n')
          {
              break;
          }
          new_user.c_pwd[y++]=d;
          gotoxy(temp2,20);
          printf("%c",'*');
          temp2++;
        }
        //getchar();
        new_user.c_pwd[y]='\0';
        //comparing CONFIRM PASSWORD with PASSWORD field values
        if(strcmp(new_user.pwd, new_user.c_pwd) == 0)
            {
                goto email;
            }

        else
            {
                gotoxy(55,22);
                messages(8);
                getchar();
                gotoxy(55,22);
                printf("                                                                           ");
                gotoxy(69,20);
                printf("                                                                           ");
                gotoxy(50,20);
                printf("                                                                           ");
                gotoxy(69,18);
                printf("                                                                           ");
                goto pwd_repeat;
            }
// EMAIL-ADDRESS FIELD
    email:
        gotoxy(50,22);
        printf("Email address:");
    email_repeat:
        gotoxy(69,22);
        scanf("%s", &new_user.email);
        getchar();

        if(strchr(new_user.email, '.') && strchr(new_user.email, '@'))
            {
                messages(9);
            }

        else
            {
                gotoxy(69,24);
                messages(10);
                getchar();
                gotoxy(69,24);
                printf("                                                                           ");
                gotoxy(69,22);
                printf("                                                                           ");
                goto email_repeat;

            }

        //add_record(new_user);
    }
