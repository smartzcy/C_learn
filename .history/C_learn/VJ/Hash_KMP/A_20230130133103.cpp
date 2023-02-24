#include <iostream>
using namespace std;
const int N = 1e5;
int next1[N], s1, ans[N];
string str;
void KMP() {
    int j = 0, k = -1;
    next1[0] = -1;
    while (j < s1) {
        if (k == -1 || str[k] == str[j]) {
            j++;
            k++;
            next1[j] = k;
        } else {
            k = next1[k];
        }
    }
}
int main() {
    while (cin >> str) {
        s1 = str.length();
        KMP();
        int j = next1[s1 - 1];
        int c = 0;
        while (j != -1) {
            if (str[j] == str[s1 - 1]) ans[c++] = t + 1;
            j = next1[j];
        }
        for (int i = c - 1; i >= 0; i--) {
            cout << ans[i] << " ";
        }
        cout << s1 << endl;
    }
}