#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int n, m;
int main() {
    map<int, int> map1;
    cin >> n >> m;
    for (int i = 1, num; i <= n; i++) {
        cin >> num;
        map1[num]++;
    }
    long long sum = 0;
    for (auto i : map1) {
        if (map1.find(i.first + m) != map1.end()) sum += i.second * map1[i.first + m];
    }
    cout << sum << endl;
}