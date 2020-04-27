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

#include <errno.h>
#include<string.h>
#include<stdio.h>
#include <stdlib.h>
#include<time.h>

#include "layout.h"
#include "database_lookup.h"
#include "messages.h"

int int_check(char input[]){

     /**
     * The function validates if the character array contains only integers
     * @param[in] input[] the user input in the filed
     * @param[out] int based on the validation, either 0 or 1 will be returned by this function
     */

    int size, x = 0;
    size = strlen(input);

    for(int i=0;i<size;i++){
      if(input[i]=='0'||input[i]=='1'||input[i]=='2'||input[i]=='3'||input[i]=='4'||input[i]=='5'||input[i]=='6'||input[i]=='7'||input[i]=='8'||input[i]=='9'){
           return 0;
      }
      else{
           continue;
      }
    }
   return 1;
}

int status_check(char input[]){

    /**
     * The function validates if the character array contains specific - Available or Unavailable
     * @param[in] input[] the user input in the filed
     * @param[out] int based on the validation, either 0 or 1 will be returned by this function
     */

    int ret = 1;
      if(strcmp(input,"Available")==0 || strcmp(input,"UnAvailable")==0 || strcmp(input,"unavailable")==0 || strcmp(input,"available")==0){
           ret = 0;
      }
      else{
           ret = 1;
      }
   return ret;
}

int date_validation(char input[]){

    /**
     * The function validates if the character array contains valid date
     * @param[in] input[] the user input in the filed
     * @param[out] int based on the validation, either 0 or 1 will be returned by this function
     */

    int status = 1;

    char * pch;
    pch = strtok (input,"-");
    int arr[4];

    int index=0;
    arr[index]=atoi(pch);
    index++;

    while (pch != NULL){
        pch = strtok (NULL, "-");

        if(pch != NULL){
            arr[index]=atoi(pch);
            index++;
        }
    }

    int dd=arr[0];
    int mm=arr[1];
    int yy=arr[2];
    //check year
    if(yy>=1900 && yy<=9999){
        //check month
        if(mm>=1 && mm<=12){
            //check days
            if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12)){
                gotoxy(40,33);printf("Date is valid.");
                status = 0;
            }
            else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11)){
                gotoxy(40,33);printf("Date is valid.");
                status = 0;
            }
            else if((dd>=1 && dd<=28) && (mm==2)){
                gotoxy(40,33);printf("Date is valid.");
                status = 0;
            }
            else if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0))){
                gotoxy(40,33);printf("Date is valid.");
                status = 0;
            }
            else{
                gotoxy(40,34);printf("Day is invalid.");
                status = 1;
            }
        }
        else{
            gotoxy(40,34);printf("Month is not valid.");
            status = 1;
        }
    }
    else{
        //printf("Year is not valid.\n");
        status = 1;
    }
 return status;
}

int modify_record(char search_term[], int table,int search_field){

    /**
    * The function modify the book details using book_id or isbn_no
    * @param[in] search_term 	Term to match in database.
    * @param[in] table 	A number indicating which database table to search.
    * @param[in] search_field 	A number indicating which field of the table to search
    * @param[out] ret	Acknowledge to the calling function if sucessfully modified in respective csv file.
    */

    char *comp_result;
    char editedValue[255];

    switch (search_field){
            case 1: gotoxy(40,31);printf("Enter Title :");
                    fflush(stdout);
                    gotoxy(60,31);scanf("%s",editedValue);
                    break;
            case 2: gotoxy(40,31);printf("Enter ISBN No :");
                    fflush(stdout);
                    gotoxy(60,31);scanf("%s",editedValue);
                    break;
            case 3: gotoxy(40,31);printf("Enter Author Name : ");
                    fflush(stdout);
                    gotoxy(60,31);scanf("%s",editedValue);
                    break;
            case 4: gotoxy(40,31);printf("Enter Quantity : ");
                    fflush(stdout);
                quantity:
                    gotoxy(60,31);scanf("%s",editedValue);
                    getchar();
                    if(int_check(editedValue)!=0) {
                        gotoxy(40,33);printf(ANSI_COLOR_RED"Enter valid quantity....!!!"ANSI_COLOR_RESET);
                        getchar();
                        gotoxy(60,31);printf("                                                                           ");
                        gotoxy(40,33);printf("                                                                           ");
                        goto quantity;
                    }
                    break;
            case 5: gotoxy(40,31);printf("Enter Category : ");
                    fflush(stdout);
                    gotoxy(60,31);scanf("%s",editedValue);
                    break;
            case 6: gotoxy(40,31);printf("Enter Language : ");
                    fflush(stdout);
                    gotoxy(60,31);scanf("%s",editedValue);
                    break;
            case 7: gotoxy(40,31);printf("Enter Date of Publication (DD-MM-YYYY):");
                    fflush(stdout);
                repeat_dateOfPub:
                    gotoxy(80,31);scanf("%s",editedValue);
                    getchar();
                    if(date_validation(editedValue)!=0) {
                        gotoxy(40,33);printf(ANSI_COLOR_RED"Enter valid date....!!!"ANSI_COLOR_RESET);
                        getchar();
                        gotoxy(80,31);printf("                                                                           ");
                        gotoxy(40,33);printf("                                                                           ");
                        gotoxy(40,34);printf("                                                                           ");
                        goto repeat_dateOfPub;
                    }
                    break;
            case 8: gotoxy(40,31);printf("Status :");
                    fflush(stdout);
                repeat_status:
                    gotoxy(60,31);scanf("%s",editedValue);
                    getchar();
                    if(status_check(editedValue)!=0) {
                        gotoxy(40,33);printf(ANSI_COLOR_RED"Enter valid status....!!!"ANSI_COLOR_RESET);
                        getchar();
                        gotoxy(60,31);printf("                                                                           ");
                        gotoxy(40,33);printf("                                                                           ");
                        goto repeat_status;
                    }
                    break;
            default: gotoxy(40,31);messages(1);
                     getchar();
                     gotoxy(60,31);printf("                                                                           ");
                     gotoxy(40,33);printf("                                                                           ");
                    //goto repeat;
    }

    fflush(stdout);
    FILE *mainFile =fopen(BOOKSFILE,"r");
    if (mainFile == NULL){

        switch(errno){
            case ENOENT: printf ("The file doesn't exist\n");
                         break;
                default: printf("The error number is %d\n", errno);
        }
    }

    fflush(stdout);

    FILE *temp =fopen(BACKUP,"w+");
    if (temp == NULL){
        switch(errno){
            case ENOENT: printf ("The file doesn't exist\n");
                         break;
                default: printf("The error number is %d\n", errno);
        }
    }

    char buf[255];

    while (fgets(buf, 1024, mainFile)){
            struct books *db_record = file_to_struct(buf,1);

            if(strcmp(db_record->isbn_no,search_term)==0 || strcmp(db_record->book_id,search_term)==0){

                    switch (search_field){
                        case 1: comp_result = strcpy(db_record->book_title, editedValue);
                                break;
                        case 2: comp_result = strcpy(db_record->isbn_no, editedValue);
                                break;
                        case 3: comp_result = strcpy(db_record->author_name, editedValue);
                                break;
                        case 4: comp_result = strcpy(db_record->quantity, editedValue);
                                break;
                        case 5: comp_result = strcpy(db_record->category, editedValue);
                                break;
                        case 6: comp_result = strcpy(db_record->language, editedValue);
                                break;
                        case 7: comp_result = strcpy(db_record->date_of_pub, editedValue);
                                break;
                        case 8: comp_result = strcpy(db_record->status, editedValue);
                                break;
                        default: gotoxy(40,32);messages(1);
                                 getchar();
                                 gotoxy(60,29);printf("                                                                           ");
                                 gotoxy(40,32);printf("                                                                           ");
                                //goto repeat;
                    }

                    if (comp_result != NULL){
                        fprintf(temp, "\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\"\n",
                        db_record->book_id, db_record->book_title, db_record->isbn_no, db_record->author_name,
                        db_record->quantity, db_record->category, db_record->language, db_record->date_of_pub,
                        db_record->entry_date,db_record->status);
                    }
            }
            else{
                fprintf(temp, "\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\"\n",
                db_record->book_id, db_record->book_title, db_record->isbn_no, db_record->author_name,
                db_record->quantity, db_record->category, db_record->language, db_record->date_of_pub,
                db_record->entry_date,db_record->status);
                }
   }

            remove(BOOKSFILE);
            rename(BACKUP,BOOKSFILE);

   fclose(temp);
   fclose(mainFile);
   return 0;
}

