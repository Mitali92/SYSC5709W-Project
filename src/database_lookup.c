
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define num_struct_fields 9

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

};


char line[255];
int maxsize = 255;
const char comma[4] = "\",\"";
char *fields_array[num_struct_fields];

FILE *lookup(char search_term[20], char table[20], int search_field){


// char table will tell which file to open

FILE *dbfile = fopen ("database.csv", "rt");
if (dbfile == NULL){
    switch(errno){
        case ENOENT: printf ("The file doesn't exist\n");
                break;
        default: printf("The error number is %d\n", errno);
    }
}

FILE *returnfile = fopen ("return.csv", "wt");
if (returnfile == NULL){
    switch(errno){
        case ENOENT: printf ("The file doesn't exist\n");
                break;
        default: printf("The error number is %d\n", errno);
    }
}

while ((fgets(line, maxsize, dbfile)) != NULL){

    int i = 0;
    char *field;
    struct books db_record;
    /* get the first token */
    field = strtok(line, comma);
    /* walk through other tokens */
    while(field != NULL ) {

        fields_array[i] = field;
        //printf("%s\n", fields_array[i]);
        i++;
        field = strtok(NULL, comma);
   }

   strcpy(db_record.book_id, fields_array[0]);
   strcpy(db_record.book_title, fields_array[1]);
   strcpy(db_record.isbn_no, fields_array[2]);
   strcpy(db_record.author_name, fields_array[3]);
   strcpy(db_record.quantity, fields_array[4]);
   strcpy(db_record.category, fields_array[5]);
   strcpy(db_record.language, fields_array[6]);
   strcpy(db_record.date_of_pub, fields_array[7]);
   strcpy(db_record.entry_date, fields_array[8]);

   char *comp_result = NULL;
   switch (search_field) {
       case 1: comp_result = strstr(db_record.book_id, search_term);
        break;
       case 2: comp_result = strstr(db_record.book_title, search_term);
        break;
        case 3: comp_result = strstr(db_record.isbn_no, search_term);
         break;
        case 4: comp_result = strstr(db_record.author_name, search_term);
         break;
         case 5: comp_result = strstr(db_record.quantity, search_term);
          break;
         case 6: comp_result = strstr(db_record.category, search_term);
          break;
          case 7: comp_result = strstr(db_record.language, search_term);
           break;
          case 8: comp_result = strstr(db_record.date_of_pub, search_term);
           break;
           case 9: comp_result = strstr(db_record.entry_date, search_term);
            break;
            default: printf("No valid search field passed");
                break;
   }

   if (comp_result != NULL){
      // write the record to file.
       fprintf(returnfile, "\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\"\n",
       db_record.book_id, db_record.book_title, db_record.isbn_no, db_record.author_name,
       db_record.quantity, db_record.category, db_record.language, db_record.date_of_pub,
       db_record.entry_date);

   }
}

fclose(returnfile);
fclose(dbfile);
return returnfile;


/*for(int i=0; i<num_struct_fields; i++){
    printf("%s\n", fields_array[i]);
}*/



}

/*int main(){
    lookup("Bat","Database",2);
    return 0;
}*/
