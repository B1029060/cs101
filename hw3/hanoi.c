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
    FILE* fp = fopen("Read_sec", "w+");
    clock_t begin, end;
    double cost;
    int f_cost;
    int s_cost[32];
    int buff[32];
    begin = clock();
    hanoi(HEIGHT, 'A', 'B', 'C');
    end = clock();
    cost = (double)(end - begin) / CLOCKS_PER_SEC * 100000000;
    f_cost = cost;
    f_cost = (f_cost - (f_cost % 100000000)) / 100000000;
    for (int i = 0; f_cost > 9; i++) {
        s_cost[i] = f_cost % 10;
        f_cost = (f_cost - (f_cost % 10)) / 10;
        if (f_cost < 10) {
            s_cost[++i] = f_cost;
            for (int j = 0; i >= 0; j++, i--) {
                buff[j] = s_cost[i];
            }
            fwrite(buff, sizeof(int), i, fp);
        }
    }
    fclose (fp);
    return 0;
}