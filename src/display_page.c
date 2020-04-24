//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include "layout.h"
#include "database_lookup.c"
//#include "pages.c"
//#include "database_lookup.c"

//char line[255];
//int maxsize = 255;

void display_page (struct page display_data){
    char selection;
    header_layout(display_data.page_title);


    for(int i = 0; i<display_data.menu_length; i++){
        if(display_data.menu[i] != ""){
                printf("%50s%-s\n","", display_data.menu[i]);
        }
    }
    printf("please select an option: ");
    selection = getchar();


}

void display_table (FILE *return_file){

    system(CLEAR);
    header_layout("SEARCH RESULT");

    char check[5];
    fread(check, 1, 5, return_file);
    rewind(return_file);

    if(strcmp(check, "\"BOOK") == 0){

    while ((fgets(line, maxsize, return_file)) != NULL){

        struct books *db_record = file_to_struct(1);
        printf("    %-6s\t %-18s\t %-12s\t %-12s\t %-12s\t %-12s\t %-12s\t %-12s\n\n",
        db_record->book_id, db_record->book_title, db_record->isbn_no,
        db_record->author_name, db_record->quantity, db_record->category,
        db_record->language, db_record->status);
    }
}else if(strcmp(check, "\"USER") == 0){

    while ((fgets(line, maxsize, return_file)) != NULL){

        struct user *db_record = file_to_struct(2);
        printf("    %-12s\t %-12s\t %-12s\t %-12s\t %-12s\t \n\n",
        db_record->name, db_record->user_name, db_record->password,
        db_record->email, db_record->number_of_books);
}
}else if(strcmp(check, "\"REQU") == 0){

    while ((fgets(line, maxsize, return_file)) != NULL){

        struct request *db_record = file_to_struct(3);
        printf("    %-12s\t %-12s\t \n\n",db_record->user_name, db_record->isbn_no);
}
}
}

/*FILE *return_all(int table){


    system(CLEAR);
    header_layout("SEARCH RESULT");
    while ((fgets(line, maxsize, return_file)) != NULL){

        struct books db_record = file_to_struct();
        printf("    %-6s\t %-18s\t %-12s\t %-12s\t %-12s\t %-12s\t %-12s\n\n",
        db_record.book_id, db_record.book_title, db_record.isbn_no,
        db_record.author_name, db_record.quantity, db_record.category,
        db_record.language);


}*/
