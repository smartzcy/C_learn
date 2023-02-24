#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n , m;
    cin >> n >> m;
    if(n == m) cout << n;
    else if(n % 2 == 0 || m % 2 == 0) cout << 2;
    else {
        int min1 = min(n , m);
        int x = n + m - min1;
        if((x + x / min1) % min1 == 0) cout << min1;
        else cout << 3;
    }
}