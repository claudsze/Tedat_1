#include <stdio.h>
#include <stdlib.h>
#include "types.h"

typedef struct _Rational Rational;

int gcd(int m, int n){
    int r;

    while(n!=0){
        r=m%n;
        m=n;
        n=r;
    }

    return m;
}

Rational *rational_create(int num, int den);

void rational_destroy(Rational *r);

Rational *rational_sum(Rational *r1, Rational *r2);

Rational *rational_prod(Rational *r1, Rational *r2);

Rational *rational_div(Rational *r1, Rational *r2);

void rational_print(Rational *r);