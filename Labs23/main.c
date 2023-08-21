#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "tree.h"


int main(void)
{
    char s[8];

    Tree tree = NULL;
    int root = 0, ver = 0, parent = 0;

    printf("\nPrint 'help' for more information\n\n");
    while (1) {
        scanf("%7s", s);
        if (!strcmp(s, "insert") || !strcmp(s, "ins")) {
            if(!tree) {
                printf("Add the value of the tree root:\n");
                scanf("%d", &root);
                tree = tree_create(root);
            }
            while (scanf("%d%d", &parent, &ver)) {
                tree_add_node(tree, parent, ver);
            }
        } else if (!strcmp(s, "delete")) {
            if(!tree) printf("Tree doesnt exist, use command 'help'\n");
            else {
                scanf("%d", &ver);
                tree_del_node(tree, ver);
            }
        } else if (!strcmp(s, "quit")) {
            if (tree) tree_destroy(tree);
            break;
        } else if (!strcmp(s, "run")) {
            if(!tree) printf("Tree doesnt exist, use command 'help'\n");
            else {
                check_monotonicity_of_decreaset(tree);
            }
        } else if (!strcmp(s, "print")) {
            if (!tree) printf("Tree doesnt exist, use command 'help'\n");
            else {
                printf("\n\n");
                tree_print(tree);
                printf("\n\n");
            }
        } else if (!strcmp(s, "destroy")) {
            if (!tree) printf("Tree doesnt exist, use command 'help'\n");
            else {
                tree_destroy(tree);
                tree = NULL;
            }
        } else if (!strcmp(s, "help")) {
            printf("\n\nCommand 'insert' - if the tree doesnt exist, makes a tree. Command 'ins' - if tree was made, adds vertices in the tree\n\n");
            printf("Command 'delete num' deletes all the vertices and all her children\n\n");
            printf("Command 'print' prints the vertices of the tree\n\n");
            printf("Command 'run' checks monotonicity of decreseaset of the tree\n\n");
            printf("Command 'quit' stops the program\n\n");
            printf("Command 'destroy' deletes the tree completely\n\n");
        } else {
            printf("\n\nThat command doesnt exist, try command 'help' \n\n");
        }
    }
    return 0;
}