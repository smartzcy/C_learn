#include <iostream>
#include <vector>
using namespace std;
const int N = 2e5 + 10;
vector<int> vec[N];
int n, m;
int main() {
    cin >> n >> m;
    for (int i = 1, u, v; i < n; i++) {
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
}