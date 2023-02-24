#include<iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n , m;
        int a , b , c , d , e;
        cin >> n >> m;
        cin >> a >> b >> c >> d >> e;
        long long min = (- n + 1) * (- n + 1) * a + (- n + 1) * b + (- m  + 1) * (- m  + 1) * c + (- m + 1) * d + e;
        for(int i = - n + 2;i < n;i++){
            for(int j = - m + 2; j < m;j++){
                min = min < i * i * a + i * b + j * j * c + j * d + e ? min : i * i * a + i * b + j * j * c + j * d + e;
            }
        }
        cout << min << endl;
    }
}