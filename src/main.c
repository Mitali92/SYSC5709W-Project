#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bookify.h"
#include "layout.c"
#include "home_menu.c"
#include "pages.c"
#include "display_page.c"

int main(int argc, char *argv[]){

    if ((argc == 2) && strcmp(argv[1],"-v") == 0){
        printf("Bookify Version 1.0 - Apr 2020\n");
        return 1;
    }

    int user_selection;
    struct all_pages pages = init_pages();

    welcome_message();
    home_menu();
    display_page(pages.manager_main_menu);
    display_table(lookup(" ",1,2));

//     /*
//     // This needs to be put in the welcome message function
//     if (strcmp(getchar(),"q"){
//         exit();
//     };
//     */
//     user_selection = home_menu();
//     if (user_selection() == 1){
//         //display_page(manager_menu);
//         //Handle functions of the manager menu
//         //The display page function needs to check input and recall manager_menu
//         //as needed
//     }else if(user_selection() == 2){
//         //display_page(user_menu);
//         //Handle functions of the user menu
//         //The display page function needs to check input and recall user_menu
//         //as needed
//     };
    return 0;
}
