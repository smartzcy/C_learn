#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int main(){
    queue<int> que;
    int N , K;
    cin >> N >> K;
    int sum = 0;
    int max1 = 0;
    for(int i = 0 ; i < K ; i++){
        int a , b;
        cin >> a >> b;
        que.push(a * b);
        sum += a * b;
    }
    max1 = sum;
    for(int i = K ; i < N ; i++){
        int a , b;
        cin >> a >> b;
        sum += a * b;
        sum -= que.front();
        max1 = max(max1 , sum);
        que.pop();
        que.push(a * b);
    }
    cout << max1;
}