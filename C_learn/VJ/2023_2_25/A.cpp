#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        if (a <= 2)
            cout << "1" << endl;
        else
            cout << (a - 3) / b + 2 << endl;
    }
}