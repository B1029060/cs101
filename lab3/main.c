#include <stdio.h>

int my_strlen(char* s) {
    int a = 0;
    while (*s++ != NULL) a++;
    return a;
}    
int rec_strlen(char* s) { int a = 0;
    while (*s++ != NULL) {rec_strlen(s); a++;}
    return a;
} 

char* my_sort(char* s) {
    for (char* t = s; *t; t++) {
        for (char* p = t+1; *p; p++) {
            if (*t > *p) {
                char tmp = *t;
                *t = *p;
                *p = tmp;
            }
        }
    }
    return s;
}
int main () {
    char s[] = "IU is a girl!";
    printf("len = %d\n", my_strlen(s));
    printf("len = %d\n", rec_strlen(s));
    printf("sort = %s\n", mysort(s));
    return 0;
}
