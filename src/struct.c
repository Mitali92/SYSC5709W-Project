#ifdef __linux__
    #define BOOKSFILE "data/bookdetails.csv"
    #define USERSFILE "data/users.csv"
    #define REQUESTS "data/requests.csv"
#elif _WIN64 || _WIN32
    #define BOOKSFILE "data\bookdetails.csv"
    #define USERSFILE "data\users.csv"
    #define REQUESTS "data\requests.csv"
#elif __APPLE__
    #define BOOKSFILE "data/bookdetails.csv"
    #define USERSFILE "data/users.csv"
    #define REQUESTS "data/requests.csv"
#endif

#include<stdio.h>
#include <string.h>
#include <windows.h>
#include<time.h>
//#include "add_record.c"

struct pubDate
{
int mm,dd,yy;
};

struct books
{
char book_id[20];
char book_title[50];
char isbn_no[20];
char author_name[50];
char quantity[20];
char category[20];
char language[20];
struct pubDate date_of_pub;
char entry_date[20];
};


struct books a;
COORD coord = {0, 0};
FILE *fa;
char tablestring[255];
int table_num;

time_t current;
struct tm* pLocal;
int choice;



// function prototype
int add_record(struct books a,int table);

void gotoxy (int x, int y)
{
coord.X = x; coord.Y = y; // X and Y coordinates
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


int add_book(){
        int t;
        gotoxy(20,3);printf("Enter the Information Below\n");
        gotoxy(20,4);printf("#####################################################\n");
        gotoxy(20,15);printf("#####################################################\n");
        gotoxy(20,6);printf("Book ID:\t");
        gotoxy(30,6);scanf("%[^\n]%*c",a.book_id);
        gotoxy(20,7);printf("Book Name:");
        gotoxy(30,7);scanf("%[^\n]%*c",a.book_title);
        gotoxy(20,8);printf("Author:");
        gotoxy(30,8);scanf("%[^\n]%*c",a.author_name);
        gotoxy(20,9);printf("Quantity:");
        gotoxy(30,9);scanf("%[^\n]%*c",a.quantity);

        gotoxy(20,10);printf("ISBN No:");
        gotoxy(30,10);scanf("%s",&a.isbn_no);

//        if(lookup(a.isbn_no,2,3)!= NULL){
//            printf("\aThe isbn number already exists\a");
//            printf("Please choose one of the filter to proceed");
//            printf("1. Move to modify page to change isbn number \n");
//            printf("2. Enter new ISBN Number \n");
//            printf("Select the filter : ");
//            scanf("%d",&choice);
//            if(choice == 1){
//                modify_book();
//            }
//            else{
//               main();
//            }
//        }
        gotoxy(20,11);printf("Category:");
        gotoxy(30,11);scanf("%[^\n]%*c",a.category);
        gotoxy(20,12);printf("Language:");
        gotoxy(30,12);scanf("%[^\n]%*c",a.language);

        gotoxy(20,13);printf("Date of Publication (DD-MM-YYYY format):");
        gotoxy(30,13);scanf("%d-%d-%d",&a.date_of_pub.dd,&a.date_of_pub.mm,&a.date_of_pub.yy);

        gotoxy(20,14);printf("Entry Date:");
            time(&current);
            pLocal = localtime(&current);
            strftime(a.entry_date, sizeof(a.entry_date), "%d-%m-%Y", pLocal);
        gotoxy(30,14);puts(a.entry_date);

        add_record(a,2);
        printf("Data saved successfully for table %d\n",table_num);

        return 0;
}




