#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define COUNTER_FILE "counter.bin"
#define RECORD_FILE "records.bin"
#define EMP_RECORD "operator_id.bin"
#define MAX_LOTTO_NUM 7
#define MAX_LOTTO_NUMSET 5

typedef struct lotto_record_t {
    int lotto_no;
    int lotto_receipt;
    int emp_id;
    char lotto_date[16];
    char lotto_time[16];
} lotto_record_t;
typedef struct emp_record_t {
    int emp_id;
    char emp_name[16];
    int emp_salary;
} emp_record_t;
void init_file() {
    int write_array[1] = {0};
    FILE* fp = fopen(COUNTER_FILE, "r");
    if (fp == NULL) {
        FILE* tmpfp = fopen(COUNTER_FILE, "wb+");
        fwrite(write_array, sizeof(int), 1, tmpfp);
        fclose(tmpfp);
    } else {
        fclose(fp);
    }
}
int get_counter() {
    int read_array[1];
    FILE* tmpfp = fopen(COUNTER_FILE, "rb");
    fread(read_array, sizeof(int), 1, tmpfp);
    fclose(tmpfp);
    return read_array[0];
}
void do_lotto_main(int counter) {
    char szbuff[32];
    lotto_record_t memo;
    memo.lotto_no = counter + 1;
    char lotto_file[32];
    int num_set = 0, id = 0;
    time_t now = time(0);
    strftime(szbuff, 100, "%Y%m%d-%H:%M:%S", localtime(&now));
    for (int i = 0; i <= sizeof(szbuff); i++) {
        if (i <= 7) {
            memo.lotto_date[i] = szbuff[i];
        } else if (i >= 9) {
            memo.lotto_time[i-10] = szbuff[i];
        }
    }
    snprintf(lotto_file, 32, "lotto[%05d].txt", counter);
    printf("歡迎光臨長庚樂透購買機台\n");
    printf("請問您的員工編號是: \n");
    scanf("%d", &id);
    memo.emp_id = &id;
    if (memo.emp_id == 0) {
        record(memo.emp_id);
    }
    printf("請問您要買幾組樂透彩: ");
    scanf("%d", &num_set);
    int tmp = &num_set;
    memo.lotto_receipt = tmp * 55;
    record_t(memo.lotto_no, memo.lotto_receipt, memo.emp_id, memo.lotto_date[16], memo.lotto_time[16]);
    print_lotto_file(num_set, counter, lotto_file);
    printf("已為您購買的%d組樂透組合輸出至 %s\n", num_set, lotto_file);
}
void print_lotto_file(int num_set, int counter, char lotto_file[]) {
    time_t curtime;
    time(&curtime);
    srand(time(0));
    FILE* tmpfp = fopen(lotto_file, "w+");
    fprintf(tmpfp, "========= lotto649 =========\n");
    fprintf(tmpfp, "========+ No.%05d +========\n", counter);
    for (int i=0; i<MAX_LOTTO_NUMSET; i++) {
        if (i<num_set) {
            print_lotto_row(tmpfp, i+1);
        } else {
            fprintf(tmpfp, "[%d]: -- -- -- -- -- -- --\n", i+1);
        }
    }
    fprintf(tmpfp, "========= csie@CGU =========\n");
    fclose(tmpfp);
}
void print_lotto_row(FILE* tmpfp, int n) {
    int numset[MAX_LOTTO_NUM];
    fprintf(tmpfp, "[%d]: ", n);
    for (int i = 0; i<MAX_LOTTO_NUM-1; i++) {
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
        fprintf(tmpfp, "%02d", numset[i]);
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
    FILE* tmpfp = fopen(COUNTER_FILE, "wb");
    fwrite(write_array, sizeof(int), 1, tmpfp);
    fclose(tmpfp);
}
void record(int id) {
    emp_record_t rec;
    int salary;
    int write_id_array[1] = id;
    char write_name_array[16];
    rec.emp_id = id;
    printf("請輸入員工名稱");
    scanf("%15s", rec.emp_name);
    printf("請輸入員工月薪");
    scanf("%d", &salary);
    rec.emp_salary = &salary;
    int write_salary_array[8] = rec.emp_salary;
    for (int i = 0; i <= sizeof(rec.emp_name); i++) {
        write_name_array[i] = rec.emp_name[i];
    }
    FILE* tmpfp = fopen(EMP_RECORD, "ab");
    fwrite(write_id_array, sizeof(write_id_array), 1, tmpfp);
    fwrite(write_name_array, sizeof(write_salary_array), 1, tmpfp);
    fwrite(write_salary_array, sizeof(write_salary_array), 1, tmpfp);
    fclose(tmpfp);
}
void record_t(int lotto_no, int lotto_receipt, int emp_id, char lotto_date[16], char lotto_time[16]) {
    int write_no[8] = lotto_no;
    int write_receipt[8] = lotto_receipt;
    int write_id[1] = emp_id;
    char write_date[16];
    char write_time[16];
    for (int i = 0; i <= 16; i++) {
        write_date[i] = lotto_date[i];
        write_time[i] = lotto_time[i];
    }
    FILE* fp = fopen(RECORD_FILE, "ab");
    fwrite(write_no, sizeof(write_no), 1, fp);
    fwrite(write_receipt, sizeof(write_receipt), 1, fp);
    fwrite(write_id, sizeof(write_id), 1, fp);
    fwrite(write_date, sizeof(write_date), 1, fp);
    fwrite(write_time, sizeof(write_time), 1, fp);
    fclose(fp);
}
int main() {
    int counter;
    init_file();
    counter = get_counter();
    do_lotto_main(++counter);
    set_counter(counter);
    return 0;
}
