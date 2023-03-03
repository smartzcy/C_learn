#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int num[N];
int main() {
    int w;
    cin >> w;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    int l = 0, r = n - 1, ans = 0;
    sort(num, num + n);
    while (l <= r) {
        if (num[l] + num[r] > w) {
            ans++;
            r--;
        } else {
            ans++;
            r--;
            l++;
        }
    }
    cout << ans << endl;
}