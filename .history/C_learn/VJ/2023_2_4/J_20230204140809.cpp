#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
long long n, m, ans = 0;
int num[8] = {1, 6, 28, 88, 198, 328, 648};
int num2[8] = {8, 18, 28, 58, 128, 198, 388};
int main() {
    cin >> n;
    m = n;
    for (int i = 6; i >= 0; i--) {
        if (n >= num[i]) {
            n -= num[i];
            ans += num2[i];
        }
    }
    ans += m * 10;
    cout << ans << endl;
}