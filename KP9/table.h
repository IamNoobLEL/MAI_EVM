#ifndef table_h
#define table_h

#define SIZE_TABLE 15
#define BYTE_IN_VAL 60

typedef struct _Key
{
	int key;
} Key;

typedef struct _Val
{
	char val[BYTE_IN_VAL];
} Val;

void getRow(FILE *stream, char *str, const int size);
void read_table(Key k[], Val v[], int* size);
void printTable(const Key *k, const Val *v, const int size);
void sort (Key keys[], Val values[], const int size);
int isSorted(const Key *k, const int size);
int binSearch(const Key *k, const Val *v, const int size, const Key key);
void scramble(Key *k, Val *v, const int size);
void reverse(Key *k, Val *v, const int size);
#endif