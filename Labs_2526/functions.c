#include "functions.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
    void initStack(Stack* s){
        s->nodes = (Token*)malloc(sizeof(Token)*s->capacity);
        s->capacity = 2;
        s->size = 0;
    }
    void push(Stack* s, Token element){
        if (s->size == s->capacity){
            s->capacity = s->capacity * 2;
            s->nodes = (Token*)realloc(s->nodes, sizeof (Token)*s->capacity);
        };
        if (s->size == 0){
            s->nodes[s->size] = element;
            s->size++;
        }
        else{
            for (int i = s->size; i > 0; i--){
                s->nodes[i] = s->nodes[i-1];
            };
                s->nodes[0] = element;
                s->size++; 
        }
    }
    Token pop(Stack* s){
        if (s->size == 0) printf("Stack is empty\n");
        else {
            Token element;
            element = s->nodes[0];
            for (int i = 0; i < s->size; ++i){
                s->nodes[i] = s->nodes[i+1];
            };
            --s->size;
            return element;
        }
    }
    bool isEmpty(Stack* s){
        if (s->size == 0) return true;
        else return false;
    }
    void PrintStack(Stack* s){
        if (s->size == 0) printf("Stack is empty\n");
        else {
            for (int i = 0; i<s->size; i++){
                printf("%d ", s->nodes[i].value);
            };
            printf("\n");
        }
    }
    Token sub(Stack* s, int i){ //Поиск и удаление максимальной функции
        int max,maxnum,late;
        Token b;                    
        max = 0;
        maxnum = 0;
        for (int a = 0; a < i; a++){
            if (s->nodes[a].value > max){
                max = s->nodes[a].value;
                maxnum = a;
            }
        }
        while (s->nodes[0].value != max){
                Token t;
                t.value = s->nodes[0].value;
                for (int j = 0; j<i; j++){
                s->nodes[j].value = s->nodes[j+1].value;
                }
                s->nodes[i-1].value = t.value; 
            }
        b.value = s->nodes[0].value;
        pop(s);
        return b;
    }
    void function(Stack* s){ //сортировка
        for (int i = s->size; i>0; i--){
            Token t;
            t.value = s->nodes[i-1].value;
            push(s, t);
            s->nodes[i-1].value =  sub(s, i).value;
        }
    } 