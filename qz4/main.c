#include <stdio.h>
#include <stdlib.h>

int* swap(int* a, int* b) {
    printf("N0.1---------\n");
    int tem = *a;
    *a = *b;
    *b = tem;
}
int* swapArray(int(* a)[1024], int(* b)[1024], int size) {
    printf("No.2---------\n");
    for (int i = 0; i < size; i++) {
        int tem =  *(a[0] + i);
        *(a[0] + i) = *(b[0] + i);
        *(b[0] + i) = tem;
    }
}
void printArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", a[i]);
        if (i != size - 1) {
            printf(",");
        } else {
        printf("]\n");
        }
    } 
}
char* copy_string(char* str) {
    printf("No.3---------\n");
    *str = (char*)calloc(sizeof(str), sizeof(char));
    for (int i = 0; i < sizeof(str); i++) return &str[i];
}

int main() {
    int n, m;
    n = 1;
    m = 2;
    int size = 10;
    int source[10] = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int dest[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    char str[] = "IU!IU!IU!IU!";
    swap(&n, &m);
    printf("after swap, n=%d, m=%d\n", n, m);
    swapArray(&source, &dest, size);
    printf("after swap array, source array = [");
    printArray(source, size);
    printf("after swap array, dest array = [");
    printArray(dest, size);
    char* cp_str = copy_string(str);
    printf("copy string = %s\n", cp_str);
    free(cp_str);
    return 0;
}