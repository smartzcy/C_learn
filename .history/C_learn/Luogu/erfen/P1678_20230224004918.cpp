#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int n, m;
int num[N];
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> num[i];
    sort(num, num + n);
    int sum = 0;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        int ans = lower_bound(num, num + n, x) - num;
        sum += min(abs(x - num[ans]), abs(x - num[ans - 1]));
    }
    cout << sum << endl;
}