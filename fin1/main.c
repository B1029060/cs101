#include <stdio.h>

int power(int a, int b) {
    if (b == 1) return a;
    return power(a, b-1) * a;
}
int setMyBit(int a, int b) {
    if ((a % power(2, b+1)) - (a % power(2, b)) == power(2,b)) {
        return a;
    } else {
        return a + power(2, b);
    }
}
int clearMyBit(int a, int b) {
    if ((a % power(2, b+1)) - (a % power(2, b)) == power(2,b)) {
        return a - power(2, b);
    } else {
        return a;
    }
}
int inverseMyBit(int a, int b) {
    if ((a % power(2, b+1)) - (a % power(2, b)) == power(2,b)) {
        return a - power(2, b);
    } else {
        return a + power(2, b);
    }
}

int main() {
    int a = 1;
    int b = 3;
    int t = a;
    printf("setMyBit(%d, %d) = %d\n", t, b, setMyBit(a,b));
    a = setMyBit(a, b);
    t = a;
    printf("clearMyBit(%d, %d) = %d\n", t, b, clearMyBit(a,b));
    a = clearMyBit(a, b);
    t = a;
    printf("inverseMyBit(%d, %d) = %d\n", t, b, inverseMyBit(a, b));
    return 0;
}
