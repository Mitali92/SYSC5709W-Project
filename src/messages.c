void messages(int msg_id)
    {
        switch(msg_id)
            {
                case 1:
                    printf(ANSI_COLOR_RED"INVALID INPUT! PLEASE PRESS ENTER TO TRY AGAIN"ANSI_COLOR_RESET);
                    break;
                
                case 2:
                    printf(ANSI_COLOR_RED"INVALID NAME! PLEASE PRESS ENTER TO TRY AGAIN"ANSI_COLOR_RESET);
                    break;

                case 3:
                    printf(ANSI_COLOR_RED"NAME CANNOT BE MORE THAN 20 CHARACTERS. PLEASE PRESS ENTER TO TRY AGAIN"ANSI_COLOR_RESET);
                    break;

                case 4:
                    printf(ANSI_COLOR_RED"INVALID USERNAME. PLEASE PRESS ENTER TO TRY AGAIN"ANSI_COLOR_RESET);
                    break;
                
                case 5:
                    printf(ANSI_COLOR_RED"NAME CANNOT BE MORE THAN 20 CHARACTERS. PLEASE PRESS ENTER TO TRY AGAIN"ANSI_COLOR_RESET);
                    break;

                case 6:
                    printf(ANSI_COLOR_RED"INVALID PASSWORD. PLEASE PRESS ENTER TO TRY AGAIN"ANSI_COLOR_RESET);
                    break;

                case 7:
                    printf(ANSI_COLOR_RED"PASSWORD CANNOT BE MORE THAN 20 CHARACTERS. PLEASE PRESS ENTER TO TRY AGAIN"ANSI_COLOR_RESET);
                    break;

                case 8:
                    printf(ANSI_COLOR_RED"PASSWORD MIS-MATCH. PLEASE PRESS ENTER TO TRY AGAIN"ANSI_COLOR_RESET);
                    break;

                case 9:
                    printf(ANSI_COLOR_RED"\n\t\t\t SIGNUP SUCCESSFUL. NEED TO LINK ADD_RECORD FUNCTION HERE"ANSI_COLOR_RESET);
                    break;

                case 10:
                    printf(ANSI_COLOR_RED"INVALID EMAIL ADDRESS. PLEASE PRESS ENTER TO TRY AGAIN"ANSI_COLOR_RESET);
                    break;

                default:
                    printf("ARE YOU SURE YOU WANT TO EXIT ? (Y/N)");
                    break;
            }   
    }