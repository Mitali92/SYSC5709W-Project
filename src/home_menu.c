void home_menu()
    {
        int selection = 0;
        header_layout("HOME MENU");

        printf("\n\t\t\t\t\t\t[ 1 ] SIGNUP");
        printf("\n\t\t\t\t\t\t[ 2 ] LOGIN");
        printf("\n\t\t\t\t\t\t[ 0 ] CLOSE APPLICATION");
        printf(ANSI_COLOR_YELLOW"\n\n\t\t\t\t\t\t PLEASE ENTER YOUR CHOICE: "ANSI_COLOR_RESET);
        scanf("%d", &selection);

        switch(selection)
             {
                case 1:
                     sign_up();
                     break;

                case 2:
                    printf("\n LOGIN FUNCTION CALLING");
                    //log_in();
                    break;

                case 0:
                    printf("\nEXIT FUNCTION CALLING");
                    //exit(1);
                    break;

                default:
                    printf("\nINVALID INPUT! PLEASE TRY AGAIN");
             }
    }