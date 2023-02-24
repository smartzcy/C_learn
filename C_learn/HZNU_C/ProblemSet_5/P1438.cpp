#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    while(cin >> n , n != 0){
        int num[100001];
        for(int i = 0 ; i < n ;i++){
            cin >> num[i];
        }
        sort(num , num + n);
        cout << 2 * (num[n - 1] - num[0]) << endl;
    }
    return 0;
}