#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int N = 1e5;
int n, m;
int f[N];
void INIT() {
    for (int i = 1; i <= 10000; i++) {
        f[i] = i;
    }
}
int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}
int main() {
    map<int, int> map1;
    int N;
    cin >> N;
    while (N--) {
        int k;
        cin >> k;
        int u;
        cin >> u;
        map1[u] = 1;
        for (int i = 1; i < k; i++) {
            int num;
            cin >> num;
            map1[num] = 1;
            if (find(u) != find(num)) f[num] = f[u];
        }
    }
    int count = 0;
    for (auto i : map1) {
        if (i.second == f[i.second]) count++;
    }
    cout << map1.size() << " " << count << endl;
}