#include "layout.h"
#include "home_menu.h"
#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[]){

    if ((argc == 2) && strcmp(argv[1],"-v") == 0){
        printf("Bookify Version 1.0 - Apr 2020\n");
        return 1;
    }

    welcome_message();
    home_menu();

    return 0;
}
