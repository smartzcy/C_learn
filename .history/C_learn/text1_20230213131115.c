#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *fp;
    fp = fopen("1.txt", "r");
    if (fp == NULL) exit(EXIT_FAILURE);
    int m;
    fscanf(fp, "%d", &m);
    fclose(fp);
}