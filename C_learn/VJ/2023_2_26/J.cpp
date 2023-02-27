#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int n, m;
long long num[N], num2[N];
long long ans[N];
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> m;
        long long sum1 = 0, sum2 = 0, answer = 1e9;
        for (int i = 1; i <= m; i++) {
            cin >> num[i];
            sum1 += num[i];
        }
        for (int i = 1; i <= m; i++) {
            cin >> num2[i];
            sum1 -= num[i];
            ans[i] = max(sum1, sum2);
            answer = min(ans[i], answer);
            sum2 += num2[i];
        }
        cout << answer << endl;
    }
}