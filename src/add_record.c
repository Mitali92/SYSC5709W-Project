int add_record(struct books a,int table)
{
        switch(table){
                case 1: strcpy(tablestring, charfile1);
                        break;
                case 2: strcpy(tablestring, charfile2);
                        break;
                case 3: strcpy(tablestring, charfile3);
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

        case 1 : printf("replace with sign up struct params");

               //fprintf(fa,"\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\"\n",
                //a.book_id,a.book_title,a.author_name,a.quantity,a.isbn_no,a.category,a.language);
                //table_num = table;
                break;
        case 2 : fprintf(fa,"\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%d-%d-%d\,\"%s\",\"%s\",\"%s\",\"%d-%d-%d\"\n",
                a.book_title,a.book_id,a.isbn_no,a.quantity,a.author_name,a.date_of_pub,a.entry_date,a.category,a.language);
                table_num = table;
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
