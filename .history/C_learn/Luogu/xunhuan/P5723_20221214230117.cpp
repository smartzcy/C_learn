#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int L , j , sum = 0;
    cin >> L;
    for(int i = 2 ; i <= L;i++){
        for(j = 2 ; j <= sqrt(i);j++){
            if(i % j == 0) break;
        }
        if(j == sqrt(i)){
            cout << i << endl;
            sum++;
        }
    }
    cout << sum << endl;
    return 0;
}