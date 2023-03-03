#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
int n, m;
vector<int> vec[N];
vector<int> ans;
int flag[N], max_deep;
void check(int fa, int deep) {
    flag[fa] = 1;
    if (max_deep < deep) {
        max_deep = deep;
        ans.clear();
        ans.push_back(fa);
    } else if (max_deep == deep)
        ans.push_back(fa);
    for (auto i : vec[fa]) {
        if (flag[i]) continue;
        check(i, deep + 1);
    }
}
int main() {
    cin >> n;
    for (int i = 1, num; i <= n; i++) {
        cin >> num;
        if (num == -1)
            m = i;
        else {
            vec[num].push_back(i);
        }
    }
    check(m, 1);
    cout << max_deep << endl;
    for (int i = 0; i < ans.size(); i++) {
        if (i != 0) cout << " ";
        cout << ans[i];
    }
}