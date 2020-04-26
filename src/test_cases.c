//#include </usr/local/Cellar/check/0.14.0/include/check.h>
//#include </usr/local/Cellar/check/0.14.0/include/check_stdint.h>
#ifdef __APPLE__
    #include </usr/local/Cellar/check/0.14.0/include/check.h>
#else
    #include <check.h>
#endif


#include "database_lookup.h"
#include "add_books.h"
#include "sign_up.h"
#include "modify_book.h"
#include "modify_record.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>



////////////// AISHA's TESTS ***************
START_TEST(test_long_search_term) {

  FILE *result;

  result = lookup("Thisstringiswaytoolong",1,2);

} END_TEST

START_TEST(test_table_ofb) {

  FILE *result;

  result = lookup("Bat",5,2);

} END_TEST

START_TEST(test_searchfield_ofb_1) {

  FILE *result;

  result = lookup("Bat",1,0);

} END_TEST

START_TEST(test_searchfield_ofb_2) {

  FILE *result;

  result = lookup("Bat",2,7);

} END_TEST

START_TEST(test_searchfield_ofb_3) {

  FILE *result;

  result = lookup("Bat",1,10);

} END_TEST

START_TEST(test_all_good) {

  FILE *result;

  result = lookup("Bat",1,2);
  ck_assert(result != NULL);

  char check[6] = {0};
  fread(check, 1, 5, result);
  //Implies that the file returned is open with read permission and the pointer is at the top.
  ck_assert_str_eq(check, "\"BOOK");
  // This test will fail on purpose to demonstrate that a failure causes a message
  // with the output and expected value
  ck_assert_str_ne(check, "\"BOOK");

} END_TEST

/************** MITALI's TESTS ****************/



/************** GENERAL TESTS ****************/
/* tests from database lookup */

START_TEST(test_file_to_struct){
    char *line;
    strcpy(line,"\"Aisha\",\"AishaSR\",\"PassWe$d\",\"aisharobinson@cmail.carleton.ca\",\"2\"");
    void *record = file_to_struct(line, 2);

    struct user *test = record;

    ck_assert_str_eq(test->name, "Aisha");
    ck_assert_str_eq(test->user_name, "AishaSR");
    ck_assert_str_eq(test->password, "PassWe$d");
    ck_assert_str_eq(test->email, "aisharobinson@cmail.carleton.ca");
    ck_assert_str_eq(test->number_of_books, "2");

} END_TEST


/* tests from add books */
START_TEST(test_ISBN_validation){

    ck_assert_int_eq(isbn_validation("12345",3), 1);
    ck_assert_int_eq(isbn_validation("55555",3), 0);

} END_TEST

/* tests from sign up */
START_TEST(test_char_check){

    ck_assert_int_eq(char_check("1"), 0);
    ck_assert_int_eq(char_check("t"), 1);

} END_TEST

START_TEST(test_pwd_check){

    ck_assert_int_eq(char_check("spaced password "), 0);
    ck_assert_int_eq(char_check("nospace"), 1);

} END_TEST

/* tests from modify_record */

START_TEST(test_status_check){

    ck_assert_int_eq(status_check("Available"), 0);
    ck_assert_int_eq(status_check("UnAvailable"), 0);
    ck_assert_int_eq(status_check("Used"), 1);

} END_TEST

START_TEST(test_int_check){

    ck_assert_int_eq(int_check("1"), 0);
    ck_assert_int_eq(int_check("45"), 0);
    ck_assert_int_eq(int_check("Two"), 1);

} END_TEST

START_TEST(test_date_validation){

    ck_assert_int_eq(date_validation("11-12-1991"), 0);
    ck_assert_int_eq(date_validation("1112-1991"), 1);
    ck_assert_int_eq(date_validation("11-15-1991"), 1);
    ck_assert_int_eq(date_validation("11-15-191"), 1);
    ck_assert_int_eq(date_validation("41-15-1991"), 1);
    ck_assert_int_eq(date_validation("11"), 1);

} END_TEST

/* tests from modify_book */

START_TEST(test_data_valid){

    ck_assert_int_eq(data_valid("Dee",4), 1);
    ck_assert_int_eq(data_valid("13",1), 1);
    ck_assert_int_eq(data_valid("11-15-1991",8), 0);
    ck_assert_int_eq(data_valid("horse", 2), 0);


} END_TEST



	////////////////
Suite *test_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("All_tests");
  tc_core = tcase_create("Core");

  tcase_add_exit_test(tc_core, test_long_search_term, 0);
  tcase_add_exit_test(tc_core, test_table_ofb, 0);
  tcase_add_exit_test(tc_core, test_searchfield_ofb_1, 0);
  tcase_add_exit_test(tc_core, test_searchfield_ofb_2, 0);
  tcase_add_exit_test(tc_core, test_searchfield_ofb_3, 0);
  tcase_add_test(tc_core, test_all_good);
  tcase_add_test(tc_core, test_ISBN_validation);
  tcase_add_test(tc_core, test_char_check);
  tcase_add_test(tc_core, test_pwd_check);
  tcase_add_test(tc_core, test_status_check);
  tcase_add_test(tc_core, test_int_check);
  tcase_add_test(tc_core, test_date_validation);
  tcase_add_test(tc_core, test_data_valid);
  tcase_add_test(tc_core, test_file_to_struct);

  suite_add_tcase(s, tc_core);

  return s;
}
/////////////////////
int main(void) {
  int no_failed = 0;
  Suite *s;
  SRunner *runner;

  s = test_suite();
  runner = srunner_create(s);
  srunner_set_log (runner, "test.log");
  srunner_run_all(runner, CK_VERBOSE);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
