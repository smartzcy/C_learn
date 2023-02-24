#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
const int N = 1e5;
long long n, m, t;
void solve() {
    long long n, ans = 0;
    cin >> n;
    stack<long long> st;
    cin >> t;
    st.push(t);
    for (int i = 1; i < n; i++) {
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