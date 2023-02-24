#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
void solve() {
    int n;
    cin >> n;
    stack<int> st; // 栈里面存放的是下标
    vector<int> a(n + 1), f(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        while (!st.empty() && a[st.top()] >= a[i]) {
            // 不同题目的符号不同，注意分辨
            st.pop();
        }
        f[i] = (st.size() == 0 ? 0 :
                                 st.top());
        // f[i] = (st.size() == 0 ? n + 1 :
st.top());
st.push(i); // 注意栈里面放进去的是下标
    }
    for (int i = 1; i <= n; ++i) {
cout << f[i] << " \n"[i == n];
    }
}

int main() {
}