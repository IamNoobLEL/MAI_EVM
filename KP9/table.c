#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "table.h"

void swapRows(Key *k, Val *v, const int a, const int b);
void getRow(FILE *stream, char *str, const int size);

void getRow(FILE *stream, char *str, const int size)
{
	int cnt = 0, ch;
	while ((ch = getc(stream)) != '\n' && cnt < size - 1){
		str[cnt++] = ch;
	}
	str[cnt] = '\0';
}

void printTable(const Key k[], const Val v[], const int size)
{
	printf("+--------+------------------------------------------------------------+\n");
	printf("|  Key   |                             Value                          |\n");
	printf("+--------+------------------------------------------------------------+\n");

	for (int i = 0; i < size; i++){
		printf("|%8d|%60s|\n", k[i].key, v[i].val);
	}
		printf("+--------+------------------------------------------------------------+\n");
}

void swap_int(int* a, int* b);
void swap_string(char str1[], char str2[]);

void sort (Key keys[], Val values[], const int size)
{
	for(int i = 1; i < size; i++){
		for(int j = i; j > 0 && keys[j - 1].key > keys[j].key; j--)
		{
			swapRows(keys, values, j - 1, j);
		}
	}
}

int isSorted(const Key *k, const int size);
int comparator(const Key k1, const Key k2);
int isEqualKeys(const Key k1, const Key k2);

int binSearch(const Key *k, const Val *v, const int size, const Key key)
{
	int start = 0, end = size - 1, mid;

	if (size <= 0)
		return -1;

	while (start < end)
	{
		mid = start + (end - start) / 2;
		if (isEqualKeys(k[mid], key))
			return mid;
		else if (comparator(k[mid], key))
			start = mid + 1;
		else
			end = mid;
	}
	if (isEqualKeys(k[end], key))
		return end;

	return -1;
}

int isSorted(const Key *k, const int size)
{
	for (int i = 0; i < size - 1; i++)
		if (!comparator(k[i], k[i + 1]))
			return 0;

	return 1;
}

int comparator(const Key k1, const Key k2)
{
	return k2.key >= k1.key;
}

int isEqualKeys(const Key k1, const Key k2)
{
	return k1.key == k2.key;
}

int randomAB(const int a, const int b);

void scramble(Key *k, Val *v, const int size)
{
	int i, j, z;

	srand((unsigned int)time(0));

	for (z = 0; z < size; z++)
	{
		i = randomAB(0, size - 1);
		j = randomAB(0, size - 1);

		swapRows(k, v, i, j);
	}
}


int randomAB(const int a, const int b)
{
	return a + rand() % (b - a + 1);
}

void swapRows(Key *k, Val *v, const int a, const int b)
{
	Key tmpKey;
	Val tmpVal;

	tmpKey = k[a];
	k[a] = k[b];
	k[b] = tmpKey;

	tmpVal = v[a];
	v[a] = v[b];
	v[b] = tmpVal;
}


void reverse(Key *k, Val *v, const int size)
{
	int i, j;
	for (i = 0, j = size - 1; i < j; i++, j--)
		swapRows(k, v, i, j);
}
