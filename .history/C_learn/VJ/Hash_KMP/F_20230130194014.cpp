#include <iostream>
using namespace std;
const int N = 1e6 + 7;
string s;
int Next[N];
void get_Hash() {
    int j = 0, k = -1;
    while (j < s.length()) {
        if (k == -1 || s[k] == s[j])
            Next[++j] = ++k;
        else
            k = Next[k];
    }
}
int main() {
    cin >> s;
    get_Hash();
    // if (Next[s.length()] == 0) {
    //     cout << "Just a legend" << endl;
    //     return 0;
    // }
    // for (int i = 1; i < s.length(); i++) {
    //     if (Next[i] == Next[s.length()]) {
    //         cout << s.substr(0, Next[i]) << endl;
    //         return 0;
    //     }
    // }
    // if (Next[Next[s.length()]]) {
    //     cout << s.substr(0, Next[Next[s.length()]]) << endl;
    // }
    cout << "Just a legend" << endl;
    return 0;
}