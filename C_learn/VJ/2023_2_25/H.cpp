#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2e4 + 10;
int n, m;
int num[N];
int main() {
    for (int i = 1; i <= 2000; i++) {
        num[i] = num[i - 1] + i;
    }
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        int cnt = 0;
        for (int i = 1; i <= 2000; i++) {
            if (num[i] >= n) {
                cnt = i;
                break;
            }
        }
        if (num[cnt] - 1 == n)
            cout << cnt + 1 << endl;
        else
            cout << cnt << endl;
    }
}