// #include<iostream>
// using namespace std;
// int main(){
//     int T;
//     cin >> T;
//     while(T--){
//         long long num[100000];
//         long long n , m , k , nm;
//         cin >> n >> m >> k;
//         nm = k;
//         for(int i = 0 ; i < k;i++){
//             cin >> num[i];
//         }
//         int num1 = 0 , flag = 0;
//         for(int i = 0 ; i < k;i++){
//             if(num[i] == nm){
//                 if(num1 > n + m - 1) flag = 1;
//                 nm--;
//             }else{
//                 num1++;
//             }
//         }
//         if(flag == 0) cout << "YA" << endl;
//         else cout << "TIDAK" << endl;
//     }
// }
#include<iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        long long num;
        long long n , m , k , nm;
        cin >> n >> m >> k;
        nm = k;
        int num1 = 0 , flag = 0;
        for(int i = 0 ; i < k;i++){
            cin >> num;
            if(num == nm){
                if(num1 > n * m - (n + m - 1)) flag = 1;
                nm--;
            }else{
                num1++;
            }
        }
        if(flag == 0) cout << "YA" << endl;
        else cout << "TIDAK" << endl;
    }
}