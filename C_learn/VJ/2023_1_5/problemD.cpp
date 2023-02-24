#include<iostream>
#include<queue>
using namespace std;
int main(){
    long long n , l , num;
    cin >> n >> l;
    priority_queue<long long , vector<long long> , greater<long long> >que;
    for(int i = 0; i < n; i++){
        cin >> num;
        l -= num;
        que.push(num);
    }
    if(l > 0) que.push(l);
    long long ans = 0;
    while(que.size() != 1){
        long long a1 , a2;
        a1 = que.top();
        que.pop();
        a2 = que.top();
        que.pop();
        ans += a1 + a2;
        que.push(a1 + a2);
    }
    cout << ans << endl;
}