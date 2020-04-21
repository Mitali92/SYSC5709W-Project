void home_menu()
    {
        int selection = 0;
        header_layout("HOME MENU");

        gotoxy(50,15);
        printf("[ 1 ] SIGNUP");
        gotoxy(50,17);
        printf("[ 2 ] LOGIN");
        gotoxy(50,19);
        printf("[ 0 ] CLOSE APPLICATION");
        gotoxy(50,21);
        printf(ANSI_COLOR_YELLOW"\n\n\t\t\t\t\t\t PLEASE ENTER YOUR CHOICE: "ANSI_COLOR_RESET);
    selection_repeat:
        gotoxy(77,23);
        scanf("%d", &selection);
        getchar();

        switch(selection)
             {
                case 1:
                     //sign_up();
                     break;

                case 2:
                    log_in();
                    break;

                case 0:
                    printf("\nEXIT FUNCTION CALLING");
                    //exit(1);
                    break;

                default:
                    gotoxy(50,25);
                    messages(1);
                    getchar();
                    gotoxy(77,23);
                    printf("                                        ");
                    gotoxy(50,25);
                    printf("                                                                                  ");
                    goto selection_repeat;
             }
    }
