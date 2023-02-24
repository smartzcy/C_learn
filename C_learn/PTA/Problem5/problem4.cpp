#include<iostream>
#include<math.h>
using namespace std;
bool is(int n){
    if(n == 1) return false;
    for(int i = 2 ; i < sqrt(n);i++){
        if(n % i == 0) return false;
    }
    return true;
}
int main(){
    int N;
    cin >> N;
    while(N--){
        int num;
        cin >> num;
        if(is(num)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}