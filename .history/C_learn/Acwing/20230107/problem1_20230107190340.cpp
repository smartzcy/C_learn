#include<iostream>
using namespace std;
int main(){
    int n;
    long long sum[2];
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int t , x , y;
        cin >> t >> x >> y;
        sum[t - 1] += x - y;
    }
    cout << sum[0] << " " << sum[1] << endl;
    if(sum[0] < 0) cout << "DEAD" << endl;
    else cout << "LIVE" << endl;
    if(sum[1] < 0) cout << "DEAD" << endl;
    else cout << "LIVE" << endl;
}