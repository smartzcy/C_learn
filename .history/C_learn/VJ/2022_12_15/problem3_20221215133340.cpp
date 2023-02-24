#include<iostream>
using namespace std;
int main(){
    int q;
    cin >> q;
    for(int i = 0 ; i < q ; i++){
        long long n , m , sum = 0;
        cin >> n >> m;
        int num[10] = {0};
        long long nm = m % 10;
        int k = 0;
        while(num[nm] != 1){
            num[nm] = 1;
            nm = (nm + m % 10) % 10;
            k++;
        }
        cout << k;
        for(int i = 0 ; i < 10;i++){
            sum += num[i] * i;
        }
        sum *= (n / m / k);
        nm = n / m % k;
        while(nm--){
            sum += m % 10;
            m += m;
        }
        cout << sum << endl;
    }
}
//3 6 9 2 5 8 1 4 7 0 3