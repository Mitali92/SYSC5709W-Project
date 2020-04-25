#include </usr/local/Cellar/check/0.14.0/include/check.h>      
//#include </usr/local/Cellar/check/0.14.0/include/check_stdint.h>               
#include "../src/database_lookup.h"
        
#include <stdlib.h>
#include <stdio.h>


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
  suite_add_tcase(s, tc_core);

  return s;
}

int main(void) {
  int no_failed = 0;                   
  Suite *s;                            
  SRunner *runner;                     

  s = test_suite();                   
  runner = srunner_create(s);          

  srunner_run_all(runner, CK_NORMAL);  
  no_failed = srunner_ntests_failed(runner); 
  srunner_free(runner);                      
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;  
}