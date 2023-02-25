#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    cin >> n;
    int a1, a2, a3, b1, b2, b3;
    cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
    cout << max({0, a1 - b1 - b3, a2 - b2 - b1, a3 - b3 - b2}) << " ";
    cout << min(a1, b2) + min(a2, b3) + min(a3, b1);
}