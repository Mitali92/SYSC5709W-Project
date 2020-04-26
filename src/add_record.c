#ifdef __linux__
    #define BOOKSFILE "../data/bookdetails.csv"
    #define USERSFILE "../data/users.csv"
    #define REQUESTS "../data/requests.csv"
#elif _WIN64 || _WIN32
    #define BOOKSFILE "..\data\bookdetails.csv"
    #define USERSFILE "..\data\users.csv"
    #define REQUESTS "..\data\requests.csv"
#elif __APPLE__
    #define BOOKSFILE "../data/bookdetails.csv"
    #define USERSFILE "../data/users.csv"
    #define REQUESTS "../data/requests.csv"
#elif __unix__
    #define BOOKSFILE "../data/bookdetails.csv"
    #define USERSFILE "../data/users.csv"
    #define REQUESTS "../data/requests.csv"
#endif

#include <errno.h>
#include<string.h>
#include<stdio.h>
#include <stdlib.h>
#include<time.h>

#include "database_lookup.h"

int add_record(void *struct_data,int table){

     /**
     * The function add details to the database for specific table in data set and returns
       the acknowledgement to the calling function.
     * @param[in] *data  passing a pointer to struct data into generic function to be entered into database.
     * @param[in] table  A number indicating which database table to add.
     * @param[out] isValid Acknowledge to the calling function if sucessfully added in respective csv file.
     */

     char tablestring[255];
     FILE *fa;
     int isValid;

     struct books *book;
     struct user *user;
     struct request *request;

     if(table == 1){
        book = struct_data;
     }
     else if(table == 2){
        user = struct_data;
     }
     else if(table == 3){
        request = struct_data;
     }

     switch(table){
        case 1: strcpy(tablestring, BOOKSFILE);
                break;
        case 2: strcpy(tablestring, USERSFILE);
                break;
        case 3: strcpy(tablestring, REQUESTS);
                break;
        default: printf("No match");
     }

     fa = fopen(tablestring,"a");

     if(fa == NULL){
        printf("File is not opened\n");
        exit(1);
     }

	 switch(table){
        case 1:   fprintf(fa,"\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\"\n",
                  book->book_id,book->book_title,book->isbn_no,book->author_name,book->quantity,
                  book->category,book->language,book->date_of_pub,book->entry_date,book->status);
                  isValid = 1;
                  break;

        case 2 :  fprintf(fa,"\"%s\",\"%s\",\"%s\",\"%s\",\"%s\"\n",
                  user->name,user->user_name,user->password,user->email,user->number_of_books);
                  isValid = 1;
                  break;

        case 3 :  fprintf(fa,"\"%s\",\"%s\"\n",request->user_name,request->isbn_no);
                  isValid = 1;
                  break;

        default : printf("No match");
                  isValid = 0;
     }

    fclose(fa);
    return isValid;
}
