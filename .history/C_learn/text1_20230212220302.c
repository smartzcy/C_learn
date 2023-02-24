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
    num1.sum = 100;
    printf("%d\n", num1.sum);
}