#include <iostream>
using namespace std;
const int N = 1e5;
int Next[N];
string s;
void get_next() {
    int j = 0, k = -1;
    Next[0] = -1;
    while (j < s.length()) {
        if (k == -1 || s[k] == s[j]) {
            Next[++j] = ++k;
        } else
            k = Next[k];
    }
}
int main() {
    int len;
    int k = 1;
    while (cin >> len, len != 0) {
        cout << "Test case #" << k++ << endl;
        cin >> s;
    }
}