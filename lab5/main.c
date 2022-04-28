#include <stdio.h>
#include <stdlib.h>

int* get_int_array(int n) {
    return (int *)calloc(n, sizeof(int));
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
    int* (* Get_Int_Array)(int);
    void (* Set_Value)(int*, int);
    void (* Print_Array)(int*, int);
} array_list_t;
char* get_str_array(int n) {
    return (char *)calloc(n, sizeof(char));
}
int get_str_len(char* s) {
    int len = 0;
    while(*s++) len++;
    return len;
}
char* my_str_cpy(char* s, char* d) {
    while(*d) *s++ = *d++;
    *s = 0;
    return s;
}
typedef char* (*ADD_INT_Func)(char*, char*);
char* func(char* a,char* b) {
    int str_len = 0;
    str_len = get_str_len(a) + get_str_len(b);
    char* new_str = get_str_array(str_len+1);
    char* tp = new_str;
    tp = my_str_cpy(tp, a);
    tp = my_str_cpy(tp, b);
    return new_str;
}
char* add_str_func(char* a, char* b, ADD_INT_Func func_ptr) {
    return func_ptr(a, b);
}

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
    nn.Get_Int_Array = get_int_array;
    nn.Set_Value = set_value;
    nn.Print_Array = print_array;
    int* ip2 = nn.Get_Int_Array(nn.var);
    for (int i = 0; i < nn.var; i++) nn.Set_Value(ip2+i, i+1);
    nn.Print_Array(*ip2, nn.var);
    free(ip2);
    printf("No.3 ------------\n");
    char a[] = "IU!IU!";
    char b[] = "@CGU";
    char* cp1 = add_str_func(a, b, func);
    printf("add_str_func = %s\n", cp1);
    free(cp1);

    return 0;
}