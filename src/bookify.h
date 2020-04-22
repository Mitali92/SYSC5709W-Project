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
void gotoxy(int x, int y);
void header_position(const char* screen_name);
void header_layout(const char* screen_name);
void welcome_message();
void messages(int msg_id);
void home_menu();
void sign_up();
void log_in();
int pwd_check(char input[]);
int char_check(char input[]);

//Functions related to pages
struct all_pages init_pages(void);
//void display_page (struct page display_data);
void display_table (FILE *return_file);


FILE *lookup(char search_term[20], int table, int search_field);
void *file_to_struct(int type);
