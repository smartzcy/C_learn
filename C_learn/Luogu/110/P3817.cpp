#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
long long n, m;
long long a[N];
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    long long last = a[0], cnt = 0;
    for (int i = 1; i < n; i++) {
        cnt += max(0LL, last + a[i] - m);
        last = a[i] - max(0LL, last + a[i] - m);
    }
    cout << cnt << endl;
}