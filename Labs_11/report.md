# Отчет по лабораторной работе N 11 по курсу
# "Фундаментальная информатика"

Студент группы: Боев Савелий Сергеевич, M80-107Б\
Контакты: bogsava123@gmail.com  telegram: @muuuusor\
Работа выполнена: 10.01.2022\
Преподаватель: Найденов Иван Евгеньевич

## 1. Тема

Простейшие приёмы лексического анализа.

## 2. Цель работы

С помощью конечных автоматов составить программу на языке Си, выполняющую анализ и обработку вводимого текста в соответствии с заданием.

## 3. Задание

Составить программу, выполняющую анализ и обработку вводимого ascii-текста. Требуется построчно выделить первое и последнее (по счету) десятичные числа строк текста. При решении задачи необходимо использовать матаппарат конечных автоматов. Запрещено использовать массивы, указатели и явные числовые коды ascii-знаков (например, число 48 вместо литерной константы '0').

## 4. Оборудование

Процессор: AMD Ryzen 5 4600H with Radeon Graphics 3.00 GHz\
ОП: 16000 Мб\
НМД: 512 Гб\
Монитор: 1920x1080

## 5. Программное обеспечение

Операционная система семейства: **linux (ubuntu)**, версия **18.10 cosmic**\
Интерпретатор команд: **bash**, версия **4.4.19**.\
Система программирования: **--**, версия **--**\
Редактор текстов: **emacs**, версия **25.2.2**\
Утилиты операционной системы: **--**\
Прикладные системы и программы: **--**\
Местонахождение и имена файлов программ и данных на домашнем компьютере: **--**\

## 6. Идея, метод, алгоритм решения задачи

![](https://i.imgur.com/Qa7iUTW.gif)

## 7. Сценарий выполнения работы

| Входные данные | Выходные данные |
| -------------- | --------------- |
|123|123|
|abra212 2123 vingadium 2123|2123 2123|
|928357av -careful 1234|1234 1234|
|nothing|                        |
|aim do 05 -150 man -19|05 -19  |                  

## 8. Распечатка протокола

```
#include <stdio.h>
#include <math.h>

int is_endl(char c)
{
    if (c == '\n') {
        return 1;
    }
    return 0;
}
int is_space(char c)
{
    if (c == ' ') {
        return 1;
    }
    return 0;
}
int is_minus(char c)
{
    if (c == '-') {
        return 1;
    }
    return 0;
}
int is_plus(char c)
{
    if (c == '+') {
        return 1;
    }
    return 0;
}
int is_musor(char c)
{
    if ((c >= 0 && c < '\n') || (c > '\n' && c < ' ') || (c > ' ' && c < '+') || (c > '+' && c < '-') || (c > '-' && c < '0') || (c > '9')) {
        return 1;
    }
    return 0;
}
int is_znak(char c)
{
    if (c == '+' || c == '-') {
        return 1;
    }
    return 0;
}
int is_num(char c)
{
    if (c >= '0' && c <= '9') {
        return 1;
    }
    return 0;
}
void numout(long long x, int j, int s) //воссановление числа
{
    int q;
    if (s == 1) {
        printf("+");
    } else if (s == -1) {
        printf("-");
    }
    if (x >= 0) {
        while (j != 0) {
            q = x / pow(10, j - 1);
            printf("%d", q);
            x = x - q * pow(10, j - 1);
            j = j - 1;
        }
    }
    printf(" ");
}
typedef enum {
    S0, S1, S2, S3, S4, S5, S6, S7
} State;
int main(void)
{
    int k = 1;
    int j = 1;
    int fsign = 0;
    int lsign = 0;
    int lnumber = 0;
    int rar = 0;
    int i = 1;
    int znak = 0;
    char c;
    long long number2 = 0;
    long long number3 = 0;
    long long number4 = 0;
    State state = S0;
    while ((c = getchar()) != EOF) {
        switch (state) {
            case S0:
                if (is_space(c) == 1 || is_endl(c) == 1) {
                    state = S0;
                } else if (is_musor(c)) {
                    state = S1;
                } else if (is_plus(c)) {
                    fsign = 1;
                    state = S4;
                } else if (is_minus(c)) {
                    fsign = -1;
                    state = S4;
                } else if (is_num(c)) {
                    fsign = 0;
                    number2 = c - '0';
                    state = S2;
                }
                break;
            case S1:
                if (is_space(c) == 1 || is_endl(c) == 1) {
                    state = S0;
                } else if (is_musor(c) == 1) {
                    state = S1;
                }
                break;
            case S2:
                if (is_num(c)) {
                    rar = c - '0';
                    number2 = number2 * 10 + rar;
                    i = i + 1;
                    state = S2;
                } else if (is_musor(c) == 1) {
                    i = 1;
                    number2 = 0;
                    fsign = 0;
                    state = S1;
                } else if (is_endl(c)) {
                    numout(number2, i, fsign);
                    numout(number2, i, fsign);
                    printf("\n");
                    i = 1;
                    number2 = 0;
                    fsign = 0;
                    state = S0;
                } else if (is_space(c)) {
                    numout(number2, i, fsign);
                    number4 = number2;
                    lnumber = i;
                    lsign = fsign;
                    state = S5;
                }
                break;
            case S3:
                if (is_num(c)) {
                    rar = c - '0';
                    number3 = number3 * 10 + rar;
                    j = j + 1;
                    state = S3;
                } else if (is_musor(c) == 1) {
                    j = 1;
                    number3 = 0;
                    lsign = 0;
                    state = S6;
                } else if (is_endl(c)) {
                    number4 = number3;
                    lnumber = j;
                    znak = lsign;
                    numout(number4, lnumber, znak);
                    j = 1;
                    printf("\n");
                    i = 1;
                    fsign = 0; lsign = 0; znak = 0;
                    lnumber = 0; number4 = 0; number3 = 0; number2 = 0;
                    state = S0;
                } else if (is_space(c)) {
                    number4 = number3;
                    znak = lsign;
                    lsign = 0;
                    lnumber = j;
                    j = 1;
                    state = S5;
                }
                break;
            case S4:
                if (is_num(c)) {
                    number2 = c - '0';
                    state = S2;
                } else if (is_musor(c) == 1) {
                    state = S1;
                } else if (is_endl(c) == 1 || is_space(c) == 1) {
                    state = S0;
                }
                break;
            case S5:
                if (is_musor(c)) {
                    state = S6;
                } else if (is_num(c)) {
                    number3 = c - '0';
                    lsign = 0;
                    state = S3;
                } else if (is_plus(c)) {
                    lsign = 1;
                    state = S7;
                } else if (is_minus(c)) {
                    lsign = -1;
                    state = S7;
                } else if (is_space(c)) {
                    number4 = number3;
                    lnumber = j;
                    znak = lsign;
                    lsign = 0;
                    j = 1;
                    state = S5;
                } else if (is_endl(c)) {
                    znak = lsign;
                    numout(number4, lnumber, znak);
                    printf("\n");
                    j = 1;
                    i = 1;
                    fsign = 0; lsign = 0; znak = 0;
                    lnumber = 0; number4 = 0; number3 = 0; number2 = 0;
                    state = S0;
                }
                break;
            case S6:
                if (is_musor(c) == 1) {
                    state = S6;
                } else if (is_space(c)) {
                    state = S5;
                } else if (is_endl(c)) {
                    numout(number4, lnumber, znak);
                    printf("\n");
                    j = 1; i = 1;
                    fsign = 0; lsign = 0; znak = 0;
                    lnumber = 0; number4 = 0; number3 = 0; number2 = 0;
                    state = S0;
                }
                break;
            case S7:
                if (is_num(c)) {
                    number3 = c - '0';
                    state = S3;
                } else if (is_musor(c) == 1) {
                    state = S6;
                } else if (is_space(c) == 1) {
                    state = S5;
                } else if (is_endl(c)) {
                    numout(number4, lnumber, znak);
                    printf("\n");
                    j = 1; i = 1;
                    fsign = 0; lsign = 0; znak = 0;
                    lnumber = 0; number4 = 0; number3 = 0; number2 = 0;
                    state = S0;
                }
                break;
        }
    }
    return 0;
}

```

## 9. Дневник отладки

## 10. Замечания автора по существу работы

Замечаний нет.

## 11. Выводы

Было интересно работать с конечными автоматами в СИ.
