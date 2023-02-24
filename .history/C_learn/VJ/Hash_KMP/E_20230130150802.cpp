#include <iostream>
using namespace std;
const int N = 1e5;
string s1, s2, ans;
int Next[N];
void get_Next() {
    Next[0] = -1;
    int j = 0, k = -1;
    while (j < s2.length()) {
        if (k == -1 || s2[j] == s2[k])
            Next[++j] = ++k;
        else
            k = Next[k];
    }
}
int main() {
    cin >> s1 >> s2;
    get_Next();
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < s1.length(); i++) s1[i] == '0' ? cnt0++ : cnt1++;
    int j = 0;
    while (cnt0 > 0 && cnt1 > 0) {
    }
}