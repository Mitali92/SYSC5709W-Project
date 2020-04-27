#ifdef __linux__
    #define BOOKSFILE "../data/bookdetails.csv"
    #define USERSFILE "../data/users.csv"
    #define REQUESTS "../data/requests.csv"
    #define BACKUP "../data/bookdetails_backup.csv"
#elif _WIN64 || _WIN32
    #define BOOKSFILE "..\data\bookdetails.csv"
    #define USERSFILE "..\data\users.csv"
    #define REQUESTS "..\data\requests.csv"
    #define BACKUP "..\data\bookdetails_backup.csv"
#elif __APPLE__
    #define BOOKSFILE "../data/bookdetails.csv"
    #define USERSFILE "../data/users.csv"
    #define REQUESTS "../data/requests.csv"
    #define BACKUP "../data/bookdetails_backup.csv"
#elif __unix__
    #define BOOKSFILE "../data/bookdetails.csv"
    #define USERSFILE "../data/users.csv"
    #define REQUESTS "../data/requests.csv"
    #define BACKUP "../data/bookdetails_backup.csv"
#endif

#include <errno.h>
#include<string.h>
#include<stdio.h>
#include <stdlib.h>

#include "layout.h"

int delete_record(char search_term[20], int table,int search_field){

        /**
        * The function delete details to the database for specific table in data set and returns
          the acknowledgement to the calling function.
        * @param[in] search_term 	Term to match in database.
        * @param[in] table 	A number indicating which database table to search.
        * @param[in] search_field 	A number indicating which field of the table to search
        * @param[out] ret	Acknowledge to the calling function if sucessfully deleted in respective csv file.
        */

        char buffer[255];
        int row=0;
        int ret = 0;
        FILE *mainFile =fopen(BOOKSFILE,"r");

        if (mainFile == NULL){
            switch(errno){
                case ENOENT: printf ("The file doesn't exist\n");
                             break;
                    default: printf("The error number is %d\n", errno);
            }
        }

        while (fgets(buffer, 1024, mainFile)){

            char *field = strtok(buffer, "\",\"");
            row++;
            if(strcmp(field,search_term)==0){
                ret = 1;
                break;
            }

        field = strtok(NULL, "\",\"");
        field = strtok(NULL, "\",\"");

            if(strcmp(field,search_term)==0){
                ret = 1;
                break;
            }
        }

        rewind(mainFile);
        if(ret==1){
            FILE *mainBackup =fopen(BACKUP,"w");

            if (mainBackup == NULL) {
                switch(errno){
                    case ENOENT: printf ("The file doesn't exist\n");
                                break;
                    default: printf("The error number is %d\n", errno);
                }
            }

            char bufferNew[255];
            int count=0;

            while (fgets(bufferNew, 1024, mainFile)){
                count++;
                if(count!=row){
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
