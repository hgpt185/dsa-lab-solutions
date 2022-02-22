#include <stdio.h>
#include <stdlib.h>

struct credit_card
{
	int size;
	long long unsigned card_number;
	char bnk_code[16];
	unsigned int mth, year;
	char first_name[50];
	char last_name[50];
};

typedef struct credit_card CreditCard;
extern CreditCard *createArray();
extern void printArray(CreditCard *arr, int num);
extern void insertelements(CreditCard *arr, CreditCard x, int num);
extern CreditCard *resize(CreditCard *arr, int num);
