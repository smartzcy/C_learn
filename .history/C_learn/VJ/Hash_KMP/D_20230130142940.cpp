#include <iostream>
using namespace std;
const int N = 1e6 + 7;
int Next[N];
string str;
void get_Next() {
    int j = 0, k = -1;
    Next[0] = -1;
    while (j < str.length())
        if (k == -1 || str[j] == str[k])
            Next[++j] == ++k;
        else
            k = Next[k];
}
int main() {
    int len;
    cin >> len >> str;
    get_Next();
    for (int i = 1; i <= len; i++) {
        int cnt = i - Next[i];
        if (Next[i] > 0 && i % cnt == 0) cout << i << " " << i / cnt << endl;
    }
}