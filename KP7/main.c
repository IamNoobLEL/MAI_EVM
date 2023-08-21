#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int n, m;
    scanf("%d %d", &m, &n);
    int *CIP = (int *) malloc(sizeof(int) * m);
    int *PI = (int *) malloc(sizeof(int));
    int *YE = (int *) malloc(sizeof(int));
    int size_PI = 0;
    for (int i = 0; i < m; ++i) CIP[i] = -1;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int a;
            scanf("%d", &a);
            if (a != 0) {
                size_PI = size_PI + 1;
                PI = (int *) realloc(PI, size_PI * sizeof(int));
                YE = (int *) realloc(YE, size_PI * sizeof(int));
                YE[size_PI - 1] = a;
                PI[size_PI - 1] = j;
                if (CIP[i] == -1)
                    CIP[i] = size_PI - 1;
            }
        }
    }
    int last, next;
    printf("Matrix\n");

    for (int i = 0; i < m; ++i) {
        if (CIP[i] != -1) {
            int last = CIP[i];
            if (i == m - 1) next = size_PI - 1;
            else {
                for (int j = i + 1; j < m; ++j) {
                    if (CIP[j] != -1) {
                        next = CIP[j] - 1;
                        break;
                    }
                    if (j == m - 1) next = size_PI - 1;
                }
            }
            for (int j = 0; j < n; ++j) {
                if (last <= next && PI[last] == j) {
                    printf("%d ", YE[last]);
                    ++last;
                } else {
                    printf("0 ");
                }
            }
        } else {
            for (int j = 0; j < n; ++j) {
                printf("0 ");
            }
        }
        printf("\n");
    }
    int max = 0;

    for (int i = 0; i < m; ++i) {
        if (CIP[i] != -1) {
            int a, b;
            a = CIP[i];
            if (i == m - 1) {
                b = size_PI - 1;
            }
            for (int j = i + 1; j < m; ++j) {
                if (CIP[j] != -1) {
                    b = CIP[j] - 1;
                    break;
                }
                if (j == m - 1) b = size_PI - 1;
            }
            if (b - a + 1 > max) max = b - a + 1;
        }
    }
    printf("elements not equal zero -- %d\n", max);
    
    for (int i = 0; i < m; ++i) {
        if (CIP[i] != -1) {
            int a, b;
            a = CIP[i];
            if (i == m - 1) {
                b = size_PI - 1;
            }
            for (int j = i + 1; j < m; ++j) {
                if (CIP[j] != -1) {
                    b = CIP[j] - 1;
                    break;
                }
                if (j == m - 1) b = size_PI - 1;
            }
            if (b - a + 1 == max) {
                printf("i = %d ", i);
            }
            int ans = 0;
            for (int j = 0; j < n; ++j) {

            }
            if (b - a + 1 == max) {
                for(int k = a; k <= b; ++k){
                    ans += YE[k];
                }
                printf("Summa = %d\n", ans);
            }
        }
    }
    free(PI);
    free(CIP);
    free(YE);
}
