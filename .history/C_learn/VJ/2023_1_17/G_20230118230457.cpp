#include <iostream>
#include <algorithm>
using namespace std;
int n, min1, min2;
const int N = 1e5;
struct node {
    int v, t2, t3;
} a[N];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i].v;
    for (int i = 0; i < n; i++) {
        if (a[i].v % 2 == 0 || a[i].v % 3 == 0) {
            while (a[i].v % 2 == 0) {
                a[i].v /= 2;
                a[i].t2++;
            }
            while (a[i].v % 3 == 0) {
                a[i].v /= 3;
                a[i].t3++;
            }
            min1 = min(min1, a[i].t2);
            min2 = min(min2, a[i].t3);
        }
    }
    for (int i = 0; i < n; i++) {
    }
}