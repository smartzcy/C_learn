#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int N = 1e4;
int n, m;
string str[N];
char s[N][N];
int main() {
    char ch;
    cin >> ch >> n;
    getchar();
    for (int i = 0; i < n; i++) {
        getline(cin, str[i]);
    }
    // for (int i = 0; i < n; i++) cout << str[i] << endl;
    int flag = 1;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = str[i].length() - 1; j >= 0; j--) {
            if (str[i][j] != ' ')
                s[n - i - 1][str[i].length() - 1 - j] = ch;
            else
                s[n - i - 1][str[i].length() - 1 - j] = ' ';
            if (str[i][j] != str[n - i - 1][str[i].length() - 1 - j]) flag = 0;
        }
    }
    if (flag) cout << "bu yong dao le" << endl;
    for (int i = 0; i < n; i++) cout << s[i] << endl;
}