#include "token.h"

struct StackNode
{
    struct Token *tValue;
    unsigned int order;
    struct StackNode *next;
};

struct StackNode* makePolish(char *);
struct StackNode* createStack();
struct StackNode* Push(struct StackNode *, struct Token *);
struct StackNode* Pop(struct StackNode *);
struct Token *Top(struct StackNode *);
void destroyStack (struct StackNode *);