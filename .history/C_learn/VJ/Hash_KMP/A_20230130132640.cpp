#include <iostream>
using namespace std;
const int N = 1e5;
int next1[N], s1, ans[N];
string str;
void KMP() {
    int j = 0, k = 0;
    while (j < s1) {
        if (k == 0 || str[k] == str[j]) {
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
        int j = next1[s1];
        int c = 0;
        while (j > 0) {
            ans[c++] = j;
            j = next1[j];
        }
        for (int i = c - 1; i >= 0; i--) {
            cout << ans[i] << " ";
        }
        cout << s1 << endl;
    }
}