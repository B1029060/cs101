#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RECORD_FILE "records.bin"
typedef struct lotto_record_t {
    int lotto_no;
    int lotto_receipt;
    char lotto_date[16];
} lotto_record_t;

int main() {
    char buzz[32];
    time_t now = time(0);
    strftime(buzz, 100, "%Y%m%d", localtime(&now));
    lotto_record_t read[256];
    int cnt_no, cnt_receipt, cnt_day=0;
    printf("========= lotto649 Report =========\n");
    printf("- Date ----- Num. ----- Receipt\n");
    FILE* fp = fopen(RECORD_FILE, "rb+");
    for (int i = 0, num = 1; i <= num; i++, num++) {
        fread(read[i].lotto_date, sizeof(read[i].lotto_date), RECORD_FILE, fp);
        if (read[i].lotto_date != NULL) {
            fread(read[i].lotto_no, sizeof(read[i].lotto_no), RECORD_FILE, fp);
            fread(read[i].lotto_receipt, sizeof(read[i].lotto_receipt), RECORD_FILE, fp);
            if (i == 0) {
                cnt_no = read[0].lotto_no;
                cnt_receipt = read[0].lotto_receipt;
            } else if (i > 0 && read[i].lotto_date == read[i-1].lotto_date) {
                cnt_no+= read[i].lotto_no;
                cnt_receipt+= read[i].lotto_receipt;
            } else if (i > 0 && read[i].lotto_date != read[i-1].lotto_date) {
                printf("\t%s", read[i].lotto_date);
                printf("\t%d", cnt_no);
                printf("\t%d\n", cnt_receipt);
                cnt_no = read[i].lotto_no;
                cnt_receipt = read[i].lotto_receipt;
                cnt_day++;
            }
        } else {
            printf("-----------------------------------\n");
            printf("\t%d\t%d\t%d\n",cnt_day, cnt_no, cnt_receipt);
            printf("========= %s =========\n", buzz);
            break;
        }
    }      
    return 0;
}