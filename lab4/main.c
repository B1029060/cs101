#include <stdio.h>
int* get_an(int(* a)[10]) {
    int num = 9;
    for (int i = 0; i <= 10; i++) {
        if (*(a[0]+i) == num) {
            printf("&n[%i]->%p, n[%i]=%i;", i, a[0]+i, i, *(a[0]+i));
            return (a[0]+i);
        }
    }
}

int main() {
    int n[] = {6,4,7,2,0,9,8,1,5,3};
    int* p;
    int* ap;
    printf("No.1-------------------\n");
    p = get_an(&n);
    printf("p->%p, *p=%i\n", p, *p);
    return 0;
}