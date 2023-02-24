#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int main() {
    int n, flag = 0;
    cin >> n;
    int a, b, c;
    cin >> a >> b >> c;
    int d = min({a + b, a + c, b + c});
    if (d - c == b)
        flag = 2;
    else if (d - c == a)
        flag = 1;
    if (n == 1) {
        cout << 0 << endl;
    } else if (flag == 0) {
        cout << (n - 1) * min(a, b) << endl;
    } else if (flag == 1) {
        cout << a + (n - 2) * min(a, c) << endl;
    } else if (flag == 2) {
        cout << b + (n - 1) * min(b, c) << endl;
    }
}