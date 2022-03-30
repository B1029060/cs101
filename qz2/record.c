#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RECORD_FILE "records.bin"
#define REPORT_FILE "Report.txt"
typedef struct lotto_record_t {
    int lotto_no;
    int lotto_receipt;
    int emp_id;
    char lotto_date[16];
    char lotto_time[16];
} lotto_record_t;
typedef struct stat {
    int lotto_counter;
    int lotto_numset;
    int lotto_receipt;
    char lotto_date[16];
} stat_t;
const int TABLE_SIZE = 128;

int check_date_in_table(lotto_record_t rec, stat_t stat_table[], int table_size) {
    int i = -1;
    for (int i = 0; i < table_size; i++) {
        if (strcmp(rec.lotto_date, stat_table[i].lotto_date) == 0) {
            break;
        }
    }
    if (i >= table_size) {
        return -1;
    }
    return i;
}
void print_reportfile(stat_t stat_table[], int table_size) {
    int tot = 0;
    int tot_num = 0;
    int tot_numset = 0;
    int tot_receipt = 0;
    time_t timer;
    char t_buf[12];
    timer = time(NULL);
    strftime(t_buf, 12, "%Y%m%d", localtime(&timer));
    FILE* rpfp = fopen(REPORT_FILE, "w+");
    fprintf(rpfp, "========= lotto649 Report =========\n");
    fprintf(rpfp, "- Date ------ Num. ------ Receipt -\n");
    for (int i = 0; i < table_size; i++) {
        fprintf(rpfp, "%s\t\t%d/%d\t\t\t%d\n", stat_table[i].lotto_date, stat_table[i].lotto_counter, stat_table[i].lotto_numset, stat_table[i].lotto_receipt);
        tot++;
        tot_num += stat_table[i].lotto_counter;
        tot_numset += stat_table[i].lotto_numset;
        tot_receipt += stat_table[i].lotto_receipt;
    }
    fprintf(rpfp, "-----------------------------------\n");
    fprintf(rpfp, "%d\t\t\t\t%d/%d\t\t%d\n", tot, tot_num, tot_numset, tot_receipt);
    fprintf(rpfp, "========= %s Printed =========\n", t_buf);
    fclose(rpfp);
}
int main() {
    lotto_record_t rec;
    int table_indx = 0;
    int date_indx = -1;
    stat_t stat_table[TABLE_SIZE];
    FILE* rcfp = fopen(RECORD_FILE, "rb");
    while (fread(&rec, sizeof(lotto_record_t), 1, rcfp)) {
        if (date_indx = check_date_in_table(rec, stat_table, TABLE_SIZE) < 0) {    
            date_indx = table_indx++;
            strcpy(stat_table[date_indx].lotto_date, rec.lotto_date);
        } 
        stat_table[date_indx].lotto_counter++;
        stat_table[date_indx].lotto_receipt += rec.lotto_receipt;
        stat_table[date_indx].lotto_numset += (rec.lotto_receipt/55);
    }
    fclose(rcfp);

    return 0;
}