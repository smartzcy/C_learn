#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int N = 2e5 + 10;
long long num[N];
int n, m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    long long sum = 0;
    map<long long, int> map1;
    map1[0] = 1;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        sum += num[i];
        if (map1.find(sum) != map1.end()) {
            cnt++;
            map1.clear();
            sum = num[i];
            map1[0] = i;
        }
        map1[sum] = i;
    }
    cout << cnt << endl;
}