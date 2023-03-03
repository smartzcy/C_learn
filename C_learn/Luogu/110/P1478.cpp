#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, s, a, b;
int main() {
    cin >> n >> s >> a >> b;
    pair<int, int> seg[N];
    for (int i = 0, u, v; i < n; i++) {
        cin >> u >> v;
        seg[i] = {v, u};
    }
    sort(seg, seg + n);
    int sum = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (sum + seg[i].first <= s && seg[i].second <= a + b) {
            cnt++;
            sum += seg[i].first;
        } else if (sum + seg[i].first > s)
            break;
    }
    cout << cnt << endl;
}