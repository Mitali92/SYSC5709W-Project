//#include "struct.c"
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
#elif __unix__
    #define BOOKSFILE "data/bookdetails.csv"
    #define USERSFILE "data/users.csv"
    #define REQUESTS "data/requests.csv"
#endif

int add_record(struct books a,int table)
{
    char tablestring[255];
    FILE *fa;
    int table_num;
        switch(table){
                case 1: strcpy(tablestring, BOOKSFILE);
                        break;
                case 2: strcpy(tablestring, USERSFILE);
                        break;
                case 3: strcpy(tablestring, REQUESTS);
                        break;
                default: printf("No match");
        }

        fa = fopen(tablestring,"a");
        if(fa == NULL)
        {
        printf("File is not opened\n");
        exit(1);
        }

	switch(table)
	{
        case 1 : fprintf(fa,"\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\"\n",
                a.book_id,a.book_title,a.isbn_no,a.author_name,a.quantity,
                a.category,a.language,a.date_of_pub,a.entry_date);
                table_num = table;
                break;

        case 2 : printf("replace with sign up struct params");

               //fprintf(fa,"\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\"\n",
                //a.book_id,a.book_title,a.author_name,a.quantity,a.isbn_no,a.category,a.language);
                //table_num = table;
                break;

        case 3 :
                printf("replace with user requests struct params");
               // fprintf(fa,"\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\"\n",
               // a.book_id,a.book_title,a.author_name,a.quantity,a.isbn_no,a.category,a.language);
                //table_num = table;
                break;
        }
        gotoxy(20,20);

        fclose(fa);
        return table_num;;

}
