#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    int N;
    cin >> N;
    while (N--) {
        string name;
        int a, b;
        cin >> name >> a >> b;
        if (a < 15 || a > 20 || b < 50 || b > 70) cout << name << endl;
    }
}