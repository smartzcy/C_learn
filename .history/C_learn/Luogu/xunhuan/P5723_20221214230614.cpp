#include <iostream>
#include <math.h>
using namespace std;
bool way(int n){
    for(int i = 2 ; i <= sqrt(n);i++){
        if(n % i == 0) return false;
    }
    return true;
}
int main(){
    int L , sum = 0 , num = 0;
    cin >> L;
    for(int i = 2 ; i <= L;i++){
        if(way(i)){
            num += i;
            if(num >= L) break;
            sum++;
            cout << i << endl;
        }
    }
    cout << sum << endl;
    return 0;
}