#include <stdio.h>

int _sum(int x, int y) {
    int a = x+y;
    return a;
}
int _sub(int x, int y) {
    int b = x-y;
    return b;
}
int _mult(int x, int y) {
    int c = x*y;
    return c;
}
int _div(int x, int y) {
    int d = x/y;
    return d;
}
int _power(int x, int y) {
    if (y >= 1) return x*_power(x, --y);
}

int main() {
    int x, y, choice;
    int (*ope[4])(int, int);
    ope[0] = _sum;
    ope[1] = _sub;
    ope[2] = _mult;
    ope[3] = _div;
    ope[4] = _power;

    printf("Enter two integer: ");
    scanf("%d%d", &x, &y);

    printf("Enter 0 to +, 1 to -, 2 to *, 3 to /, 4 to ^:");
    scanf("%d", &choice);

    printf("%d", ope[choice](x, y));
    return 0;
}