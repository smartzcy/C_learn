```cpp
struct node{
    int l , r;
    friend bool operator<(const node& a , const node& b){
        if(a.r != b.r) return a.r < b.r;
        else return a.l < b.l;
    }
}q[55];
sort(q + 1 , q + 1 + n);
```

重载运算符 重载< 因为sort里面用的是小于号

内置比较函数 less<int>() 从小到大 greater<int>()从大到小

```cpp
sort(a , a + n , greater<int>());
```

模板

```cpp
#Include<bits/stdc++.h>
typedef long long ll;
const ll maxn = 5e5 + 7;
const ll maxm = 2e6 + 7;
const ll mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}
```
