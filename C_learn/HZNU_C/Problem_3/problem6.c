#include<stdio.h>
int main(){
    int N;
    while(scanf("%d", &N) != EOF) {
        int sum, sums;
        double end;
        sum = 0;
        sums = 0;
        end = 0;
        for(int i = 0; i < N; i++) {
            int n;
            scanf("%d", &n);
            if(n % 2 == 0) {
                sum = sum + n;
                sums = sums + n * n;
                end = end + 1.0 / n;
            }
        }
        printf("%d %d %.2f\n", sum, sums, end);
    }
}