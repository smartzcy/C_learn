#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;
const int N = 2e5 + 10;
vector<int> vec[N];
int dis[N];
int main() {
    unordered_map<string, int> map1;
    int n;
    cin >> n;
    while (n--) {
        string a, b;
        cin >> a >> b;
        if (map1[a] == 0) map1[a] = map1.size();
        if (map1[b] == 0) map1[b] = map1.size();
        // cout << map1[a] << " " << map1[b] << endl;
        vec[map1[a]].push_back(map1[b]);
    }
    for (int i = 1; i < map1.size(); i++) {
        if (dis[i] == 1) continue;
        queue<int> que;
        que.push(i);
        while (!que.empty()) {
            int x = que.front();
            cout << x << endl;
            que.pop();
            dis[x] = 1;
            for (auto j : vec[x]) {
                if (dis[j] == 1) {
                    cout << "No" << endl;
                    return 0;
                }
                que.push(j);
            }
        }
    }
    cout << "Yes" << endl;
}