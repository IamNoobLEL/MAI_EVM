#include"functions.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int main() {
    Stack s;
    initStack(&s);
    char symbol;
    Token number;
    while ((symbol = getchar()) != EOF) {
        switch(symbol){
        case '+': {
            scanf("%d", &number.value);
            push(&s,number);
            break;
        }
        case '-': {
            pop(&s);
            break;
        }
        case '?': {
            if (isEmpty(&s)) {
                printf("Stack is empty\n");
                break;
            } 
            else 
                printf("Stack is not empty, size = %d\n", s.size);
                break;
        }
        case 'p':{
            PrintStack(&s);
            break;
        }
        case 'f':{
            function(&s);
            break;
        } 
     //   case 'c':{ использовалась при отладке
     //       int i = 4;
     //       sub(&s, i);
     //       break;
     //   } 
    }
    }
    free(s.nodes);

}