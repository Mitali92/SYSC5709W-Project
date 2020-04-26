ifeq ($(OS),Windows_NT)
    CCFLAGS += -D WIN32
    ifeq ($(PROCESSOR_ARCHITEW6432),AMD64)
        CCFLAGS += -D AMD64
    else
        ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
            CCFLAGS += -D AMD64
        endif
        ifeq ($(PROCESSOR_ARCHITECTURE),x86)
            CCFLAGS += -D IA32
        endif
    endif
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        CCFLAGS += -D LINUX
    endif
    ifeq ($(UNAME_S),Darwin)
        CCFLAGS += -D OSX
    endif
    UNAME_P := $(shell uname -p)
    ifeq ($(UNAME_P),x86_64)
        CCFLAGS += -D AMD64
    endif
    ifneq ($(filter %86,$(UNAME_P)),)
        CCFLAGS += -D IA32
    endif
    ifneq ($(filter arm%,$(UNAME_P)),)
        CCFLAGS += -D ARM
    endif
endif

EXECUTABLES = main all_tests

CC = gcc
CFLAGS += -I.
DEPS = layout.h add_books.h add_record.h delete_record.h delete_book.h modify_book.h modify_record.h database_lookup.h manager_menu.h sign_up.h log_in.h messages.h home_menu.h display_page.h pages.h



%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(EXECUTABLES)

main: main.o layout.o add_books.o add_record.o delete_record.o delete_book.o modify_book.o modify_record.o database_lookup.o manager_menu.o sign_up.o log_in.o messages.o home_menu.o display_page.o pages.o
	$(CC) -g -o main main.c layout.c add_books.c add_record.c delete_record.c delete_book.c modify_book.c modify_record.c database_lookup.c manager_menu.c sign_up.c log_in.c messages.c home_menu.c display_page.c pages.c

all_tests: test_lookup.o layout.o add_books.o add_record.o delete_record.o delete_book.o modify_book.o modify_record.o database_lookup.o manager_menu.o sign_up.o log_in.o messages.o home_menu.o display_page.o pages.o
	$(CC)  test_lookup.c layout.c add_books.c add_record.c delete_record.c delete_book.c modify_book.c modify_record.c database_lookup.c manager_menu.c sign_up.c log_in.c messages.c home_menu.c display_page.c pages.c -lcheck -lm -lpthread -o all_tests
