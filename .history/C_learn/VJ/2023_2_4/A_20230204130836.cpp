#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, ans;
        cin >> s;
        int x = s[s.length() - 1] - '0';
        for (int i = s.length() - 2; i >= 0; i--) {
            int y = s[i] - '0';
            if (x + y > 10) {
                cout << s.substr(0, i) << (x + y) << s.substr(i + 2) << endl;
                break;
            }
        }
    }
}