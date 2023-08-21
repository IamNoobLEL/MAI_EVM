#include <stdbool.h>
#include "stack.h"

struct Node 
{
     struct Token *value;
     struct Node* left;
     struct Node* right;
};

struct Combined 
{
     struct Node *node;
     struct StackNode *values;
};

struct Node* createNode();
struct Node* createTree(struct Token *);
struct Combined buildTree(struct Node *, struct StackNode *);
struct Node* simplify (struct Node *);
void printTree (struct Node *);
void drawTree (struct Node*, unsigned int);
void destroyTree (struct Node* );
void destroyNode (struct Node* );
struct Token *GetValue(struct Node *);
enum Meaning getMeaning(struct Node *);