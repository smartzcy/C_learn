#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    int n;
    cin >> n;
    while (n--) {
        int count = 0, sum = 0;
        int id = 1;
        string s;
        int a, b;
        int num[1005]{0};
        int sent[1005]{0};
        while (id != 0) {
            cin >> id >> s;
            scanf("%d:%d", &a, &b);
            int time = a * 60 + b;
            if (s[0] == 'S') {
                sent[id] = 1;
                num[id] = time;
            } else {
                if (sent[id] == 1) {
                    sum += time - num[id];
                    count++;
                    num[id] = 0;
                    sent[id] = 0;
                }
            }
        }
        double tt = sum * 1.0;
        if (count > 1) tt = (sum * 1.0) / count;
        printf("%d %d\n", count, (int)(tt + 0.5));
    }
}