#ifndef PERSON_H
#define PERSON_H

typedef struct _Person {
	char FullName[60];
	int items;
	int weight;
	char dest[30];
	char time[5];
	int trans;
	int child;
} Person;

void create();
void print();
void var32();
void add();

#endif