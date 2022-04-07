#include <stdio.h>

void rec_dec (char* s) {
    if (*s != NULL) printf("%c,", *s);
    if (*s != NULL) rec_dec(++s); 
    if (*s == NULL) printf("\n");
}
void hanoi(int n, char A, char B, char C) {
    if(n == 1) {
        FILE* fp = fopen("hanoi.txt", "w");
        fwrite(fp, "Move disk 1 from %c to %c\n", A, C);
        fclose(fp);
    }
    else {
        hanoi(n-1, A, C, B);
        hanoi(1, A, B, C);
        hanoi(n-1, B, A, C);
    }
}

int multiplication(int i, int j) {
    if (j == 10) {
        printf("\n");
        j = 1;
        i++;
    }
    printf("\t%dx%d=%d", i, j, i*j);
    if (i == 9 && j == 9) return 0;
    multiplication(i, ++j);
}

int main() {
    char s[] = "1234567890";
    rec_dec(s);
    printf("func#1---\n");
    hanoi(16, 'A', 'B', 'C');
    printf("func#2---\n");
    multiplication(1, 1);
    printf("func#3---\n");
    return 0;
}
