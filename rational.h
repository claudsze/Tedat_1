#include <stdio.h>
#include <stdlib.h>
#include "types.h"

typedef struct _Rational Rational;

Rational *rational_create(int num, int den);

void rational_free(Rational *r);

Rational *rational_sum(Rational *r1, Rational *r2);

Rational *rational_prod(Rational *r1, Rational *r2);

Rational *rational_div(Rational *r1, Rational *r2);

void rational_print(Rational *r);