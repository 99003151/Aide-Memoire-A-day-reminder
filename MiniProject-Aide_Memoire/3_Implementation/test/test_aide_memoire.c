#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

/* Modify these two lines according to the project */
#include <aide_memoire.h>
#define PROJECT_NAME    "Aide-Memoire"

/* Prototypes for all the test functions */
void test_Leap_Year(void);

/* Start of the application test */
int main() {
/* Note: Do not edit START*/
  /*Initialize and setup the Test Framework */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();
  CU_pSuite suite = CU_add_suite(PROJECT_NAME, 0, 0);
/* Note: Do not edit END */
  
  
  /* Add your test functions in this format for testing*/
  CU_add_test(suite, "Leap_Year", test_Leap_Year);
  
/* Note: Do not edit START*/
  /* Setup Test Framework to output the result to Screen */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  
  /* run the unit test framework*/
  CU_basic_run_tests();
  
  /* Cleaning the Resources used by Unit test framework */
  CU_cleanup_registry();
/* Note: Do not edit END */
  return 0;
}

/* Write all the test functions */ 
void test_add(void) {
  CU_ASSERT(1 == Leap_Year(2020));
  CU_ASSERT(1 == Leap_Year(2024));
  CU_ASSERT(0 == Leap_Year(2021));
  CU_ASSERT(0 == Leap_Year(2026));
  CU_ASSERT(2 == Leap_Year(2010));
}


  
 

