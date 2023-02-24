#include <iostream>
using namespace std;
const int N = 1e6 + 7;
int Next[N];
string str;
void get_Next() {
    int j = 0;
    Next[0] = 0;
    Next[1] = 0;
    for (int i = 1; i < str.length(); i++) {
        if (j == 0 || str[i] == str[j]) {
            Next[i + 1] = ++j;
        } else {
            j = Next[j];
        }
    }
}
int main() {
    int len, ans = 0;
    cin >> len >> str;
    get_Next();
    for (int i = 1; i <= len; i++) {
        int j = i;
        while (Next[j]) j = Next[j];
        if (Next[i] != 0) Next[i] = j;
        ans += i - j;
    }
    cout << ans << endl;
}