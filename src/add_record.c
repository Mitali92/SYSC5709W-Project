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

//int add_record(struct books a,int table) 
int add_record(struct signup new_user,int table) //the first input argument should be updated as UNION
{
    char tablestring[255];
    FILE *fa;
    int status;
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
        case 1 :/*the below lines should be uncommented after add_record is generalized with a UNION input argument 
                fprintf(fa,"\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\"\n",
                a.book_id,a.book_title,a.isbn_no,a.author_name,a.quantity,
                a.category,a.language,a.date_of_pub,a.entry_date);
                status = 1; */
                break;

        case 2 :fprintf(fa,"\"%s\",\"%s\",\"%s\",\"%s\"\n", new_user.name, new_user.user_name, new_user.pwd, new_user.email);
                status = 1;
                break;

        case 3 :
                printf("replace with user requests struct params");
               // fprintf(fa,"\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\"\n",
               // a.book_id,a.book_title,a.author_name,a.quantity,a.isbn_no,a.category,a.language);
               // status = 1;
                break;
        default:
                status = 0;

        }
        gotoxy(20,20);

        fclose(fa);
        return status;

}
