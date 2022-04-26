#include <stdio.h>
#include <stdlib.h>

int* get_int_array(int n) {
    return calloc(sizeof(int)*n, sizeof(int));
}
void set_value(int* p, int v) {
    *p = v;
}
void print_array(int* p, int n) {
    printf("[");
    for (int i = 0; i < n ; i++) {
        if (i != n-1) {
            printf("%i,", *p++);
        } else {
            printf("%i]\n", *p);
        }    
    }
}
typedef struct array_list {
    int var;
    int (* Get_Int_Array)(int n);
    void (* Set_Value)(int* p, int v);
    void (* Print_Array)(int* p, int n);
} array_list_t;

int main() {
    printf("No.1 ------------\n");
    int n = 10;
    int* ip = get_int_array(n);
    for (int i = 0; i < n; i++) {
        set_value(ip+i, i+1);
    }
    
    print_array(ip, n);
    printf("No.2 ------------\n");
    array_list_t nn;
    
    return 0;
}