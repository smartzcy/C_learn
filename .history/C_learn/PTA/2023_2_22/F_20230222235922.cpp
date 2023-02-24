#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    int x;
    cin >> x;
    unsigned long long num = 1;
    int k = 1;
    while (true) {
        num = num % x;
        if (num == 0) break;
        num = num * 10 + 1;
        k++;
    }
    cout << num / x << " " << k << endl;
}