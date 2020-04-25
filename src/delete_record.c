#ifdef __linux__
    #define BOOKSFILE "data/bookdetails.csv"
    #define USERSFILE "data/users.csv"
    #define REQUESTS "data/requests.csv"
    #define BACKUP "data/bookdetails_backup.csv"
#elif _WIN64 || _WIN32
    #define BOOKSFILE "data\bookdetails.csv"
    #define USERSFILE "data\users.csv"
    #define REQUESTS "data\requests.csv"
    #define BACKUP "data\bookdetails_backup.csv"
#elif __APPLE__
    #define BOOKSFILE "data/bookdetails.csv"
    #define USERSFILE "data/users.csv"
    #define REQUESTS "data/requests.csv"
    #define BACKUP "data/bookdetails_backup.csv"
#elif __unix__
    #define BOOKSFILE "data/bookdetails.csv"
    #define USERSFILE "data/users.csv"
    #define REQUESTS "data/requests.csv"
    #define BACKUP "data/bookdetails_backup.csv"
#endif

#include "layout.h"

int delete_record(char search_term[20], int table,int search_field)
{

    char buffer[255];
    int row=0;
    int ret = 0;// isFound = false;
    FILE *mainFile =fopen(BOOKSFILE,"r");

    if (mainFile == NULL)
    {
        switch(errno)
        {
            case ENOENT: printf ("The file doesn't exist\n");
                         break;
            default: printf("The error number is %d\n", errno);
        }
    }



    while (fgets(buffer, 1024, mainFile))
    {
        char *field = strtok(buffer, "\",\"");
        row++;
        if(strcmp(field,search_term)==0)
        {
            gotoxy(40,23);printf("Record deleted successfully");
            ret = 1;
            break;
        }

        field = strtok(NULL, "\",\"");
        field = strtok(NULL, "\",\"");

        if(strcmp(field,search_term)==0)
        {
            gotoxy(40,23);printf("Record deleted successfully");
            ret = 1;
            break;
        }
    }


        rewind(mainFile);
        if(ret==1)
        {
            FILE *mainBackup =fopen(BACKUP,"w");

            if (mainBackup == NULL)
            {
                switch(errno)
                {
                    case ENOENT: printf ("The file doesn't exist\n");
                                break;
                    default: printf("The error number is %d\n", errno);
                }
            }

            char bufferNew[255];
            int count=0;

            while (fgets(bufferNew, 1024, mainFile))
            {
                count++;
                if(count!=row)
                {
                    fprintf(mainBackup,"%s",bufferNew);
                }
            }

            remove(BOOKSFILE);
            rename(BACKUP,BOOKSFILE);
            fclose(mainBackup);
        }

        fclose(mainFile);
        return ret;
}
