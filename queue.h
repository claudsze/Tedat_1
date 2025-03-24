/**
 * @file queue.h
 * @brief Public interface for Queue implementation.
 *
 * The Queue admits arbitrary elements, received as pointers to void.
 *
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

#include "types.h"

typedef struct _Queue Queue;

Queue *queue_new();

void queue_free(Queue *pq);

Boolean queue_is_empty(const Queue *pq);

Status queue_push(Queue *pq, const void *e);

void *queue_pop(Queue *pq);

void *queue_get_front(const Queue *pq);

void *queue_get_back(const Queue *pq);

int queue_size(const Queue *pq);

int queue_print(FILE *fp, const Queue *pq, int (*ele_print)(FILE *, const void *));

/**
 * @brief Reverse the order of the elements in the queue.
 *
 * @param pq Queue.
 * @return OK on success, ERROR otherwise.

 */
Status queue_reverse(Queue *pq);

#endif
