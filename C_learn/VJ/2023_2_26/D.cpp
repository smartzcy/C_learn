#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e5;
int n, m;
int num[N], pos[N];
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> num[i];
            pos[num[i]] = i;
        }
        vector<int> ans(n);
        int t = 0;
        for (int i = n; i >= 1; i--) {
            int s = pos[i];
            ans[i - 1] = (s + 1) % i;
            for (int j = 1; j <= i; j++) {
                pos[j] = (pos[j] - 1 - s + i) % i;
            }
        }
        for (auto i : ans) cout << i << " ";
        cout << endl;
    }
}