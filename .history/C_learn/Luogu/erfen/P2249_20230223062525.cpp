#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;
int num[N];
int n, m;
int find(int x) {
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (num[mid] < x)
            r = mid + 1;
        else
            l = mid - 1;
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
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    while (m--) {
        int x;
        cin >> x;
    }
}