#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int num[N], p[N], mod = 133331;
int get(int l, int r) {
    return num[r] - num[l] * p[r - l];
}
int getr(int l, int r) {
    return num[r] - num[l] * p[l - r];
}
bool check(int x, int i) {
    return get(i - x, i) == get(i + 1 + x, i + 1);
}
int bs1(int l, int r, int i) {
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid, i))
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}
int main() {
    cin >> n;
    string str;
    cin >> str;
    str = " " + str;
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        num[i] = num[i - 1] * mod + str[i];
    }
}