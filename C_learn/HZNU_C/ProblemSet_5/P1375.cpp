#include<iostream>
#include<math.h>
using namespace std;
int ways(int n){
    for(int i = 2; i * i <= n;i++){
        if(n % i == 0) return 0;
    }
    return 1;
}
int main(){
    long long p , a;
    while (cin >> p >> a , a != 0 && p != 0){
        if(ways(p)) cout << "no" << endl;
        else {
            long long n = p;
            long long r = 0;
            long long s = 1;
            while(p != 0){
                if(n & 1){
                    s = s * r % n;
                }
                r = r * r % n;
                p >>= 1;
            }
            if(s == a){
                cout << "yes" << endl;
            }else{
                cout << "no" << endl;
            }
        }
    }
    return 0;
}
// #include<iostream>
// #include<cmath>
// using namespace std;
// bool is_prime(int n){
// 	for(int i = 2 ;i * i <= n ;i++)
// 		if(n % i ==0 ) return false;
// 	return true;
// }
// int main(){
// 	long long p,a;
// 	while(cin >> p >> a , p != 0 && a != 0){
// 		if(is_prime(p)){
// 			cout << "no" << endl;
// 		}else{
//             long long n = p;
//             long long tmp = a;
//             long long res = 1;
//             while(p){
//                 if(p & 1) res = res * tmp % n;
//                 tmp = tmp * tmp % n;
//                 p >>= 1;
//             }
// 			if(res == a) cout << "yes" << endl;
// 			else cout << "no" << endl;
// 		}
// 	}
//     return 0;
// }