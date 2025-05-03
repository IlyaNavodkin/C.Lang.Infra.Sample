#include <stdio.h>
#include <string.h>
#include "my_lib.h"
#include "sum.h"

int main() {
    printf("Hello, World!\n");
    printf("Sum of 1 and 2 is %d\n", sum(1, 2));
    printf("Family: %s\n", FAMILY);
    printf("Kids: %d\n", KIDS);
    printf("Mortage rate: %f\n", MORTAGE_RATE);

    getchar();
    return 0;
}

