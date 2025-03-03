#include "rational.h"

struct _Rational
{
    int num;
    int den;
};

Rational *rational_create(int num, int den)
{
    Rational *r = NULL;
    int div;

    if (den == 0)
    {
        return NULL;
    }

    r = (Rational *)malloc(sizeof(Rational));
    if (!r)
    {
        return NULL;
    }

    div = gcd(num, den);
    num /= div;
    den /= div;

    r->num = num;
    r->den = den;
    return r;
}

void rational_destroy(Rational *r)
{
    if (r != NULL)
    {
        free(r);
    }
}

Rational *rational_sum(Rational *r1, Rational *r2)
{
    Rational *result = NULL;
    int div;

    if (!r1 || !r2)
    {
        return NULL;
    }

    result = (Rational *)malloc(sizeof(Rational));
    if (!result)
    {
        return NULL;
    }

    result->den = r1->den * r2->den;
    result->num = r1->num * r2->den + r1->den * r2->num;

    div = gcd(result->den, result->num);
    result->num /= div;
    result->den /= div;

    return result;
}

Rational *rational_prod(Rational *r1, Rational *r2)
{
    Rational *result = NULL;
    int div;

    if (!r1 || !r2)
    {
        return NULL;
    }

    result = (Rational *)malloc(sizeof(Rational));
    if (!result)
    {
        return NULL;
    }

    result->den = r1->den * r2->den;
    result->num = r1->num * r2->num;

    div = gcd(result->den, result->num);
    result->num /= div;
    result->den /= div;

    return result;
}

Rational *rational_div(Rational *r1, Rational *r2)
{
    Rational *result = NULL;
    int div;

    if (!r1 || !r2)
    {
        return NULL;
    }

    result = (Rational *)malloc(sizeof(Rational));
    if (!result)
    {
        return NULL;
    }

    result->num = r1->num * r2->den;
    result->den = r1->den * r2->num;

    div = gcd(result->den, result->num);
    result->num /= div;
    result->den /= div;

    return result;
}

void rational_print(Rational *r){
    fprintf(stdout, "%d/%d\n", r->num, r->den);
}