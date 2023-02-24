#include<iostream>
using namespace std;
int way(int n){
    int count = 1;
    while (n != 1){
        if(n % 2 == 1) n = 3 * n + 1;
        else n /= 2;
        count++;
    }
    return count;
}
int main(){
    int n , m;
    while (cin >> n >> m){
        cout << n << " " << m;
        int max = 0;
        if(n > m){
            int t = m;
            m  = n;
            n = t;
        }
        for(int i = n ; i <= m;++i)
            max = max > way(i) ? max : way(i);
        cout << " " << max << endl;
    }
    return 0;
}