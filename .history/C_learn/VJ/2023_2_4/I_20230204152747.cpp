#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
const int N = 1e5;
int n, m, t, tot;
vector<int> vec[N];
int main() {
    cin >> t;
    stack<pair<int, int>> s;
    while (cin >> n >> m) {
        if (m == 0) {
            s.push({++tot, 2});
        }
    }
}