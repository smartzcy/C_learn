#include <iostream>
using namespace std;
const int N = 1e6 + 7;
int Next[N];
string str;
void get_Next() {
    int j = 1, k = 0;
    Next[0] = 0;
    Next[1] = 0;
    while (j < str.length()) {
        if (k == 0 || str[j] == str[k])
            Next[++j] = ++k;
        else
            k = Next[k];
    }
}
int main() {
    int len, ans = 0;
    cin >> len >> str;
    get_Next();
    for (int i = 1; i <= len; i++) {
        int j = i;
        while (Next[j] != -1) j = Next[j];
        if (Next[i] != -1) Next[i] = j;
        ans += i - j;
    }
    cout << ans << endl;
}