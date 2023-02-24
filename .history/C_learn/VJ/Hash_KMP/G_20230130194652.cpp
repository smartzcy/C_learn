#include <iostream>
using namespace std;
const int N = 1e5;
int Next[N];
int get_Next(string str) {
    int j = 0, k = -1;
    Next[0] = -1;
    while (j < str.length()) {
        if (k == -1 || str[k] == str[j])
            Next[++j] == ++k;
        else
            k = Next[k];
    }
}
int main() {
    int n;
    cin >> n;
    while (n--) {
        string str;
        cin >> str;
    }
}