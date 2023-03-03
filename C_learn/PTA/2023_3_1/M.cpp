#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int N = 1e5;
int n, m;
void jin() {
    for (int i = 0; i < n; i++) cout << "  ";
}
int main() {
    string str;
    int flag = 0, flag1 = 0;
    getline(cin, str);
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '0' && flag) {
        } else {
            cout << str[i];
            flag = 0;
        }
        if (str[i] == '{') {
            n++;
            cout << endl;
            flag = 1;
            jin();
        } else if (str[i] == '}') {
            n--;
            cout << endl;
            flag = 1;
            jin();
        } else if (str[i] == 'i' && str[i + 1] == 'f') {
        }
    }
}