#include <stdio.h>
#include <stdlib.h>
int cmp(int *a, int *b) {
    return *a - *b;
}
int main() {
    int num[10] = {1, 5, 2, 4, 3, 8, 9, 2, 8, 10};
    qsort(num, 10, sizeof(int), cmp);
    for (int i = 0; i < 10; i++) printf("%d ", num[i]);
}