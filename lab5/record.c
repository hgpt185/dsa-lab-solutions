#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "record.h"

CreditCard *createArray()
{
	CreditCard *arr = (CreditCard *)(malloc(sizeof(CreditCard) * 10));
	arr->size = 10;
	return arr;
}

bool isFull(CreditCard *arr, int num)
{

	if (num <= arr->size)
	{
		return false;
	}
	else
		return true;
}

CreditCard *resize(CreditCard *arr, int num)
{
	if (isFull(arr, num))
	{
		arr->size = arr->size * 2;
		arr = (CreditCard *)(realloc(arr, (sizeof(CreditCard) * arr->size) * 2));
	}
	return arr;
}

void insertelements(CreditCard *arr, CreditCard x, int num)
{

	if (num >= arr->size)
	{
		arr = resize(arr, num);
	}
	else
	{
		(arr + num)->card_number = x.card_number;
		strcpy(x.bnk_code, (arr + num)->bnk_code);
		(arr + num)->mth = x.mth;
		(arr + num)->year = x.year;
		strcpy((arr + num)->first_name, x.first_name);
		strcpy((arr + num)->last_name, x.last_name);
		num++;
	}
}

void printArray(CreditCard *arr, int num)
{
	printf("\n Starting\n");
	for (int i = 0; i < num; i++)
	{
		printf("%llu %s %u %u %s %s \n", (arr + i)->card_number, (arr + i)->bnk_code, (arr + i)->mth, (arr + i)->year, (arr + i)->first_name, (arr + i)->last_name);
	}
}