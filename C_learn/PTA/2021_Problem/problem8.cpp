#include<iostream>
using namespace std;
long long ways(long long x ,long long y){
    if(x == 0 || y == 0) return 0;
    else return x > y ? y * 4 + ways(x - y , y) : x * 4 + ways(x , y - x);
}
int main(){
    long long x , y;
    cin >> x >> y;
    cout << ways(x , y);
}