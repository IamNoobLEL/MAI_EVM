#include <stdio.h>
#include "tree.h"

struct Node* parseCommand(char command, struct Node* root)
{   
    switch(command) 
    {
        case 't':
            drawTree(root, 1);
            break;
        case 'p':
            printTree(root);
            printf("\n");
            break;
        case 's':
            root = simplify(root);
            break;
        case 'h':
            printf("t - print in tree form\n");
            printf("p - print expression\n");
            printf("s - group like terms\n");
            printf("h - help (this)\n");
            printf("e - exit application\n");
            break;
        default:
            break;
    }    
    return root;
}

int main()
{
    struct Node *root = createNode();
    int fisrtNode;
    char exp;
    struct StackNode *stack = createStack();

    printf("Enter an expression\nNotice that variable names MUST be shorter than 11 symbols and MUST NOT begin with a digit\n");
 
    scanf("%s", &exp);            
    stack = makePolish(&exp);

    struct Combined combo;
    combo = buildTree(root, stack);
    root = combo.node;

    printf("Expression tree is built\n");
    root = parseCommand('h', root);

    while(fisrtNode) {
        char command;
        
        scanf("%c", &command);

        if(command == 'e'){
            if(root != NULL)
                destroyTree(root);//если закрываем то удаляется дерево
            break;
        }        
        root = parseCommand(command, root);//делаем что-то с ним
    }
}