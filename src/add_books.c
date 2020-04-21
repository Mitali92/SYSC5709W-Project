#include<stdio.h>
#include<string.h>
<<<<<<< HEAD
#include<time.h>

struct books a;
=======
//#include<windows.h>
#include<time.h>

struct books a;
//COORD coord = {0, 0};
>>>>>>> Implement_more_structs
FILE *fa;
char tablestring[255];

time_t current;
struct tm* pLocal;
int choice;

// function prototype
int add_record(struct books a,int table);

int add_book(){

        int t;
        system(CLEAR);
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
        gotoxy(30,10);scanf("%[^\n]%*c",a.isbn_no);

//        if(lookup(a.isbn_no,1,3)){
//                printf("add data");
//            }
//        else{
//            printf("\aThe isbn number already exists\a");
//            printf("Please choose one of the filter to proceed");
//            printf("1. Move to modify page to change isbn number \n");
//            printf("2. Enter new ISBN Number \n");
//            printf("Select the filter : ");
//            scanf("%d",&choice);
//            if(choice == 1){
//                    printf("modify");
//                //modify_book();
//            }
//            else{
//                printf("add again");
//               //main();
//            }
  //          printf("already");
            //return 0;
//        }
        gotoxy(20,11);printf("Category:");
        gotoxy(30,11);scanf("%[^\n]%*c",a.category);
        gotoxy(20,12);printf("Language:");
        gotoxy(30,12);scanf("%[^\n]%*c",a.language);

        gotoxy(20,13);printf("Date of Publication (DD-MM-YYYY format):");
        gotoxy(60,13);scanf("%s",a.date_of_pub);

        gotoxy(20,14);printf("Entry Date : ");
            time(&current);
            pLocal = localtime(&current);
            strftime(a.entry_date, sizeof(a.entry_date), "%d-%m-%Y", pLocal);
        gotoxy(30,14);puts(a.entry_date);

        if(add_record(a,1) == 1){
             printf("Data saved successfully for Book Details");
        }
        else{
            printf("Error in saving details");
        }
        return 0;
}
