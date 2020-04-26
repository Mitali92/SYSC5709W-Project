#ifndef DATABASE_LOOKUP_H
#define DATABASE_LOOKUP_H

#include<stdio.h>
#include<string.h>
#include<time.h>
#include <stdlib.h>
#include <errno.h>

FILE *lookup(char search_term[20], int table, int search_field);
void *file_to_struct(char *line, int type);

struct books{

  char book_id[20];
  char book_title[20];
  char isbn_no[20];
  char author_name[20];
  char quantity[20];
  char category[20];
  char language[20];
  char date_of_pub [20];
  char entry_date[20];
  char status[20];

};

struct user{

  char name[20];
  char user_name[20];
  char email[50];
  char password[20];
  char number_of_books[2];
};

struct request{

  char user_name[20];
  char isbn_no[20];

};




#endif
