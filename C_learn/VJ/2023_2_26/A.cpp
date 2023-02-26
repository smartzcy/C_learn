#include <iostream>
#include <vector>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s1;
        char s2;
        cin >> s1 >> s2;
        vector<int> vec;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == s2) vec.push_back(i);
        }
        int flag = 0;
        for (auto i : vec) {
            if (i % 2 == 0 && ((s1.size() - 1 - i) % 2 == 0)) {
                flag = 1;
                break;
            }
        }
        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}