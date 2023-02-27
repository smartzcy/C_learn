#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n , i = 2;
    cin >> n;
    while(i <= sqrt(n)){
        if(n % i++ == 0) break;
    }
    cout << n / (i - 1);
    return 0;
}