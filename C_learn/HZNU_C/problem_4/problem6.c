#include<stdio.h>
long long biao(long long m){
    long long k = 1;
    long long n = m;
    for(int i = 1; i < 29; i++){
        m = 2 * k + m;
        k = n;
        n = m;
    }
    return m;
}
int main(){
    long long int T;
    long long int m;
    scanf("%lld", &T);
    for(int i = 0; i < T; i++){
        scanf("%lld", &m);
        printf("%lld\n",biao(m));
    }
}