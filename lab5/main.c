#include <stdio.h>
#include <sys/time.h>
#include "record.h"
#include "insertsort.h"
#include <string.h>

int main()
{

    struct timeval start, stop;
    double secs = 0;

    gettimeofday(&start, NULL);

    long long unsigned card_number;
    char bnk_code[16];
    unsigned int expiry_d;
    unsigned int mth;
    char first_name[50];
    char last_name[50];


    FILE *fp = fopen("10", "r");
    CreditCard *arr = createArray();

    int i = 0;

    while (fscanf(fp, "\"%llu,%[^,],%u/%u,%[^,],%[^\"]\"\n", &card_number, bnk_code, &expiry_d, &mth, first_name, last_name) != -1)
    {
        printf("%llu\t%s\t%u / %u\t%s\t%s\n", card_number, bnk_code, expiry_d, mth, first_name, last_name);
        CreditCard temp;
        temp.card_number = card_number;
        strcpy(temp.first_name, first_name);
        strcpy(temp.last_name, last_name);
        strcpy(temp.bnk_code, bnk_code);
        temp.mth = expiry_d;
        temp.year = mth;
        
        insertelements(arr, temp, i);
        i++;
    }

    int num = i;
    printArray(arr, num);
    insertion_sort(arr, num);
    printArray(arr, num);
    gettimeofday(&stop, NULL);
    secs = (double)(stop.tv_sec - start.tv_sec);
    printf("time taken %f\n", secs);
}