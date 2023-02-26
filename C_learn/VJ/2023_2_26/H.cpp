#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    int T;
    cin >> T;
    while (T--) {
        long long num;
        cin >> num;
        if (num <= 6)
            cout << 15 << endl;
        else {
            long long res = num / 6 * 15;
            num %= 6;
            if (num == 0)
                cout << res << endl;
            else if (num <= 2)
                cout << res + 5 << endl;
            else if (num <= 4)
                cout << res + 10 << endl;
            else
                cout << res + 15 << endl;
        }
    }
}