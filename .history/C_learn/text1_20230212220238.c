#include <stdio.h>
#include <stdlib.h>
struct node {
    int l, r;
    long long sum;
};
struct node num1;
int cmp(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}
int main() {
    // int num[10] = {1, 5, 2, 4, 3, 8, 9, 2, 8, 10};
    // qsort(num, 10, sizeof(int), cmp);
    num1.sum = 100;
    printf("%d\n", num1.sum);
    // for (int i = 0; i < 10; i++) printf("%d ", num[i]);
}