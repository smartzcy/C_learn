#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e5;
int n, m;
vector<char> ans;
int main() {
    cin >> n >> m;
    m--;
    while (m > 0) {
        int x = m % 26;
        m /= 26;
        ans.push_back('z' - x);
        n--;
    }
    while (n > 0) {
        ans.push_back('z');
        n--;
    }
    for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i];
}