#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdbool.h>

typedef struct{
    int value;
} Token;
typedef struct{
    Token* nodes;
    unsigned capacity;
    unsigned size;
} Stack;
void initStack(Stack*);
void push(Stack*, Token);
Token pop(Stack*);
Token sub(Stack*, int);
void function(Stack*);
void PrintStack(Stack*);
bool isEmpty(Stack*);
#endif
