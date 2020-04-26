#ifndef PAGES_H
#define PAGES_H

struct page {
    char page_title[20];
    char menu[15][50];
    int menu_length;
};

void user_main_menu();
void search_book(void);
void view_my_details(void);

#endif
