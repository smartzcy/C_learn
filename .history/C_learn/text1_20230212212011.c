#include <stdio.h>
int main() {
    char str[110];
    scanf("%s", str);
    int k = 0, sum = 0;
    while (str[k] != '\0') {
        if (str[k] <= '9' && str[k] >= '0') sum++;
        k++;
    }
}