// #include <iostream>
// #include<algorithm>
// using namespace std;
// struct People{
//     long long l , r;
//     long long cha;
//     bool operator < (const People& a) const{
//         return cha < a.cha;
//     }
// }peo[100100];
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     long long n , ans = 0;
//     cin >> n;
//     for(int i = 1 ; i <= n ; i++){
//         cin >> peo[i].l >> peo[i].r;
//         peo[i].cha = peo[i].r - peo[i].l;
//     }
//     sort(peo + 1 , peo + n + 1);
//     for(int i = 1 ; i <= n ; i++)
//         ans += (i - 1) * peo[i].l + (n - i) * peo[i].r;
//     cout << ans << endl;
//     return 0;
// }

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
typedef long long ll;
struct node
{
    int a, b;
    ll sub;
} num[N];
ll ans;
bool cmp(node a, node b)
{
    return a.sub > b.sub;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i].a >> num[i].b;
        num[i].sub = num[i].a - num[i].b;
    }
    sort(num + 1, num + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        ans += num[i].a * (i - 1);
        ans += num[i].b * (n - i);
    }
    cout << ans;
    return 0;
}