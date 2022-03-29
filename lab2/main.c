#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define COUNTER_FILE "counter.bin"
#define OPERATOR_FILE "operator_id.bin"
#define RECORD_FILE "records.bin"
#define MAX_LOTTO_NUM 7
#define MAX_LOTTO_NUMSET 5

typedef struct lotto_record {
    int no;
    int receipt;
    int id;
    char date[16];
    char time[16];
} lotto_record_t;

void init_file() {
    FILE* fp = fopen(COUNTER_FILE, "r");
    int write_array[1];
    write_array[0] = 0;
    if (fp == NULL) {
        FILE* tmpfp = fopen(COUNTER_FILE, "wb");
        fwrite(write_array, sizeof(int), 1, tmpfp);
        fclose(tmpfp);
    } else {
        fclose(fp);
    }
}
int get_counter() {
    int read_array[1];
    FILE* fpg = fopen(COUNTER_FILE, "rb");
    fread(read_array, sizeof(int), 1, fpg);
    fclose(fpg);
    return read_array[0];
}
    
void do_lotto_main(int counter) {
    int lotto_file[20];
    int ope_id = 0;
    int num_set = 0;
    char c;
    lotto_record_t rec;
    time_t now = time(0);
    snprintf(lotto_file, 20, "lotto[%05d].txt", counter);
    printf("歡迎光臨長庚樂透購買機台\n");
    printf("請輸入操作人員id(0-5): \n");
    scanf("%d", &ope_id);
    while (ope_id > 5 || ope_id < 0) {
        printf("id輸入錯誤，請重新輸入\n");
        printf("請輸入操作人員id(0-5): \n");
        scanf("%d", &ope_id);
    }
    printf("請問您要買幾單樂透彩(1-5): ");
    scanf("%d", &num_set);
    print_lottofile(num_set, counter, lotto_file);
    print_lottofile_id(num_set, counter, ope_id);
    printf("已為您購買的%d單樂透組合輸出至 %s\n", num_set, lotto_file);
    rec.no = counter;
    rec.receipt = 55 * num_set;
    rec.id = ope_id;
    strftime(rec.date, 8, "%Y%m%d", localtime(&now));
    strftime(rec.time, 8, "%H:%M:%S", localtime(&now));
    FILE* cfp = fopen(RECORD_FILE, "a");
    fwrite(&rec, sizeof(rec), 1, cfp);
    fclose(cfp);
}

void print_lottofile(int num_set, int counter, char lotto_file[]) {
    time_t curtime;
    time(&curtime);
    srand(time(0));

    FILE* tmpfp = fopen(lotto_file, "w+");
    fprintf(tmpfp, "========= lotto649 =========\n");
    fprintf(tmpfp, "========+ No.%05d +========\n", counter);
    fprintf(tmpfp, "= %.*s =\n", 24, ctime(&curtime));
    for (int j=0; j<num_set; j++) {
        for (int i=0; i<MAX_LOTTO_NUMSET; i++) {
            if (i<5) {
                print_lotto_row(tmpfp, i+1);
            } else {
                fprintf(tmpfp, "[%d]: -- -- -- -- -- -- --\n", i+1);
            }
        }
    fprintf(tmpfp, "============================\n");    
    }
    fprintf(tmpfp, "========= csie@CGU =========\n");
    fclose(tmpfp);
}
void print_lottofile_id(int num_set, int counter, int id) {
    time_t curtime;
    time(&curtime);
    srand(time(0));

    FILE* tmpfp = fopen(OPERATOR_FILE, "w+");
    fprintf(tmpfp, "========= lotto649 =========\n");
    fprintf(tmpfp, "========+ No.%05d +========\n", counter);
    fprintf(tmpfp, "= %.*s =\n", 24, ctime(&curtime));
    for (int j=0; j<num_set; j++) {
        for (int i=0; i<MAX_LOTTO_NUMSET; i++) {
            if (i<5) {
                print_lotto_row(tmpfp, i+1);
            } else {
                fprintf(tmpfp, "[%d]: -- -- -- -- -- -- --\n", i+1);
            }
        }
    fprintf(tmpfp, "========= Op.%05d =========\n", id);    
    }
    fprintf(tmpfp, "========= csie@CGU =========\n");
    fclose(tmpfp);
}
void print_lotto_row(FILE* tmpfp, int n) {
    int numset[MAX_LOTTO_NUM];

    fprintf(tmpfp, "[%d]: ",n);
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
        fprintf(tmpfp, "%02d ", numset[i]);
    }
    fprintf(tmpfp, "\n");
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

void set_counter(int counter) {
    int write_array[1];
    write_array[0] = counter;
    FILE* tmpfp;
    tmpfp = fopen(COUNTER_FILE, "wb");
    fwrite(write_array, sizeof(int), 1, tmpfp);
    fclose(tmpfp);
}
int main() {
    int counter;
    init_file();
    counter = get_counter();
    do_lotto_main(++counter);
    set_counter(counter);
    return 0;
}
