#include <iostream>
using namespace std;
string s;
int main() {
    int len;
    int k = 1;
    while (cin >> len, len != 0) {
        cout << "Test case #" << k++ << endl;
        cin >> s;
    }
}