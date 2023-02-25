#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        int flag = 0;
        for (int i = 0; i < n; i++) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            if (b == c) flag = 1;
        }
        if (flag && m % 2 == 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}