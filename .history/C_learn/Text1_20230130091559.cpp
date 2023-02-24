#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
const int mod1 = 3145739; // 如有误差手动修改
const int mod2 = 6291469;
struct Hash {
    ll has1[N], has2[N];
    ll bas1[N], bas2[N];
    ll p1, p2;
    void init(char s[]) {
        p1 = 2333; // 如有误差手动修改
        p2 = 17;
        has1[0] = has2[0] = 0;
        bas1[0] = bas2[0] = 1;
        int len = strlen(s + 1);
        for (int i = 1; i <= len; ++i) { // 多串hash可以这块预处理
            bas1[i] = (bas1[i - 1] * p1) % mod1;
            bas2[i] = (bas2[i - 1] * p2) % mod2;
        }
        for (int i = 1; i <= len; ++i) {
            has1[i] = (has1[i - 1] * p1 + s[i]) % mod1;
            has2[i] = (has2[i - 1] * p2 + s[i]) % mod2;
        }
    }
    ll gethash1(int r, int len) { // 返回以r结尾长度len的子串has1值
        return ((has1[r] - has1[r - len] * bas1[len]) % mod1 + mod1) % mod1;
    }
    ll gethash2(int r, int len) { // 返回以r结尾长度len的子串has2值
        return ((has2[r] - has2[r - len] * bas2[len]) % mod2 + mod2) % mod2;
    }
}