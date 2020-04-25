#ifndef MODIFY_RECORD_H
#define MODIFY_RECORD_H


#include <errno.h>
#include<string.h>
#include<stdio.h>
#include <stdlib.h>
#include<time.h>

int int_check(char input[]);
int status_check(char input[]);
int date_validation(char input[]);
int modify_record(char search_term[], int table,int search_field);

#endif