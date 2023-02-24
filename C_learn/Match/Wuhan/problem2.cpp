#include<iostream>
#include<vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> vec;
    vec.reserve(200000);
    int T;
    cin >> T;
    int A;
    for(int i = 0; i < T; i++){
        string str;
        cin >> str;
        if(str != "null"){
            int x;
            cin >> x;
            int num = 0;
            for(int j = 0 ; j < str.length() ; j++){
                if(str[j] == ':')break;
                num = num * 10 + (str[j] - '0');
            }
            if(i == 0){
                A = x;
            }else{
                vec.emplace_back(vector<int>{num,x});
                if(num >= 6 && num < 12){
                    A = A & x;
                }else if(num >= 12 && num < 18){
                    A = A | x;
                }else if(num >= 18 && num < 24){
                    A = A ^ x;
                }
            }
        }else{
            for(auto j : vec){
                if(j[0] >= 6 && j[0] < 12){
                    A = A & j[1];
                }else if(j[0] >= 12 && j[0] < 18){
                    A = A | j[1];
                }else if(j[0] >= 18 && j[0] < 24){
                    A = A ^ j[1];
                }
            }
        }
        cout << A << endl;
    }
}

// #include<iostream>
// using namespace std;
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int T;
//     cin >> T;
//     int A;
//     int flag = 0;
//     int X = 0;
//     for(int i = 0; i < T; i++){
//         string str;
//         cin >> str;
//         if(str != "null"){
//             int x;
//             cin >> x;
//             int num = 0;
//             for(int j = 0 ; j < str.length() ; j++){
//                 if(str[j] == ':')break;
//                 num = num * 10 + (str[j] - '0');
//             }
//             if(i == 0){
//                 A = x;
//             }else{
//                 if(num >= 6 && num < 12){
//                     if(flag == 0){
//                         flag = 1;
//                         X = x;
//                     }else{
//                         X = X & x;
//                     }
//                     A = A & x;
//                 }else if(num >= 12 && num < 18){
//                     if(flag == 0){
//                         flag = 2;
//                         X = x;
//                     }else{
//                         X = X | x;
//                     }
//                     A = A | x;
//                 }else if(num >= 18 && num < 24){
//                     if(flag == 0){
//                         flag = 3;
//                         X = x;
//                     }else{
//                         X = X ^ x;
//                     }
//                     A = A ^ x;
//                 }
//             }
//         }else{
//             A = A | X;
//         }
//         cout << A << endl;
//     }
// }