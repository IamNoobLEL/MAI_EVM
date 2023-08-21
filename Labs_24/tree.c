#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node* createNode()
{
    struct Node *new = malloc(sizeof(struct Node));
    return new;
}

struct Node* createTree(struct Token *t)
{
    struct Node *new = malloc(sizeof(struct Node));
    new->value = t;
    return new;
}

bool isMonomial(struct Node *node)//определяем имеет ли вид a*(...), (...)*a или a/(...)
{
    if(getMeaning(node) == isOperation)
    {
        if(GetValue(node)->value.operation == '*')
        {
            if(getMeaning(node->right) == isVariable)
            {
                if(getMeaning(node->left) != isVariable)
                    return true;
                else
                    return false;
            }
            else
            {
                if(getMeaning(node->left) == isVariable)
                    return true;
                else
                    return false;
            }
        }
        else if(GetValue(node)->value.operation == '/')
        {
            if(getMeaning(node->left) == isVariable)
            {
                if(getMeaning(node->right) != isVariable)
                    return true;
                else
                    return false;
            }
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}

struct Node *normalizeMonomial(struct Node *unnorm)//(...)*a превращаем в a*(...)
{
    char value[10];
    struct Node *mono = createTree(makeToken("*"));    
    if(getMeaning(unnorm->right) == isVariable)
    {
        snprintf(value, 10, "%s", GetValue(unnorm->right)->value.variable);
        mono->right = unnorm->left;
        mono->left = createTree(makeToken(value));
    }
    else
    {
        snprintf(value, 10, "%s", GetValue(unnorm->left)->value.variable);
        mono->right = unnorm->right;
        mono->left = createTree(makeToken(value));
    }
    return mono;
}

struct Node *buildMonomial(struct Node *var)// делаем из а 1*а
{
    char value[10];
    struct Node *mono = createTree(makeToken("*"));
    snprintf(value, 10, "%s", GetValue(var)->value.variable);
    mono->left = createTree(makeToken(value));
    mono->right = createTree(makeToken("1"));
    return mono;
}

bool equalStrings (char*s1, char*s2)//просто сравниваем строки
{
    int i = 0;
    bool out = true;
    while(i < 10 & (s1 [i] != '\0' | s2[i] != '\0'))
    {
        if(s1[i]!=s2[i++])
        {
            out = false;   
            break;
        }     
    }
    return out;
}

struct Node *groupLikeTerms (struct Node* term1, struct Node* term2, char *sign)//выносим как бы переменную за скобки
{
    struct Node *grouped = createNode();
    char res[10];
    int a, b;
    switch(getMeaning(term2))
    {
        case isOperation: // значит одночлен  
        grouped = createTree(makeToken("*"));
        grouped->right = createTree(makeToken(sign));//справа ставим знак 
        //после которого встретилась в выражении последнее слагаемое
        //так мы имитируем, смену знака, при внесении в скобку если перед ней минус
        snprintf(res, 10, "%s", GetValue(term1->left)->value.variable);
        grouped->left = createTree(makeToken(res));//слева ставим значение переменной
        if(GetValue(term1)->value.operation == '*')
        {
            grouped->right->left = createNode();
            *grouped->right->left = *term1->right;
        }
        else// а/(...) = a*(1/(...))
        {
            grouped->right->left = createTree(makeToken("/"));
            grouped->right->left->left = createTree(makeToken("1"));
            grouped->right->left->right = createNode();
            *grouped->right->left->right = *term1->right;
        }
        if(GetValue(term2)->value.operation == '*')
        {
            grouped->right->right = createNode();
            *grouped->right->right = *term2->right;
        }
        else
        {
            grouped->right->right = createTree(makeToken("/"));
            grouped->right->right->left = createTree(makeToken("1"));
            grouped->right->right->right = createNode();
            *grouped->right->right->right = *term2->right;
        }
        break;

        case isConstant:
        a = GetValue(term1)->value.constant;
        b = GetValue(term2)->value.constant;
        if(sign[0] == '+')
            snprintf(res, 10, "%d", a + b);
        else
            snprintf(res, 10, "%d", a - b);//константы сразу высчитываем
        grouped = createTree(makeToken(res));
        break;
        
        default://на всякий случай. Переменные и операции не одночлены не должны сюда попадать
        printf("fatal error 1\n");
        break;
    }
    drawTree(grouped, 1);
    return grouped;
}

struct Node returnLeftBranch(struct Node *root)
{
    struct Node leftBranch = *root->left;
    return leftBranch;
}

struct Node returnRightBranch(struct Node *root)
{
    struct Node rightBranch = *root->right;
    return rightBranch;
}

struct Node *findLikeTerms (struct Node* home, struct Node* pointer, char *s)
{//pоиск одинаковых
    char *curVar = malloc(10);
    switch(getMeaning(pointer->left))
    {
        case isOperation:
        if(!isMonomial(pointer->left))
        {
            if(isAdditive(GetValue(pointer->left)))//если слева плюс или минус
            {
                switch(getMeaning(pointer->left->right))
                {//если всё что угодно кроме операции (не одночлена) справа, то сравниваем его с тем что в home->right
                    case isOperation:
                    if(isMonomial(pointer->left->right))
                    {
                        snprintf(curVar, 10, "%s", GetValue(pointer->left->right->left)->value.variable);
                        if(equalStrings(curVar, s))//и объединяем в случае совпадения
                        {                         
                            snprintf(curVar, 10, "%c", GetValue(home)->value.operation);
                            home->right = groupLikeTerms(home->right, pointer->left->right, curVar);
                            home->right->right = simplify(home->right->right);
                            *pointer->left = returnLeftBranch(pointer->left);
                            home = findLikeTerms(home, pointer, s);
                        }
                        else
                            home = findLikeTerms(home, pointer->left, s);  
                    }
                    break;

                    case isVariable://никогда отдельно не обрабатываем просто переменную, а делаю из неё одночлен и прогоняю снова
                    *pointer->left->right = *buildMonomial(pointer->left->right);
                    home = findLikeTerms(home, pointer, s);
                    break;

                    case isConstant:
                    snprintf(curVar, 10, "%d", 1);
                    if(equalStrings(curVar, s))
                    {
                        snprintf(curVar, 10, "%c", GetValue(home)->value.operation);
                        home->right = groupLikeTerms(home->right, pointer->left->right, curVar);
                        home->right = simplify(home->right);
                        *pointer->left = returnLeftBranch(pointer->left);
                        home = findLikeTerms(home, pointer, s);//запускаем дальше
                    }
                    else
                        home = findLikeTerms(home, pointer->left, s);
                    break;
                    
                    default:
                    printf("fatal error 3\n");
                    break;
                }
            }
        }//если мы зашли ниже этой точки, значит все слагаемые просмотрены и это самое последнее
        else
        {
            *pointer->left = *normalizeMonomial(pointer->left);
            snprintf (curVar, 10, "%s", GetValue(pointer->left->left)->value.variable);
            if(equalStrings(curVar,s))
            {
                snprintf(curVar, 10, "%c", GetValue(home)->value.operation);
                home->right = groupLikeTerms(home->right, pointer->left, curVar);
                home->right->right = simplify(home->right->right);
                *pointer = returnRightBranch(pointer);
            }
        }
        break;

        case isVariable:
        *pointer->left = *buildMonomial(pointer->left);
        home = findLikeTerms(home, pointer, s);
        break;
        
        case isConstant:
        snprintf(curVar, 10, "%d", 1); 
        if(equalStrings(curVar,s))
        {
            snprintf(curVar, 10, "%c", GetValue(home)->value.operation);
            home->right = groupLikeTerms(home->right, pointer->left, curVar);
            home->right = simplify(home->right);
            *pointer = returnRightBranch(pointer);
            drawTree(home,1);
        }
        break;

        default:
            printf("fatal error 2\n");
        break;
    }
    free(curVar);
    return home;
}

struct Node* simplify(struct Node *current)
{//просто берёт переменную(или константу) с которой сравнивать и запускает от себя поиск таких же
    if(getMeaning(current) == isOperation)
    {        
        if(isAdditive(GetValue(current)))
        {
            char *curVar = malloc(10);
            switch(getMeaning(current->right))
            {
                case isOperation:
                if(isMonomial(current->right))
                {
                    current->right = normalizeMonomial(current->right);
                    snprintf(curVar, 10, "%s", GetValue(current->right->left)->value.variable);
                }
                else
                    *current->right = *simplify(current->right);
                break;

                case isVariable:
                snprintf(curVar, 10, "%s", GetValue(current->right)->value.variable);
                current->right = buildMonomial(current->right);
                break;

                case isConstant:
                snprintf(curVar, 10, "%d", 1);
                break;

                default:
                printf("fatal error 0\n");
                break;
            }
            current = findLikeTerms(current, current, curVar);
            free(curVar);
            if(getMeaning(current)==isOperation)//после find значение current могло измениться
                current->left = simplify(current->left);
        }
        else if(!isMonomial(current))
        {
            current->left = simplify(current->left);
            current->right = simplify(current->right);
        }
    }
    return current;
}

struct Combined buildTree (struct Node *current, struct StackNode *values)
{//строит дерево из стака. Один раз вызывается
    current = createTree(Top(values));//делаем ноду
    values = Pop(values);

    if(getMeaning(current) == isOperation)//если операция
    {
        struct Combined newLeft = buildTree(current->left, values);
        current->left = newLeft.node;//делаем левую
        values = newLeft.values;

        struct Combined newRight = buildTree(current->right, values);
        current->right = newRight.node;//делаем правую
        values = newRight.values;
    }

    struct Combined newCur;
    newCur.node = malloc(sizeof(struct Node));
    newCur.node = current;
    newCur.values = values;
    return newCur;
}

void printTree (struct Node *root)
{
    if(root->value->meaning == isOperation)
    {
        if((root->left->value->meaning == isOperation) && isPrioritized(root->value, root->left->value))
        {
            printf("(");
            printTree(root->left);
            printf(")");
        }
        else
            printTree(root->left);
    }

    if(root->value->meaning == isConstant)
        printf("%d", root->value->value.constant);
    else if(root->value->meaning == isVariable)
        printf("%s", root->value->value.variable);
    else 
        printf("%c", root->value->value.operation);

    if(root->value->meaning == isOperation)
    {
        if(getMeaning(root->right) == isOperation && (isPrioritized(GetValue(root), GetValue(root->right)) || GetValue(root)->value.operation == '-' && isAlike(GetValue(root->right),GetValue(root))))
        {//такое длинное условие из-за варианта -(...+...)
            printf("(");
            printTree(root->right);
            printf(")");
        }
        else
            printTree(root->right);
    }
    return;
}

void drawTree(struct Node *root, unsigned int level)
{
    if(root->value->meaning == isOperation)
    {
        drawTree(root->left, level + 1);
    }

    if(level > 0){
        for(int i = 1; i < level; i++)
            printf("\t");
        if(root->value->meaning == isConstant)
            printf("%d\n", root->value->value.constant);
        else if(root->value->meaning == isVariable)
            printf("%s\n", root->value->value.variable);
        else 
            printf("%c\n", root->value->value.operation);
    }

    if(root->value->meaning == isOperation)
    {
        drawTree(root->right, level + 1);
    }
    return;
}

void destroyTree(struct Node* current)
{
    if(getMeaning(current) == isOperation)
    {
        destroyTree(current->left);
        destroyTree(current->right);
    }
    free(current);
    return;
}

void destroyNode(struct Node* current)
{
    free(current);
    return;
}

struct Token *GetValue(struct Node *top)
{
    struct Token *value = malloc(sizeof(struct Token));
    value = top->value;
    return value;
}

enum Meaning getMeaning(struct Node *node)
{
    return node->value->meaning;
}