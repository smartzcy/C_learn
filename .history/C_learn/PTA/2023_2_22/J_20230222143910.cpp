#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int n, m;
struct node {
    int date;
    int next;
} seg[N];
int main() {
    int start, N;
    cin >> start >> N;
    for (int i = 1, u, w, v; i <= N; i++) {
        cin >> u >> w >> v;
        seg[u].date = w;
        seg[u].next = v;
    }
    int now = start;
    while (now != -1) {
        now = seg[now].next;
    }
}