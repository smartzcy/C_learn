#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
long long n, m, ans = 0;
int num[8] = {1, 6, 28, 88, 198, 328, 648};
int num2[8] = {8, 18, 28, 58, 128, 198, 388};
pair<double, int> num3[8];
int main() {
    cin >> n;
    m = n;
    for (int i = 0; i <= 6; i++) num3[i] = {num2[i] / num[i] * 1.0, i};
    sort(num3, num3 + 7);
    for (int i = 6; i >= 0; i--) {
        if (n >= num[num3[i].second]) {
            ans += num2[num3[i].second];
            n -= num[num3[i].second];
        }
    }
    ans += m * 10;
    cout << ans << endl;
}