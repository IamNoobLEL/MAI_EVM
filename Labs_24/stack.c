#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
struct StackNode* makePolish(char *s/*просто вся первая строка*/)
{//название само за себя. Только обратную польскую
    int pos = 0, posInWord = 0;
    struct StackNode *expression = createStack();
    struct Token *t;
    char str[10];
    for(int i = 0; i < 10; i++)
        str[i] = '\0';
    while(s[pos])
    {
        char c = s[pos++];
        if(GetMeaning(&c)==isOperation)
        {
            if(c == '-' & posInWord == 0)//минус который перед отрицательным числом
            {
                str[posInWord++] = c;
            }
            else//плюсы и минусы как операции
            {
            t = makeToken(str);
            expression = Push(expression, t);
            t = makeToken(&c);
            expression = Push(expression, t);
            for(int i = 0; i < posInWord; i++)
                str[i] = '\0';
            posInWord = 0;
            }
        }
        else if(c == ')')
        {
            t = makeToken(str);
            expression = Push(expression, t);
            for(int i = 0; i < posInWord; i++)
                str[i] = '\0';
            posInWord = 1;
            str[0] = c;
        }
        else if(c == '(')
        {
            t = makeToken(&c);
            expression = Push(expression, t);
        }
        else
            str[posInWord++] = c;
    }
    t = makeToken(str);
    expression = Push(expression, t);
    //разбили строку на токены, теперь делаем из них обратную польскую
    struct StackNode *stack = createStack();
    struct StackNode *reversed = createStack();

    while(expression->next)//алгоритм сортировочной станции
    {
        t = Top(expression);
        expression = Pop(expression);
        struct Token *current = malloc(sizeof(struct Token));
        switch (t->meaning)
        {
            case isOperation:
                current = Top(stack);
                while((stack->next) && (current->meaning == isOperation) && !isPrioritized(t, current) && !isAlike(t, current)/*так как обрабатываем выражение как бы справа на лево, то операции с тем же приоритетом не выбрасываем*/)
                {
                    reversed = Push(reversed, current);
                    stack = Pop(stack);
                    current = Top(stack);
                }
                stack = Push(stack, t);
            break;
            case isConstant:
                reversed = Push(reversed, t);
            break;
            case isVariable:
                reversed = Push(reversed, t);
            break;
            case isBracket:
                if(t->value.operation == ')')
                    stack = Push(stack, t);
                else
                {
                    current = Top(stack);
                    while((stack->next) && (current->meaning != isBracket) && (current->value.operation != '('))
                    {                        
                        reversed = Push(reversed, current);
                        stack = Pop(stack);
                        current = Top(stack);
                    }
                    if(stack->next)
                        stack = Pop(stack);
                    else
                        printf("missed bracket");
                }
            break;
        }
    }
    while (stack->next)
    {
        reversed = Push(reversed, Top(stack));
        stack = Pop(stack);
    }
    destroyStack(stack);
    destroyStack(expression);
    return reversed;
}

struct StackNode* createStack()
{
    struct StackNode *new = malloc(sizeof(struct StackNode));
    new->order = 0;
    return new;
}

struct StackNode* Push(struct StackNode *top, struct Token *value)
{
    struct StackNode *new = malloc(sizeof(struct StackNode));
    struct Token *newValue = malloc(sizeof(struct Token));
    *newValue = *value;
    new->next = top;
    new->tValue = value;
    new->order = top->order + 1;
    return new;
}

struct StackNode* Pop(struct StackNode *top)
{
    struct StackNode *temp = top;
    top = top->next;
    free(temp);
    return top;
}

struct Token *Top(struct StackNode *top)
{
    struct Token *value = malloc(sizeof(struct Token));
    value = top->tValue;
    return value;
}

void destroyStack (struct StackNode *top)
{
    if(top->next)
        destroyStack (top->next);
    free(top);
    return;
}