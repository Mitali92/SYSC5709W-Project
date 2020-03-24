#include<stdio.h>
#include <string.h>
#include <windows.h>

struct date
{
    int yyyy;
    int mm;
    int dd;
};

struct books
{
int book_id;
char book_title[20];
int isbn_no;
char author_name[20];
int quantity;
char category[20];
char language[20];
struct date date_of_pub;
struct date entry_date;
};

struct books a;
COORD coord = {0, 0};
FILE *fa;

// function prototype
void add_record(struct books a);

void gotoxy (int x, int y)
{
coord.X = x; coord.Y = y; // X and Y coordinates
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main(){
        int t;
        gotoxy(20,3);printf("Enter the Information Below\n");
        gotoxy(21,6);printf("Book ID:\t");
        gotoxy(30,6);scanf("%d",&a.book_id);
        gotoxy(21,7);printf("Book Name:");
        gotoxy(33,7);scanf("%s",a.book_title);
        gotoxy(21,8);printf("Author:");
        gotoxy(30,8);scanf("%s",a.author_name);
        gotoxy(21,9);printf("Quantity:");
        gotoxy(31,9);scanf("%d",&a.quantity);
        gotoxy(21,10);printf("ISBN No:");
        gotoxy(28,10);scanf("%d",&a.isbn_no);
        gotoxy(21,11);printf("Category:");
        gotoxy(30,11);scanf("%s",a.category);
        gotoxy(21,12);printf("Language:");
        gotoxy(30,12);scanf("%s",a.language);

        add_record(a);

        return 0;
}

void add_record(struct books a)
{
        fa = fopen("D:\\test.txt","ab+");
        if(fa == NULL)
        {
        printf("File is not opened\n");
        exit(1);
        }
        fprintf(fa, "\n");
        fwrite(&a,sizeof(a),1,fa);
        //fprintf(fa," \nBook Name : %s\n Book Id : %u\n Author Name : %s",a.book_title,a.book_id,a.author_name);
        gotoxy(21,14);
        printf("The Record Is Sucessfully Saved\n");

        fclose(fa);

}


