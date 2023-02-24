#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n , a1 , a2 , a3 , b1 , b2 , b3;
    cin >> n >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
    int shu = min(a1 , b1 + b3) + min(a2 , b2 + b1) + min(a3 , b3 + b2);
    int win = min(b1 , a1 + a3) + min(b2 , a2 + a1) + min(b3 , a3 + a2);
    cout << n - shu << endl;
    cout << win << endl;
}