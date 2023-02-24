#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
const int N = 1e5;
int n, m, t;
void solve() {
    int n, ans = 0;
    cin >> n;
    stack<int> st;
    cin >> t;
    st.push(t);
    for (int i = i; i < n; i++) {
        cin >> t;
        while (!st.empty() && st.top() <= t) {
            st.pop();
        }
        ans += st.size();
        st.push(t);
    }
    cout << ans << endl;
}
int main() {
    solve();
}