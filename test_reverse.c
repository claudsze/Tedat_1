#include <stdio.h>
#include <time.h>

#include "queue.h"

/* Output for a correct implementation (these tests are not exhaustive):

$ ./test_reverse
0 1 2 3 4 5 6 7
7 6 5 4 3 2 1 0
aaa bbb ccc ddd eee fff ggg hhh
hhh ggg fff eee ddd ccc bbb aaa
*/

int int_print(FILE *f, const void *e) { return fprintf(f, "%d ", *((int *)e)); }

int string_print(FILE *f, const void *e) { return fprintf(f, "%s ", (char *)e); }

int main(int argc, char *argv[]) {
  int i = 0;
  int numbers[8] = {0, 1, 2, 3, 4, 5, 6, 7};
  char *strings[8] = {"aaa", "bbb", "ccc", "ddd", "eee", "fff", "ggg", "hhh"};
  Queue *queue = NULL;

  queue = queue_new();
  if (queue == NULL) {
    return EXIT_FAILURE;
  }

  for (i = 0; i < sizeof(numbers) / sizeof(int); i++) {
    if (queue_push(queue, numbers + i) == ERROR) {
      queue_free(queue);
      return EXIT_FAILURE;
    }
  }

  queue_print(stdout, queue, int_print);
  if (queue_reverse(queue) == ERROR) {
    queue_free(queue);
    return EXIT_FAILURE;
  } else {
    queue_print(stdout, queue, int_print);
  }

  while(queue_is_empty(queue) == FALSE) {
    queue_pop(queue);
  }

  for (i = 0; i < sizeof(strings) / sizeof(char *); i++) {
    if (queue_push(queue, strings[i]) == ERROR) {
      queue_free(queue);
      return EXIT_FAILURE;
    }
  }

  queue_print(stdout, queue, string_print);
  if (queue_reverse(queue) == ERROR) {
    queue_free(queue);
    return EXIT_FAILURE;
  } else {
    queue_print(stdout, queue, string_print);
  }

  queue_free(queue);

   return EXIT_SUCCESS;
}