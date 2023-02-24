#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;
    int max1 = 0;
    cin >> n;
    bool num[2000000] = {0};
    for(int i = 0 ; i < n;i++){
        double a;
        int t;
        cin >> a >> t;
        max1 = max(int(a * t) , max1);
        for(int j = 1 ; j <= t ; j++){
            num[int(j * a)] = abs(num[int(j * a)] - 1);
        }
    }
    for(int i = 1 ; i <= max1 ;i++){
        if(num[i]) {
            cout << i;
            break;
        }
    }
}