/**
 * @file queue.c
 * @brief Queue implementation with (void *).
 *
 */
#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE 1024

/* ALL THE CODE must between written between the <START_CODE> and <END_CODE>
tags. Auxiliary functions can also be defined between those lines.
*/

struct _Queue {
  void *data[MAX_QUEUE];
  int front;
  int rear;
};

/*Private functions. */

Boolean _queue_is_full(const Queue *pq);

/*Public functions. */

Queue *queue_new() {
  Queue *pq = NULL;
  int i;

  pq = (Queue *)malloc(sizeof(Queue));
  if (pq == NULL) {
    return NULL;
  }

  for (i = 0; i < MAX_QUEUE; i++) {
    pq->data[i] = NULL;
  }
  pq->front = 0;
  pq->rear = 0;
  return pq;
}

void queue_free(Queue *pq) { free((void *)pq); }

Status queue_push(Queue *pq, const void *e) {
  if ((pq == NULL) || (e == NULL) || (_queue_is_full(pq) == TRUE)) {
    return ERROR;
  }

  pq->data[pq->rear] = (void *)e;
  pq->rear = (pq->rear + 1) % MAX_QUEUE;

  return OK;
}

void *queue_pop(Queue *pq) {
  void *e = NULL;

  if ((pq == NULL) || (queue_is_empty(pq) == TRUE)) {
    return NULL;
  }

  e = pq->data[pq->front];
  pq->data[pq->front] = NULL;
  pq->front = (pq->front + 1) % MAX_QUEUE;

  return e;
}
void *queue_get_front(const Queue *pq) {
  if ((pq == NULL) || (queue_is_empty(pq) == TRUE)) {
    return NULL;
  }

  return pq->data[pq->front];
}
void *queue_get_back(const Queue *pq) {
  int last_elem;

  if ((pq == NULL) || (queue_is_empty(pq) == TRUE)) {
    return NULL;
  }

  last_elem = (MAX_QUEUE + pq->rear - 1) % MAX_QUEUE;
  return pq->data[last_elem];
}

Boolean queue_is_empty(const Queue *pq) {
  if (pq == NULL) {
    return TRUE;
  }

  if (pq->front == pq->rear) {
    return TRUE;
  }

  return FALSE;
}

int queue_size(const Queue *pq) {
  if (pq == NULL) {
    return 0;
  }

  if (queue_is_empty(pq) == TRUE) {
    return 0;
  }

  return (MAX_QUEUE + pq->rear - pq->front) % MAX_QUEUE;
}

int queue_print(FILE *fp, const Queue *pq, int (*ele_print)(FILE *, const void *)) {
  int i;

  if ((fp == NULL) || (pq == NULL) || (ele_print == NULL)) {
    return -1;
  }

  i = pq->front;
  while (i != pq->rear) {
    ele_print(fp, pq->data[i]);
    i = (i + 1) % MAX_QUEUE;
  }

  fprintf(fp, "\n");

  return 0;
}

/*<START_CODE>*/

Status queue_reverse(Queue *pq) {
  int i, j;

  if(!pq||pq->front==pq->rear){
    return ERROR;
  } 
  
  i = pq->front;
  j= (pq->rear - 1 + MAX_QUEUE)%MAX_QUEUE;

  while (i != j && (i + 1) % MAX_QUEUE != j) {
    void *temp = pq->data[i];
    pq->data[i] = pq->data[j];
    pq->data[j] = temp;

    i = (i + 1) % MAX_QUEUE;
    j = (j - 1 + MAX_QUEUE) % MAX_QUEUE;
  }

  return OK;
}

/*<END_CODE>*/

/* Private functions. */

Boolean _queue_is_full(const Queue *pq) {
  if (pq == NULL) {
    return TRUE;
  }

  if (pq->front == (pq->rear + 1) % MAX_QUEUE) {
    return TRUE;
  }

  return FALSE;
}
