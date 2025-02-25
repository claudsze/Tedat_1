/**
 * @file slist.c
 * @brief Implementation of an ordered (by position, not with respect to any ordering criterion) list of strings.
 *
 */
#include "slist.h"

#include <stdio.h>
#include <stdlib.h>

#include "types.h"

/* ALL THE CODE must between written between the <START_CODE> and <END_CODE>
tags. Auxiliary functions can also be defined between those lines.
*/

#ifndef OVERRIDE_DEFS
#define INIT_SIZE 4
#define GROWTH_FACTOR 2
#endif

/**
 * @brief List of strings.
 *
 */
struct _SList {
  char **data;   /*!< Array of strings of size capacity. */
  int capacity;  /*!< Capacity of the list. */
  int n_strings; /*!< Number of strings the list actually contains. */
};

SList *sl_new() {
  SList *sl = NULL;

  sl = (SList *)malloc(sizeof(SList));
  if (!sl) {
    return NULL;
  }

  sl->data = (char **)malloc(sizeof(char *) * INIT_SIZE);
  if (!sl->data) {
    free((void *)sl);
    return NULL;
  }
  sl->capacity = INIT_SIZE;
  sl->n_strings = 0;

  return sl;
}

void sl_free(SList *sl) {
  if (sl != NULL) {
    free((void *)sl->data);
    free((void *)sl);
  }
}

int sl_size(SList *sl) {
  if (sl == NULL) {
    return 0;
  } else {
    return sl->n_strings;
  }
}

/**
 * Private function; detects whether the list is full.
 */
bool _sl_is_full(SList *sl) {
  if (sl == NULL) {
    return true;
  }

  if (sl->capacity == sl->n_strings) {
    return true;
  } else {
    return false;
  }
}

/**
 * Private function; increases the capacity of the list.
 */
Status _sl_grow(SList *sl) {
  int new_size;
  char **new_data = NULL;

  if ((sl == NULL) || (sl->data == NULL)) {
    return ERROR;
  }

  new_size = sl->capacity * GROWTH_FACTOR;
  new_data = realloc(sl->data, sizeof(char *) * new_size);
  if (!new_data) {
    return ERROR;
  }

  sl->capacity = new_size;
  sl->data = new_data;
  return OK;
}

/*<START_CODE>*/

Status sl_append(SList *sl, char *str) {
  if(!sl||!str||!sl->data){
    return ERROR;
  }

  if(_sl_is_full(sl)==true){
    if(_sl_grow(sl)==ERROR){
      return ERROR;
    }
  }

  sl->data[sl->n_strings]=str;
  sl->n_strings++;
  return OK;
}

Status sl_pop(SList *sl, char **str) {
  if(!sl||!str){
    return ERROR;
  }

  (*str)=sl->data[sl->n_strings-1];

  sl->data[sl->n_strings-1]=NULL;
  sl->n_strings--;
  return OK;
}

/*<END_CODE>*/

Status sl_get(SList *sl, int pos, char **str) {
  if ((sl == NULL) || (pos < 0) || (str == NULL)) {
    return ERROR;
  }

  if (pos >= sl->n_strings) {
    return ERROR;
  }

  *str = sl->data[pos];

  return OK;
}

bool sl_is_empty(SList *sl) {
  if (sl == NULL) {
    return true;
  }
  if (sl->n_strings == 0) {
    return true;
  } else {
    return false;
  }
}

void sl_print(SList *sl) {
  int i;

  if (sl == NULL) {
    return;
  }

  for (i = 0; i < sl->n_strings; i++) {
    printf("\"%s\" ", sl->data[i]);
  }
}
