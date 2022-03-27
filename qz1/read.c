#include <stdio.h>
#include <stdlib.h>

#define COUNTER_FILE "counter.bin"

int main( ) {
    FILE* fp = fopen(COUNTER_FILE, "r");
        int a;
        do {
            a = fgetc(fp);
            printf("%c", a);
        } while (a != EOF);
        fclose(fp);
    return 0;    
}