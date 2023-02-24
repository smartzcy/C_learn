#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int m = 2 , k = 1 , flag = 0;
    cout << n << "=";
    while(n != 1){
        k = 1;
        while(n % (int)pow(m,k) == 0){
            k++;
        }
        if(k != 1){
            if(flag == 0){
                if(k == 2) cout << m;
                else cout << m << "^" << k - 1;
                flag = 1;
            }else{
                if(k == 2) cout << "*" << m;
                else cout << "*" << m << "^" << k - 1;
            }
        }
        n = n / (int)(pow(m,k - 1));
        m++;
    }
    if(m == 2) cout << "1";
}