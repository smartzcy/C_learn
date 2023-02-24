#include <iostream>
using namespace std;
const int N = 1e6;
int a[N];
int n;
int lowbit(int x){
    return x & -x;
}
void add(int x , int val){
    while(x <= n){
        a[x] += val;
        x += lowbit(x);
    }
}
int getsum(int x){
    int sum = 0;
    while(x > 0){
        sum += a[x];
        x -= lowbit(x);
    }
    return sum;
}