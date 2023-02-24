#include<iostream>
using namespace std;
int main(){
    long long n , m;
    while (cin >> n >> m,n != 0 || m != 0){
        int count = 0;
        int x = 0;
        while (n > 0 || m > 0){
            x = (n % 10 + m % 10 + x) / 10;
            count += x;
            n /= 10;
            m /= 10;
        }
        if(count == 0) cout << "No carry operation." << endl;
        else if(count == 1) cout << count <<" carry operation." << endl;
        else cout << count << " carry operations." << endl;
    }
    return 0;
}