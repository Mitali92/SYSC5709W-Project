int add_record(struct books a,int table)
{

        char tablestring[255];

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

        case 1 : fprintf(fa,"\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\"\n",
                a.book_id,a.book_title,a.author_name,a.quantity,a.isbn_no,a.category,a.language);
                table_num = table;
                break;
        case 2 : fprintf(fa,"\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\"\n",
                a.book_id,a.book_title,a.author_name,a.quantity,a.isbn_no,a.category,a.language);
                table_num = table;
                break;
        case 3 : fprintf(fa,"\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\"\n",
                a.book_id,a.book_title,a.author_name,a.quantity,a.isbn_no,a.category,a.language);
                table_num = table;
                break;
	}
        gotoxy(20,16);

        fclose(fa);
        return table_num;;

}
