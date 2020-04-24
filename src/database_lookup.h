#ifndef DATABASE_LOOKUP_H
#define DATABASE_LOOKUP_H

FILE *lookup(char search_term[20], int table, int search_field);
void *file_to_struct(char *line, int type);

#endif
