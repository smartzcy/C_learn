#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int N = 1e5;
struct node {
    string name;
    int num;
    double ping;
} Node[200];
int main() {
    int T;
    cin >> T;
    for (int m = 1; m <= T; m++) {
        string name;
        int k;
        cin >> name >> k;
        map<int, int> map1;
        for (int i = 1, num; i <= k; i++) {
            cin >> num;
            map1[num] = 1;
        }
        Node[m].name = name;
        Node[m].num = map1.size();
        Node[N].ping = (double)k / map1.size();
        map1.clear();
    }
}