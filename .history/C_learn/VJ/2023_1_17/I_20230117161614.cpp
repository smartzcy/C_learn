#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 100;
int n, m;
vector<int> vec[N];
int d[N], c[N];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    while (m--) {
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
    }
    queue<int> que;
    que.push(1);
    while (!que.empty()) {
        int x = que.front();
        que.pop();
        for (auto i : vec[x]) {
            que.push(i);
            d[i] = max(d[i], d[x]);
        }
    }
}