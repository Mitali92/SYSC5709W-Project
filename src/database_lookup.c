#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

//#include "layout.c"
//#define TYPE books
#define book_struct_fields 10
#define user_struct_fields 5
#define request_struct_fields 2

/**
* The function searches the database for a given search term and returns a file
  with the entries that match.
* @param[in] search_term - term to match in database.
* @param[in] table - A number indicating which database table to search.
* @param[in] search_field - A number indicating which field of the table to search
*/

FILE *lookup(char search_term[20], int table, int search_field);
//struct *file_to_struct(FILE *file);



FILE *dbfile;
FILE *returnfile;
char *comp_result;

struct books{

  char book_id[20];
  char book_title[20];
  char isbn_no[20];
  char author_name[20];
  char quantity[20];
  char category[20];
  char language[20];
  char date_of_pub [20];
  char entry_date[20];
  char status[20];

};

struct user{

  char name[20];
  char user_name[20];
  char email[50];
  char password[20];
  char number_of_books[2];
};

struct request{

  char user_name[20];
  char isbn_no[20];

};

char line[255];
int maxsize = 255;
const char comma[4] = "\",\"";

void *file_to_struct(int type);

void *file_to_struct(int type){

    void *record;

    if(type == 1){

            struct books *db_record = malloc(sizeof(struct books));

            char *fields_array[book_struct_fields];

            int i = 0;
            char *field;
            /* get the first token */
            field = strtok(line, comma);
            /* walk through other tokens */
            while(field != NULL ) {
                fields_array[i] = field;
                i++;
                field = strtok(NULL, comma);
            }

            strcpy(db_record->book_id, fields_array[0]);
            strcpy(db_record->book_title, fields_array[1]);
            strcpy(db_record->isbn_no, fields_array[2]);
            strcpy(db_record->author_name, fields_array[3]);
            strcpy(db_record->quantity, fields_array[4]);
            strcpy(db_record->category, fields_array[5]);
            strcpy(db_record->language, fields_array[6]);
            strcpy(db_record->date_of_pub, fields_array[7]);
            strcpy(db_record->entry_date, fields_array[8]);
            strcpy(db_record->status, fields_array[9]);

            void *record = db_record;
            return record;

    }else if(type == 2){
            struct user *db_record = malloc(sizeof(struct user));
            char *fields_array[user_struct_fields];

            int i = 0;
            char *field;
            /* get the first token */
            field = strtok(line, comma);
            /* walk through other tokens */
            while(field != NULL ) {
                fields_array[i] = field;
                i++;
                field = strtok(NULL, comma);
            }

            strcpy(db_record->name, fields_array[0]);
            strcpy(db_record->user_name, fields_array[1]);
            strcpy(db_record->email, fields_array[2]);
            strcpy(db_record->password, fields_array[3]);
            strcpy(db_record->number_of_books, fields_array[4]);

            void *record = db_record;
            return record;

    }else if(type == 3){
            struct request *db_record = malloc(sizeof(struct request));
            char *fields_array[request_struct_fields];

            int i = 0;
            char *field;
            /* get the first token */
            field = strtok(line, comma);
            /* walk through other tokens */
            while(field != NULL ) {
                fields_array[i] = field;
                i++;
                field = strtok(NULL, comma);
            }

            strcpy(db_record->user_name, fields_array[0]);
            strcpy(db_record->isbn_no, fields_array[1]);

            void *record = db_record;
            return record;
    }

}
//char *set_tablestring(int table);
//char tablestring[255];


/*char *set_tablestring(int table){

    switch(table){
        case 1: strcpy(tablestring, "data/database.csv");
            break;
        case 2: strcpy(tablestring, "data/users.csv");
            break;
        case 3: strcpy(tablestring, "data/database.csv");
            break;
        default: printf("No match");
    }

    return tablestring;

}*/

FILE *lookup(char search_term[20], int table, int search_field){

// int table will tell which file to open
char tablestring[255];
//strcpy(tablestring, set_tablestring(table));
switch(table){
    case 1: strcpy(tablestring, "data/database.csv");
        break;
    case 2: strcpy(tablestring, "data/users.csv");
        break;
    case 3: strcpy(tablestring, "data/database.csv");
        break;
    default: printf("No match");
}

dbfile = fopen (tablestring, "rt");
if (dbfile == NULL){
    switch(errno){
        case ENOENT: printf ("The file doesn't exist\n");
                break;
        default: printf("The error number is %d\n", errno);
    }
}

returnfile = fopen ("data/return.csv", "w+");
if (returnfile == NULL){
    switch(errno){
        case ENOENT: printf ("The file doesn't exist\n");
                break;
        default: printf("The error number is %d\n", errno);
    }
}

switch(table){
    case 1: fprintf(returnfile, "\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\"\n",
    "BOOK ID", "BOOK TITLE", "ISBN NO.", "AUTHOR NAME", "QUANTITY", "CATEGORY",
    "LANGUAGE", "DATE OF PUB", "ENTRY DATE", "STATUS");
    break;
    case 2: fprintf(returnfile, "\"%s\",\"%s\",\"%s\",\"%s\",\"%s\"\n",
    "NAME", "USERNAME", "PASSWORD", "EMAIL", "BOOK COUNT");
    break;
    case 3: fprintf(returnfile, "\"%s\",\"%s\",\"%s\",\"%s\"\n",
    "REQUEST NO.", "ISBN NO.", "USERNAME", "TBD");
    break;

}
//struct *struct_record = file_to_struct(dbfile);
//struct *file_to_struct(FILE *file){

if(table == 1){
    while ((fgets(line, maxsize, dbfile)) != NULL){

        struct books *db_record = file_to_struct(1);
        comp_result = NULL;


       switch (search_field) {
           case 1: comp_result = strstr(db_record->book_id, search_term);
           break;
           case 2: comp_result = strstr(db_record->book_title, search_term);
           break;
           case 3: comp_result = strstr(db_record->isbn_no, search_term);
           break;
           case 4: comp_result = strstr(db_record->author_name, search_term);
           break;
           case 5: comp_result = strstr(db_record->quantity, search_term);
           break;
           case 6: comp_result = strstr(db_record->category, search_term);
           break;
           case 7: comp_result = strstr(db_record->language, search_term);
           break;
           case 8: comp_result = strstr(db_record->date_of_pub, search_term);
           break;
           case 9: comp_result = strstr(db_record->entry_date, search_term);
           break;
           case 10: comp_result = strstr(db_record->status, search_term);
           break;
           default: printf("No valid search field passed");
           break;
       }

       if (comp_result != NULL){
          // write the record to file.

           fprintf(returnfile, "\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\"\n",
           db_record->book_id, db_record->book_title, db_record->isbn_no, db_record->author_name,
           db_record->quantity, db_record->category, db_record->language, db_record->date_of_pub,
           db_record->entry_date, db_record->status);

       }
       free(db_record);

    }
}else if (table == 2){
    while ((fgets(line, maxsize, dbfile)) != NULL){

        struct user *db_record = file_to_struct(2);
        comp_result = NULL;


       switch (search_field) {
           case 1: comp_result = strstr(db_record->name, search_term);
           break;
           case 2: comp_result = strstr(db_record->user_name, search_term);
           break;
           case 3: comp_result = strstr(db_record->password, search_term);
           break;
           case 4: comp_result = strstr(db_record->email, search_term);
           break;
           case 5: comp_result = strstr(db_record->number_of_books, search_term);
           break;
           default: printf("No valid search field passed");
           break;
       }

       if (comp_result != NULL){
          // write the record to file.

           fprintf(returnfile, "\"%s\",\"%s\",\"%s\",\"%s\",\"%s\"\n",
           db_record->name, db_record->user_name, db_record->password,db_record->email,
           db_record->number_of_books);

       }
       free(db_record);

    }
}else if (table == 3){
    while ((fgets(line, maxsize, dbfile)) != NULL){

        struct request *db_record = file_to_struct(3);
        comp_result = NULL;


       switch (search_field) {
           case 1: comp_result = strstr(db_record->user_name, search_term);
           break;
           case 2: comp_result = strstr(db_record->isbn_no, search_term);
           break;
           default: printf("No valid search field passed");
           break;
       }

       if (comp_result != NULL){
          // write the record to file.

           fprintf(returnfile, "\"%s\",\"%s\"\n", db_record->user_name, db_record->isbn_no);

       }
       free(db_record);
    }
}

//fclose(returnfile);
fclose(dbfile);
rewind(returnfile);
return returnfile;



}


/*
int main(){
    //Test run
    //int linesCount = 0;
    char ch;
    char nline[255];

    FILE *file = lookup(" ",1,2);

    //while((fgets(nline, maxsize, file)) != NULL) {
        printf("%s",(fgets(nline, maxsize, file)));
        //if(ch=='\n')
        //linesCount++;
//}
//close the file
fclose(file);
///print number of lines
//printf("Total number of lines are: %d\n",linesCount);

    return 0;
}
*/
