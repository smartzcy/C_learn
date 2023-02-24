#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e4 + 1;
int n, m;
int flag[N];
int main() {
    int N;
    cin >> N;
    int k = 0;
    int num;
    string str;
    string s;
    int sum = 0, sum1 = 0;
    while (cin >> num >> str >> s) {
        if (num == 0) {
            k++;
            for (int i = 0; i <= 1000; i++) flag[i] = 0;
            cout << sum1 << " " << sum << endl;
            sum1 = 0;
            sum = 0;
        } else {
            int time = 60 * ((s[0] - '0') * 10 + s[1] - '0') + (s[3] - '0') * 10 + s[4] - '0';
            if (str == "S") {
                flag[num] = time;
            } else if (str == "E") {
                if (flag[num] != 0) {
                    sum1++;
                    sum += time - flag[num];
                }
            }
        }
        if (k == N) break;
    }
}