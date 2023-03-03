#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, g, k, sum;
pair<int, string> seg[N];
bool cmp(pair<int, string> &a, pair<int, string> &b) {
    if (a.first == b.first)
        return a.second < b.second;
    else
        return a.first > b.first;
}
int main() {
    cin >> n >> g >> k;
    for (int i = 1; i <= n; i++) {
        string email;
        int num;
        cin >> email >> num;
        if (num >= 60 && num < g)
            sum += 20;
        else if (num >= g && num <= 100)
            sum += 50;
        seg[i] = {num, email};
    }
    cout << sum << endl;
    sort(seg + 1, seg + n + 1, cmp);
    int m = 1;
    for (int i = 1; i <= n; i++) {
        if (i <= k) {
            if (seg[i].first == seg[i - 1].first) {
                cout << m << " " << seg[i].second << " " << seg[i].first << endl;
            } else {
                cout << i << " " << seg[i].second << " " << seg[i].first << endl;
                m = i;
            }
        } else {
            if (seg[i].first == seg[i - 1].first) {
                cout << m << " " << seg[i].second << " " << seg[i].first << endl;
            } else
                break;
        }
    }
}