#include <iostream>
using namespace std;
const int N = 1e6;
int n, m;
int a[N];
int lowbit(int x) {
    return x & -x;
}
void add(int x, int val) {
    while (x <= n) {
        a[x] += val;
        x += lowbit(x);
    }
}
int getSum(int x) {
    int sum = 0;
    while (x > 0) {
        sum += a[x];
        x -= lowbit(x);
    }
}
int main() {
}