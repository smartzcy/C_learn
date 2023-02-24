#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int N = 1e5;
int n, m;
int f[N];
int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}
int main() {
    int N;
    cin >> N;
    while (N--) {
        int k;
        cin >> k;
        while (k--) {
            int num;
            cin >> num;
        }
    }
}