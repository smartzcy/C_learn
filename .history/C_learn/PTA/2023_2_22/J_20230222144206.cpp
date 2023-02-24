#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int n, m;
struct node {
    int date;
    int next;
} seg[N];
int Num[N];
int main() {
    int start, N;
    cin >> start >> N;
    for (int i = 1, u, w, v; i <= N; i++) {
        cin >> u >> w >> v;
        seg[u].date = w;
        seg[u].next = v;
    }
    int now = start;
    int k = 1;
    while (now != -1) {
        Num[k++] = now;
        now = seg[now].next;
    }
    int i = 1, j = N;
    while (i < j) {
        printf("%05d %d %05d\n", Num[j], seg[Num[j]].date, seg[Num[j]].next);
        j--;
        if (j == i) break;
        printf("%05d %d %05d\n", Num[i], seg[Num[i]].date, seg[Num[i]].next);
        i++;
    }
}