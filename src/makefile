CC=gcc
CFLAGS=-I.
DEPS = layout.h add_books.h add_record.h delete_record.h delete_book.h modify_book.h modify_record.h database_lookup.h manager_menu.h sign_up.h log_in.h messages.h home_menu.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: main.o layout.o add_books.o add_record.o delete_record.o delete_book.o modify_book.o modify_record.o database_lookup.o manager_menu.o sign_up.o log_in.o messages.o home_menu.o
	$(CC) -o main main.o layout.o add_books.o add_record.o delete_record.o delete_book.o modify_book.o modify_record.o database_lookup.o manager_menu.o sign_up.o log_in.o messages.o home_menu.o
	