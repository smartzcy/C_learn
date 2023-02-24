#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int fa[N];
void INIT() {
    for (int i = 1; i <= n; i++) fa[i] = i;
}
int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int main() {
    cin >> n >> m;
}