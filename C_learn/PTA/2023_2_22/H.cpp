#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e3 + 10;
int n, m;
int num1[N][N], num2[N][N];
int main() {
    int r1, c1, r2, c2;
    cin >> r1 >> c1;
    for (int i = 1; i <= r1; i++) {
        for (int j = 1; j <= c1; j++) {
            cin >> num1[i][j];
        }
    }
    cin >> r2 >> c2;
    for (int i = 1; i <= r2; i++) {
        for (int j = 1; j <= c2; j++) {
            cin >> num2[i][j];
        }
    }
    if (c1 != r2)
        cout << "Error: " << c1 << " != " << r2 << endl;
    else {
        cout << r1 << " " << c2 << endl;
        for (int i = 1; i <= r1; i++) {
            for (int j = 1; j <= c2; j++) {
                int sum = 0;
                for (int k = 1; k <= r2; k++) {
                    sum += num1[i][k] * num2[k][j];
                }
                cout << sum << " \n"[j == c2];
            }
        }
    }
}