#include<iostream>
#include<queue>
using namespace std;
int main(){
    long long n , sum = 0 , k = 0;
    cin >> n;
    priority_queue<long long> que;
    for(int i = 0; i < n; i++){
        long long num;
        cin >> num;
        sum += num;
        if(num < 0) que.push(-num);
        while(sum < 0 && !que.empty()){
            sum += que.top();
            que.pop();
            k++;
        }
    }
    cout << n - k;
}