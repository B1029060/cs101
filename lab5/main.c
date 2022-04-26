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
    int* ip1 = get_int_array(n);
    for (int i = 0; i < n; i++) set_value(ip1+i, i+1);
    
    print_array(ip1, n);
    free(ip1);
    printf("No.2 ------------\n");
    array_list_t nn;
    nn.var = 20;
    int* ip2 = nn.Get_Int_Array(nn.var);
    for (int i = 0; i < nn.var; i++) nn.Set_Value(ip2+i, i+1);
    nn.Print_Array(ip2, nn.var);
    free(ip2);
    printf("No.3 ------------");
    return 0;
}