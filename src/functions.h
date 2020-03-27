#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int main (int argc, char*argv[]);   
int sign_up (char name[], char username[], char password[], char confirm_password[], char email_address[]);  
int log_in (char username[], char password[]);
void messages (int message_number);
int add_record (struct new_entry, char table[]);  
int delete_record (char search_term[], char table[], char field[]);
int modify_record (char search_term[], char table[], char field[], char new_data[]);
void display_table (char *file_name, FILE **file_pointer);
void display_page (struct display_data);
FILE * database_lookup (char search_term[], char table[], char field[]);
int validate_filter (int filter_entry);
_Noreturn void before_exit (void);

#endif

