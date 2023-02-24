#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n , a1 , a2 , a3 , b1 , b2 , b3;
    cin >> n >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
    int shu = min(a1 , b1 + b3) + min(a2 , b2 + b1) + min(a3 , b3 + b2);
    cout << n - shu << endl;
}