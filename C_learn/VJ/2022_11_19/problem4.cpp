// #include<iostream>
// using namespace std;
// int main(){
//     int T;
//     cin >> T;
//     while(T--){
//         int n;
//         cin >> n;
//         string str;
//         cin >> str;
//         if(str.find("B") == string::npos && str.find("R") == string::npos){
//             cout << "YES" << endl;
//             continue;
//         }
//         int a = 0 , b = 0;
//         for(int i = 0 ; i < n;i++){
//             if(str[i] == 'W'){
//                 if(a == 0 || b == 0 && i != 0){
//                     cout << "NO" << endl;
//                     break;
//                 }
//                 if(i == n - 1){
//                     cout << "YES" << endl;
//                     break;
//                 }
//                 a = 0;
//                 b = 0;
//             }else if(str[i] == 'R') a++;
//             else if(str[i] == 'B') b++;
//             if(i == n - 1){
//                 if(a == 0 || b == 0){
//                     cout << "NO" << endl;
//                 }else{
//                     cout << "YES" << endl;
//                 }
//             }
//         }
//     }
// }


#include<iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        string str;
        cin >> str;
        int flag = 0;
        int a = 0 , b = -1;
        for(int i = 0 ; i < n;i++){
            if(str[i] == 'W'){
                if(abs(a) == i - b - 1 && i != 0 && b != i - 1) flag = 1;
                b = i;
                a = 0;
            }else if(str[i] == 'R') a++;
            else if(str[i] == 'B') a--;
        }
        if(n - 1 - b == abs(a) && n - 1 != b){
            flag = 1;
        }
        if(flag == 1) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}