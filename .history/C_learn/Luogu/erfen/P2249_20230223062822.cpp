#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;
int num[N];
int n, m;
int find(int x) {
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (num[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    if (num[l] == x)
        return l;
    else
        return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    while (m--) {
        int x;
        cin >> x;
        cout << find(x) << " ";
    }
}