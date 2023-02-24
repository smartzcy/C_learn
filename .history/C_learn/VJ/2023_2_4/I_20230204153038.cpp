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
            s.pop();
            if (p.second != 1) s.push({p.first, 1});
            vec[p.first].push_back(++tot);
            s.push({tot, 2});
        } else {
            pair<int, int> p = s.top();
            s.pop();
            if (p.second != 1) s.push({p.first, 1});
            vec[p.first].push_back(++tot);
        }
    }
}