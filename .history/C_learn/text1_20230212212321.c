#include <stdio.h>
int main() {
    double result = 0.0;
    int m;
    scanf("%d", &m);
    while (m <= 0 || m > 20) scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        result += 1.0 / i;
    }
    printf("%.2f", result);
}