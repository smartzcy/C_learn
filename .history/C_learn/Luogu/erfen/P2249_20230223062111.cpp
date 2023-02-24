#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;
int num[N];
int n, m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    while (m--) {
        int x;
        cin >> x;
        cout << lower_bound(num, num + n, x) - num << " ";
    }
}