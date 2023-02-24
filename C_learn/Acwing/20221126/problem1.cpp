#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    if((int)sqrt(2 * n) * (int)(sqrt(2 * n) + 1) == 2 * n) cout << "YES";
    else cout << "NO";
}