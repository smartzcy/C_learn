#include <iostream>
using namespace std;
const int N = 1e6;
int n, m, f[N];
void INIT() {
    for (int i = 1; i <= n; i++) f[i] = i;
}
int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}
int main() {
}