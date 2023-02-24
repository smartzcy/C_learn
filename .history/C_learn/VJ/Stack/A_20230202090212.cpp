#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
const int N = 1e5;
int n, m;
void solve() {
    int n;
    cin >> n;
    stack<int> st;
    vector<int> a(n + 1), f(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n; i >= 1; i--) {
        while (!st.empty() && a[st.top()] >= a[i]) {
            st.pop();
        }
        f[i] = (st.size() == 0 ? 0 : st.top());
        st.push(i);
    }
    for (int i = 1; i <= n; i++) {
        cout << f[i] << " \n"[i == n];
    }
}
int main() {
    solve();
}