#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *ptr = malloc(sizeof(int));
    if (ptr == NULL) return 1;

    *ptr = 42;
    int *alias = ptr;

    free(ptr);
    ptr = NULL;

    printf("Value: %d\n", *alias);

    return 0;
}
