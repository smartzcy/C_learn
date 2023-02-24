#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    if(((1 + n) * n / 2 ) % 2 == 0) cout << "0";
    else cout << "1";
    return 0;
}