#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e4;
int n, t;
struct node {
    int m, v;
} seg[N];
bool cmp(const node &a, const node &b) {
    return a.v * b.m > b.v * a.m;
}
int main() {
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> seg[i].m >> seg[i].v;
    }
    sort(seg, seg + n, cmp);
    double sum = 0;
    int num = t;
    for (int i = 0; i < n && num > 0; i++) {
        if (num >= seg[i].m) {
            sum += seg[i].v;
            num -= seg[i].m;
        } else {
            sum += seg[i].v * 1.0 / seg[i].m * num;
            num = 0;
        }
    }
    printf("%.2f", sum);
}