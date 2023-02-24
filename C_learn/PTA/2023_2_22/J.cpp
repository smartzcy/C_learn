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
    int i = 1, j = k - 1;
    while (i <= j) {
        if (j == i)
            printf("%05d %d %d\n", Num[j], seg[Num[j]].date, -1);
        else
            printf("%05d %d %05d\n", Num[j], seg[Num[j]].date, Num[i]);
        j--;
        if (j == i - 1) break;
        if (j == i)
            printf("%05d %d %d\n", Num[i], seg[Num[i]].date, -1);
        else
            printf("%05d %d %05d\n", Num[i], seg[Num[i]].date, Num[j]);
        i++;
    }
}