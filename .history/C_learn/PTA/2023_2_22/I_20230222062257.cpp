#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    int T;
    cin >> T;
    while (T--) {
        string name;
        int k;
        cin >> name >> k;
        map<int, int> map1;
        for (int i = 1, num; i <= k; i++) {
            cin >> num;
            map1[num] = 1;
        }
    }
}