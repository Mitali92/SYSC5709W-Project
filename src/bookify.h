#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"


int main(int argc, char *argv[]);

void add_book();
void delete_book();
int modify_book();

extern int a;

//Functions related to pages
struct all_pages init_pages(void);
void user_main_menu(void);
void search_book(void);
void view_my_details(void);
//void display_page(struct page display_data);
void display_table(FILE *return_file);



//FILE *lookup(char search_term[20], int table, int search_field);
//void *file_to_struct(char *line, int type);
