#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e4;
int n, m;
vector<int> vec[N];
int main() {
    int V, E, K;
    cin >> V >> E >> K;
    for (int i = 1, u, v; i <= V; i++) {
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
}