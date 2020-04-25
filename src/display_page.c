//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include "layout.c"
#include "database_lookup.h"

//#include "pages.c"
//#include "database_lookup.c"


//struct all_pages setup_pages(void);
//global struct all_pages pages;
//void setup_pages(){
//struct all_pages pages = init_pages();

//}

//void display_page(struct page display_data);

void display_page(struct page display_data){

    /**
    * The function take a page struct and prints it to the screen
    * @param[in] display_data 	struct containing data for the page.
    */


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

    /**
    * The function takes a csv file, reads the lines and prints them to the
        console formatted as a table.
    * @param[in] return_file 	file from which data for table is to be read
    */

    system(CLEAR);
    header_layout("SEARCH RESULT");

    char line[255];
    int maxsize = 255;
    char check[5] = {0,0,0,0,0};
    fread(check, 1, 5, return_file);
    rewind(return_file);
    check[strcspn(check, "v")] = 0;
    
    if(strcmp(check, "\"BOOK") == 0){

    while ((fgets(line, maxsize, return_file)) != NULL){

        struct books *db_record = file_to_struct(line, 1);
        printf("    %-6s\t %-18s\t %-12s\t %-12s\t %-12s\t %-12s\t %-12s\t %-12s\n\n",
        db_record->book_id, db_record->book_title, db_record->isbn_no,
        db_record->author_name, db_record->quantity, db_record->category,
        db_record->language, db_record->status);
		free(db_record);
    }
}else if(strcmp(check, "\"NAME") == 0){

    while ((fgets(line, maxsize, return_file)) != NULL){
		//printf("here");
        struct user *db_record = file_to_struct(line, 2);

        printf("    %-10s\t %-12s\t %-12s\t %-36s\t %-12s\t \n\n",
        db_record->name, db_record->user_name, db_record->password,
        db_record->email, db_record->number_of_books);
		free(db_record);
}
}else if(strcmp(check, "\"REQU") == 0){

    while ((fgets(line, maxsize, return_file)) != NULL){

        struct request *db_record = file_to_struct(line, 3);
        printf("    %-12s\t %-12s\t \n\n",db_record->user_name, db_record->isbn_no);
		free(db_record);
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
