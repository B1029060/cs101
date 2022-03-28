#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 40

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
    clock_t begin, end;
    double cost;
    begin = clock();
    hanoi(HEIGHT, 'A', 'B', 'C');
    end = clock();
    cost = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Height of Hanoi tower: %d\n", HEIGHT);
    printf("Time cost: %lf\n", cost);
    return 0;
}
