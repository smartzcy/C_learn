#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    int N;
    cin >> N;
    string str;
    while (cin >> str) {
        if (str == "End") break;
        if (n == N) {
            n = -1;
            cout << str << endl;
        } else {
            if (str == "ChuiZi")
                cout << "Bu";
            else if (str == "JianDao")
                cout << "ChuiZi" << endl;
            else if (str == "Bu")
                cout << "JianDao" << endl;
        }
        n++;
    }
}