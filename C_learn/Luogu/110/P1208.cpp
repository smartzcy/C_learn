#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    pair<int, int> vec[N];
    cin >> n >> m;
    for (int i = 0, p, v; i < m; i++) {
        cin >> p >> v;
        vec[i] = {p, v};
    }
    sort(vec, vec + m);
    long long sum = 0;
    for (int i = 0; i < m; i++) {
        if (n == 0) break;
        if (vec[i].second < n) {
            sum += vec[i].second * vec[i].first;
            n -= vec[i].second;
        } else {
            sum += vec[i].first * n;
            n = 0;
        }
    }
    cout << sum << endl;
}