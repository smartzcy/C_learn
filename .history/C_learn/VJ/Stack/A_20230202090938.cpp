#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
const int N = 1e5;
int n, m;
void solve() {
    int n, ans = 0;
    cin >> n;
    stack<int> st;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n; i >= 1; i--) {
        while (!st.empty() && a[st.top()] >= a[i]) {
            st.pop();
        }
        ans += st.size();
        st.push(i);
    }
    cout << ans << endl;
}
int main() {
    solve();
}