#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define COUNTER_FILE "counter.bin"
#define RECORD_FILE "records.bin"
typedef struct lotto {
   int lotto_no;
   int lotto_receipt;
   int emp_id;
   char lotto_date[16];
   char lotto_time[16];
} lotto_record_t
void init_file() {
    int write_array[1] = {0};
    FILE* fp = fopen(COUNTER_FILE,"r");
    if (fp == NULL) {
        FILE* tmpfp = fopen(COUNTER_FILE,"wr+");
        fwrite(write_array, sizeof(int), 1, tmpfp);
        fclose(tmpfp);
    } else {
        fclose(fp);
    }
}
int get_counter() {
    int read_array[1] = {0};
    FILE* fp =fopen(COUNTER_FILE,"rb");
    fread(read_array, sizeof(int), 1, fp);
    fclose(fp);
    return read_array[0];
}
int numset(int num, int numset[], int mxm) {
    int ret = 0;
    for (int i = 0; i < mxm; i++) {
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
    FILE* tmpfp = fopen(COUNTER_FILE,"wb"); 
    fwrite(write_array, sizeof(int), 1, tmpfp);
    fclose(tmpfp);
}
void record(lotto_record_t rcd) {
    FILE* tmpfp = fopen(RECORD_FILE,"ab");
    fwrite(rcd, sizeof(rcd), 1, tmpfp);
    fclose(tmpfp);
}
int main() {
    int x = 1;
    char time_r1[32];
    char time_r2[32];
    time_t now = time(0);
    strftime(time_r1, 9, "%Y%m%d", localtime(&now));
    strftime(time_r2, 9, "%H:%M:%S", localtime(&now));
    init_file(1);
    time_t curtime;
    time(&curtime);
    int lot[7],i,id;
    lotto_record_t emp;
    int n_cnt = get_counter(1);
    srand((unsigned) time(NULL));
    printf("此次操作人員ID為: ");
    scanf("%d",&id);
    emp.emp_id = id;
    snprintf(emp.lotto_date, sizeof(emp.lotto_date), time_r1);
    snprintf(emp.lotto_time, sizeof(emp.lotto_time), time_r2);
    printf("歡迎光臨長庚樂透彩購買機台\n請問您要買幾單樂透彩: ");
    scanf("%d",&i);
    emp.lotto_receipt = i*55; /* 50 * 1.1 = 55 */
    printf("已為您購買的 %d 單樂透組合輸出至 lotto[%05d].txt\n",i,n_cnt);
    for (int fch = 1; fch <= i; fch++) {
         set_counter(n_cnt);
         emp.lotto_no = n_cnt;
         printf("========No.%05d========\n=%.*s=\n",n_cnt,24,ctime(&curtime));
        for (int j = 1; j <= 5; j++) {
            printf("\t[%d]: ",j);
            for (int num = 0,cnt,buf; num < 6; num++) {
                cnt = rand() % 69 + 1;
                if (numset(cnt, lot, 6)) {
                    continue;
                } else {
                    lot[num] = cnt;
                }
                buf = num;
                if (buf > 0) {
                    for (; buf > 0; buf--) {
                        if (lot[buf] < lot[buf-1]) {
                            lot[7] = lot[buf];
                            lot[buf] = lot[buf-1];
                            lot[buf-1] = lot[7];
                        }
                    }
                }
                if (num == 5) {
                    lot[6] = rand() % 9 + 1;
                    for (int seq = 0; seq < 6; seq++) {
                        if (lot[6] == lot[seq] && lot[6] > 1) {
                            lot[6] = lot[6] - 1;
                        } else if (lot[6] == lot[seq] && lot[6] < 10) {
                            lot[6] = lot[6] + 1;
                        } else if (lot[seq] < 10) {
                            printf(" 0%d ",lot[seq]);
                        } else {
                            printf(" %d ",lot[seq]);
                        }
                    }
                    if (lot[6] < 10) {
                        printf(" 0%d\n",lot[6]);
                    } else {
                        printf(" %d\n",lot[6]);
                    }    
                }
            }
        }
        printf("========csie@CGU========\n");
    }
    void_record(emp);
    
  return 0;
}
