#include <stdio.h>

int* my_calloc(int n, int size) {
    for (; size>0; size--) return n;
    printf("%s\n", *my_calloc);
}
void my_free(int* p) {
    my_calloc(0, sizeof(p));
}
typedef struct my_mm {
    int m[10];
} my_mm_t;
int g_mem[10];
my_mm_t mms;

int main () {
    int* np1 = my_calloc(1, 1);
    int* np2 = my_calloc(1, 2);
    int* np3 = my_calloc(1, 3);
    int* np4 = my_calloc(1, 4);
    my_free(np1);
    my_free(np4);
    return 0;
}