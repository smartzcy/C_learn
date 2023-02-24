#include <iostream>
using namespace std;
const int N = 1e6;
int n, m, f[N];
int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}
int main() {
}