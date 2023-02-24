#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    int n;
    cin >> n;
    int a, b, c;
    cin >> a >> b >> c;
    int d = min({a + b, a + c, b + c});
    if (n == 1) {
        cout << 0 << endl;
    } else if ((n - 1) % 2 == 0) {
        cout << d * (n - 1) / 2 << endl;
    } else {
        cout << d * (n - 1) / 2 + min({a, b, c}) << endl;
        cout << (n - 1) / 2 << endl;
    }
}