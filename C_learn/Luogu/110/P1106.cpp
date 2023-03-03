#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    string str;
    cin >> str;
    cin >> n;
    int last = 0, flag = 0;
    n = str.size() - n;
    for (int i = n - 1; i >= 0; i--) {
        char ch = str[last];
        int k = last;
        for (int j = last + 1; j < str.length() - i; j++) {
            if (ch > str[j]) {
                ch = str[j];
                k = j;
            }
        }
        if (ch == '0' && flag == 0) {
        } else {
            cout << ch;
            flag = 1;
        }
        last = k + 1;
    }
    if (flag == 0) cout << 0;
}

// #include <iostream>
// #include <algorithm>
// using namespace std;
// const int N = 1e5;
// int n, m;
// int a[N];
// int main() {
//     string str;
//     cin >> str >> n;
//     int len = str.size();
//     for (int i = 0; i < len; i++) a[i] = str[i] - '0';
//     while (n--)
//         for (int i = 0; i < len; i++)
//             if (a[i] > a[i + 1]) {
//                 for (int j = i; j < len; j++)
//                     a[j] = a[j + 1];
//                 len--;
//                 break;
//             }
//     int i = 0, l = 0;
//     while (a[i] == 0 && l < len - 1) {
//         l++;
//         i++;
//     }
//     for (int i = l; i < len; i++)
//         cout << a[i];
// }