#include <iostream>
using namespace std;
int a[110][11000];
int fun(int a[], int m, int n) {
    int i, s = 0;
    for (i = 0; i < n; i++)
        if (i != m) s += a[i];
    return !s;
}
int main() {
    int n, i, b[110], max = -999, j, s = 0, flag = 0;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> b[i];
        b[i] *= 10;
        if (max < b[i]) max = b[i];
    }
    if (n == 1) s = -1;
    for (j = 0; j < max; j++)
        for (i = 0; i < n; i++)
            if (b[i]) {
                if (fun(b, i, n)) {
                    if ((i == 0 && a[i][j - 1] == s) || flag || n == 1)
                        a[i][j] = s += 2;
                    else if (!flag)
                        a[i][j] = ++s;
                    flag = 1;
                } else
                    a[i][j] = ++s;
                b[i]--;
            }
    for (i = 0; i < n; i++) {
        cout << "#" << i + 1 << endl;
        for (j = 0; a[i][j]; j++) {
            cout << a[i][j];
            cout << " \n"[(j + 1) % 10 == 0];
        }
    }
}
