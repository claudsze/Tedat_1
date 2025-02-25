#include <stdio.h>
#include <stdlib.h>

#include "slist.h"
#include "types.h"

/* Output for a correct implementation (these tests are not exhaustive):

$ ./test_slist
"hi1" "hi2"
"hi1" "hi2" "hi3" "hi4" "hi5" "bye"
Removing last string... Removed "bye":
"hi1" "hi2" "hi3" "hi4" "hi5"

$ ./test_slist a b c d e f g
"a"
"a" "b"
"a" "b" "c"
"a" "b" "c" "d"
"a" "b" "c" "d" "e"
"a" "b" "c" "d" "e" "f"
"a" "b" "c" "d" "e" "f" "g"
"a" "b" "c" "d" "e" "f"
"a" "b" "c" "d" "e"
"a" "b" "c" "d"
"a" "b" "c"
"a" "b"
"a"
*/

int main(int argc, char **argv) {
  int i = 0;
  char *strings1[] = {"hi1", "hi2"}, *strings2[] = {"hi3", "hi4", "hi5", "bye"}, *string = NULL;
  SList *sl = NULL;

  sl = sl_new();
  if (sl == NULL) {
    return EXIT_FAILURE;
  }

  if (argc == 1) {
    for (i = 0; i < 2; i++) {
      sl_append(sl, strings1[i]);
    }
    sl_print(sl);
    printf("\n");

    for (i = 0; i < 4; i++) {
      sl_append(sl, strings2[i]);
    }
    sl_print(sl);
    printf("\n");

    printf("Removing last string...");
    sl_pop(sl, &string);
    printf(" Removed \"%s\":\n", string);
    sl_print(sl);
    printf("\n");

    sl_free(sl);
    return EXIT_SUCCESS;
  }

  if (argc > 1) {
    for (i = 1; i < argc; i++) {
      sl_append(sl, argv[i]);
      sl_print(sl);
      printf("\n");
    }

    while (sl_is_empty(sl) == false) {
      sl_pop(sl, &string);
      sl_print(sl);
      printf("\n");
    }

    sl_free(sl);
    return EXIT_SUCCESS;
  }
}