#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n , max1 = 0 , m = 0 , sum = 0;
    cin >> n;
    for(int i = 0 ; i < n ;i++){
        int num;
        cin >> num;
        if(m + 1 == num){
            sum++;
            m++;
        }else{
            m = num;
            max1 = max(max1 , sum);
            sum = 1;
        }
    }
    max1 = max(max1 , sum);
    cout << max1;
    return 0;
}