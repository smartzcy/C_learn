// #include<iostream>
// #include<stdio.h>
// using namespace std;
// void pri(long long a , long long b){
//     if(a * b < 0){
//         if(a / b != 0 && a % b == 0) printf("(%d)",a / b);
//         else if(a / b != 0 && a % b != 0) printf("(%d %d/%d)",a / b,abs(a % b), abs(b));
//         else if(a == 0) printf("0");
//         else printf("(%d/%d)",a , b);
//     }else{
//         if(a / b != 0 && a % b == 0) printf("%d",a / b);
//         else if(a / b != 0 && a % b != 0) printf("%d %d/%d",a / b,a % b, b);
//         else if(a == 0) printf("0");
//         else printf("%d/%d",a , b);
//     }
// }
// long long big(long long x , long long y){
//     while(x % y != 0){
//         long long k = x % y;
//         x = y;
//         y = k;
//     }
//     return y;
// }
// long long min(long long x , long long y){
//     long long b = y;
//     y = big(x , y);
//     return x * b / y;
// }
// int main(){
//     long long a1 , a2 , b1 , b2;
//     scanf("%lld/%lld %lld/%lld",&a1,&b1,&a2,&b2);
//     for(int i = 0 ; i < 4;i++){
//         pri(a1,b1);
//         if(i == 0) cout << " + ";
//         else if(i == 1) cout << " - ";
//         else if(i == 2) cout << " * ";
//         else if(i == 3) cout << " / ";
//         pri(a2,b2);
//         cout << " = ";
//         long long a3 , b3;
//         if(i == 0){
//             b3 = min(b1,b2);
//             a3 = a1 * (b3 / b1) + a2 * (b3 / b2);
//         }else if(i == 1){
//             b3 = min(b1,b2);
//             a3 = a1 * (b3 / b1) - a2 * (b3 / b2);
//         }else if(i == 2){
//             b3 = b1 * b2;
//             a3 = a1 * a2;
//         }else if(i == 3){
//             if(a2 == 0){
//                 cout << "Inf" << endl;
//                 continue;
//             }else{
//                 a3 = a1 * b2;
//                 b3 = b1 * a2;
//             }
//         }
//         long long k = big(a3,b3);
//         b3 /= k;
//         a3 /= k;
//         if(b3 < 0){
//             b3 = -b3;
//             a3 = - a3;
//         }
//         pri(a3,b3);
//         cout << endl;
//     }
// }

#include <iostream>
#include <cmath>
using namespace std;
long long a, b, c, d;
long long gcd(long long t1, long long t2) {
    return t2 == 0 ? t1 : gcd(t2, t1 % t2);
}
void func(long long m, long long n) {
    if (m * n == 0) {
        printf("%s", n == 0 ? "Inf" : "0");
        return ;
    }
    bool flag = ((m < 0 && n > 0) || (m > 0 && n < 0));
    m = abs(m); n = abs(n);
    long long x = m / n;
    printf("%s", flag ? "(-" : "");
    if (x != 0) printf("%lld", x);
    if (m % n == 0) {
        if(flag) printf(")");
        return ;
    }
    if (x != 0) printf(" ");
    m = m - x * n;
    long long t = gcd(m, n);
    m = m / t; n = n / t;
    printf("%lld/%lld%s", m, n, flag ? ")" : "");
}
int main() {
    scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
    func(a, b); printf(" + "); func(c, d); printf(" = "); func(a * d + b * c, b * d); printf("\n");
    func(a, b); printf(" - "); func(c, d); printf(" = "); func(a * d - b * c, b * d); printf("\n");
    func(a, b); printf(" * "); func(c, d); printf(" = "); func(a * c, b * d); printf("\n");
    func(a, b); printf(" / "); func(c, d); printf(" = "); func(a * d, b * c);
    return 0;
}