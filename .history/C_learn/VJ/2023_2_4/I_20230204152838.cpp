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
    s.push({0, 1});
    while (cin >> n >> m) {
        if (m == 0) {
            pair<int, int> p = s.top();
            if (p.second == 0) s.pop();

            s.push({++tot, 2});
        }
    }
}