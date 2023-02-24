#include <iostream>
using namespace std;
int main(){
    int n , sum[201];
    cin >> n;
    for(int i = 0 ; i < n;i++){
        int num;
        cin >> num;
        sum[i] = num % 200;
    }
    
    return 0;
}