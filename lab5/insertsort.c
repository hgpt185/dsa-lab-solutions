#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "record.h"

void insertinroder(CreditCard *arr, CreditCard *x, int n)
{
	int j;
	j = n - 1;
	CreditCard *key = x;
	while (j >= 0 && (arr + j)->card_number > key->card_number)
	{
		*(arr + j + 1) = *(arr + j);
		j = j - 1;
	}
	*(arr + j + 1) = *key;
}

void insertion_sort(CreditCard *arr, int n)
{
	if (n <= 1)
	{
		return;
	}

	insertion_sort(arr, n - 1);
	CreditCard key = *(arr + n - 1);
	int j = n - 2;
	while (j >= 0 && (arr + j)->card_number > key.card_number)
	{
		*(arr + j + 1) = *(arr + j);
		j--;
	}
	*(arr + j + 1) = key;
	printArray(arr, n);
	
}
