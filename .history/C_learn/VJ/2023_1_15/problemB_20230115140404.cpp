#include <iostream>
using namespace std;
const int maxn = 10000000;
bool not_prime[maxn + 5];
int prime[maxn + 5], tot = 0;
void get_prime(int n) {
    for (int i = 2; i <= n; i++) {
        if (!not_prime[i]) prime[++tot] = i;
        for (int j = 1; j <= tot && i * prime[j] <= n; j++) {
            not_prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}
int main() {
    int num;
    get_prime(10000);
    while (cin >> num, num != 0) {
        int ans = 0;
        for (int i = 1; i <= tot; i++) {
            int sum = prime[i];
            if (sum > num)
                break;
            else if (sum == num) {
                ans++;
                break;
            }
            for (int j = i + 1; j <= tot; j++) {
                sum += prime[j];
                if (sum > num)
                    break;
                else if (sum == num) {
                    ans++;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
}