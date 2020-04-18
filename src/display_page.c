//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include "layout.c"
//#include "database_lookup.c"
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

    //system(CLEAR);
    header_layout("SEARCH RESULT");
    /*while ((fgets(line, maxsize, return_file)) != NULL){

        struct books db_record = file_to_struct();
        printf("    %-6s\t %-18s\t %-12s\t %-12s\t %-12s\t %-12s\t %-12s\n\n",
        db_record.book_id, db_record.book_title, db_record.isbn_no,
        db_record.author_name, db_record.quantity, db_record.category,
        db_record.language);
 }*/
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
