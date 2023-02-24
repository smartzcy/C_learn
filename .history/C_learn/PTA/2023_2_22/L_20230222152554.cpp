#include <iostream>
#include <algorithm>
#include <set>
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
    INIT();
    set<int> s1;
    int N;
    cin >> N;
    while (N--) {
        int k;
        cin >> k;
        int u;
        cin >> u;
        s1.insert(u);
        int fu = find(u);
        for (int i = 1; i < k; i++) {
            int num;
            cin >> num;
            s1.insert(num);
            int fa = find(num);
            if (fa != fu) f[fa] = fu;
        }
    }
    int count = 0;
    for (auto i : s1) {
        if (i == f[i]) count++;
    }
    cout << s1.size() << " " << count << endl;
}