#include<iostream>
#include<queue>
using namespace std;
int main(){
    long long n , l;
    cin >> n >> l;
    priority_queue<long long , vector<long long> , greater<long long> >que;
    for(int i = 0; i < n; i++){
        long long num;
        cin >> num;
        que.push(num);
    }
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