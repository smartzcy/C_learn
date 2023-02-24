#include<stdio.h>
using namespace std;
int main(){
    long long n , m;
    while (scanf("%lld %lld",&n,&m),n != 0 && m != 0){
        //x + y = n
        //2x + 4y = m
        if((4 * n - m) % 2 != 0 || (m - 2 * n) % 2 != 0){
            printf("Error\n");
        }else{
            printf("%lld %lld\n",(4 * n - m) / 2,(m - 2 * n) / 2);
        }
    }
    return 0;
}