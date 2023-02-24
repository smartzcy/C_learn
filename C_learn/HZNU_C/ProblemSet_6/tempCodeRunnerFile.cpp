#include<iostream>
using namespace std;
int main(){
    int n , m;
    while(cin >> n >> m){
        int count = 0;
        for(int i = 1 ; i <= n;i++){
            int k = i % 5;
            k = 5 - k;
            count += ((m - k) / 5 + 1);
        }
        cout << count << endl;
    }
}   