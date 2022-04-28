#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define COUNTER_FILE "counter.bin"
#define OPERATOR_FILE "operator_id.bin"
#define MAX_LOTTO_NUM 7
#define MAX_LOTTO_NUMSET 5

void do_lotto_main() {
    int lotto_file[20];
    int num_set = 0;
    printf("歡迎光臨長庚樂透購買機台\n");
    printf("請問您要買幾張樂透彩(1-5): ");
    scanf("%d", &num_set);
    print_lottofile(1, num_set, lotto_file);
}

void print_lottofile(int num_set, int seq, char lotto_file[]) {
    time_t curtime;
    time(&curtime);
    srand(time(0));

    printf("========= lotto649 =========\n");
    printf("========+ No.00001 +========\n");
    printf("= %.*s =\n", 24, ctime(&curtime));
    for (int i=0; i<seq; i++) {
        if (i<5) {
            print_lotto_row(i+1);
        } else {
            printf("[%d]: -- -- -- -- -- -- --\n", i+1);
        }
    }
    printf("============================\n");    

}
void print_lotto_row(int n) {
    int numset[MAX_LOTTO_NUM];

    printf("[%d]: ",n);
    for (int i = 0; i<MAX_LOTTO_NUM-1;) {
        int num = (rand() % 69) + 1;
        if (num_in_numset(num, numset, MAX_LOTTO_NUM-1)) {
            continue;
        } else {
            numset[i] = num;
            i++;
        }
    }
    for (int i = 0; i<1; ) {
        int num = (rand() % 10) + 1;
        if (num_in_numset(num, numset, MAX_LOTTO_NUM-1)) {
            continue;
        } else {
            numset[MAX_LOTTO_NUM-1] = num;
            i++;
        }
    }
    for (int i = 0; i<MAX_LOTTO_NUM-1; ++i) {
        for (int j = 0; j < i; ++j) {
            if (numset[j] > numset[i]) {
                int temp = numset[j];
                numset[j] = numset[i];
                numset[i] = temp;
            }
        }
    }
    for (int i = 0; i<MAX_LOTTO_NUM; i++) {
        printf("%02d ", numset[i]);
    }
    printf("\n");
}

int num_in_numset(int num, int numset[], int Len) {
    int ret = 0;
    for (int i = 0; i < Len; i++) {
        if (num == numset[i]) {
            ret = 1;
            break;
        }
    }
    return ret;
}

int main() {
    do_lotto_main();
    return 0;
}