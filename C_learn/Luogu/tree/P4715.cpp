#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int max1 = INT_MIN , max2 = INT_MIN;
    int k1 = 0 , k2 = 0;
    int k = pow(2 , n);
    for(int i = 1 ; i <= k ;i++){
        int num;
        cin >> num;
        if(i <= k / 2){
            if(num > max1){
                max1 = num;
                k1 = i;
            }
        }else{
            if(num > max2){
                max2 = num;
                k2 = i;
            }
        }
    }
    if(max1 > max2){
        cout << k2;
    }else cout << k1;
}