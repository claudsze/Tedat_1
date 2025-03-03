#include "rational.h"

int main()
{
    Rational *operator1 = NULL, *operator2 = NULL, *result = NULL;

    operator1 = rational_create(20, 3);
    operator2 = rational_create(6, 15);
    
    result = rational_sum(operator1, operator2);
    rational_print(result);
    rational_free(result);
    
    result = rational_prod(operator1, operator2);
    rational_print(result);
    rational_free(result);
    
    result = rational_div(operator1, operator2);
    rational_print(result);
    rational_free(result);
    
    rational_free(operator1);
    rational_free(operator2);
    
    return EXIT_SUCCESS;
}