#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m, ans = 0;
int num[8] = {1, 6, 28, 88, 198, 328, 648};
int num1[8] = {10, 60, 280, 880, 1980, 3280, 6480};
int num2[8] = {8, 18, 28, 58, 128, 198, 328};
int main() {
    cin >> n;
    for (int i = 6; i >= 0; i--) {
        if (n >= num[i]) {
            n -= num[i];
            ans += num1[i] + num2[i];
        }
    }
    for (int i = 6; i >= 0; i--) {
        while (n >= num[i]) {
            n -= num[i];
            ans += num1[i];
        }
    }
    cout << ans << endl;
}