#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

// csv file defined on macro
#define charfile1 "D:\\signupdata.csv"
#define charfile2 "D:\\bookdetails.csv"
#define charfile3 "D:\\user.csv"

//function prototype
int main(int argc, char *argv[]);
void gotoxy(int x, int y);
void header_position(const char* screen_name);
void header_layout(const char* screen_name);
void welcome_message();
int add_record(struct books a,int table);

//global variables
COORD coord = {0, 0};
FILE *fa;
char tablestring[255];
int table_num;

