#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 16

void hanoi(int n, char A, char B, char C) {
    if(n == 1) {
        printf("Move sheet from %c to %c\n", A, C);
    }
    else {
        hanoi(n-1, A, C, B);
        hanoi(1, A, B, C);
        hanoi(n-1, B, A, C);
    }
}
int main() {
    FILE* fp = fopen("ReadSec", "w+");
    clock_t begin, end;
    double cost[100];
    begin = clock();
    hanoi(HEIGHT, 'A', 'B', 'C');
    end = clock();
    cost[0] = (double)(end - begin) / CLOCKS_PER_SEC;
    fprintf(fp, cost);
    close(fp);
    return 0;
}
