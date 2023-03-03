#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int a[N];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    m = a[1];
    for (int i = 2; i <= n; i++)
        if (a[i] > a[i - 1]) m += a[i] - a[i - 1];
    cout << m;
}