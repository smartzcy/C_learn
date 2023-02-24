#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n , sum[2];
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int num;
        cin >> num;
        sum[num % 2]++;
    }
    cout << sum[0] << " " << sum[1] << endl;
    cout << min(sum[0],sum[1]) << endl;
}