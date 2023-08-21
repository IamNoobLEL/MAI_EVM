#include <stdbool.h>
#include <stdlib.h>
#include "token.h"

struct Token *makeToken(char s[10])
{
    char c = s[0];
    struct Token *token = malloc(sizeof(struct Token));
    if(GetMeaning(&c) == isConstant)
    {
        token->meaning = isConstant; 
        token->value.constant = atoi(s);//преобразуем строку в число
    }
    else if(GetMeaning(&c) == isOperation | GetMeaning(&c) == isBracket)
    {
        token->meaning = GetMeaning(&c);
        token->value.operation = c;
    }
    else
    {
        token->meaning = isVariable;
        char *new = malloc(10);
        for(int i = 0; i < 10; i++)
            new[i] = s[i];
        token->value.variable = new;
    }
    return token;
}

enum Meaning GetMeaning (char *symbol)//по первому знаку определяет смысл строки
{
    if(*symbol >= 42 & *symbol < 44 | *symbol == 45 | *symbol == 47) //+ - * /
        return isOperation;
    else if(*symbol >= 48 & *symbol < 58)//0...9
        return isConstant;
    else if(*symbol >= 97 & *symbol < 123)//a...z
        return isVariable;
    else if(*symbol >= 40 & *symbol < 42)// (,)
        return isBracket;
    else
        return null
}

bool isAdditive(struct Token *t)
{
    return t->meaning == isOperation & (t->value.operation == '+' | t->value.operation == '-');
}

bool isMultiplicative(struct Token *t)
{
    return t->meaning == isOperation & (t->value.operation == '*' | t->value.operation == '/');
}

bool isAlike (struct Token *token1, struct Token *token2)
{
    char newOp = token1->value.operation;
    char oldOp = token2->value.operation;

    if(newOp == '+' | newOp == '-')
    {
        if(oldOp == '+' | oldOp == '-')
            return true;
        else
            return false;
    }
    else if(newOp == '*' | newOp == '/')
    {
        if(oldOp == '*' | oldOp == '/')
            return true;
        else
            return false;
    }
}

bool isPrioritized (struct Token *t1,struct Token *t2)
{
    char newOp = t1->value.operation;
    char oldOp = t2->value.operation;

    if(oldOp == '*' | oldOp == '/')
        return false;
    else if (oldOp == '+' | oldOp == '-')
    {
        if(newOp == '*' | newOp == '/')
            return true;
        else
            return false;
    }        
}