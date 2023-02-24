// #include<iostream>
// #include<set>
// using namespace std;
// set<pair<int,int> > s;
// int n , k;
// void way(int a , int b){
//     s.insert({a , b});
//     s.insert({a + 1 , b});
//     s.insert({a + 1 , b + 1});
//     if(a + 1 == n) return ;
//     way(a + 1 , b);
//     way(a + 1 , b + 1);
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n >> k;
//     for(int i = 0 ; i < k;i++){
//         int a , b;
//         cin >> a >> b;
//         way(a , b);
//         if(s.find({a , b - 1}) != s.end()){
//             s.insert({a - 1 , b - 1});
//         }else if(s.find({a , b + 1}) != s.end()){
//             s.insert({a - 1 , b});
//         }
//     }
//     cout << s.size();
// }


// #include<iostream>
// #include<algorithm>
// using namespace std;
// int main(){
//     int n , k;
//     cin >> n >> k;
//     int x = 0 , y = 0;
//     for(int i = 0 ; i < k ; i++){
//         int a , b;
//         cin >> a >> b;
//         if(x == 0){
//             x = a;
//             y = b;
//         }else{
//             int flag = 0;
//             if(y < b){
//                 if(y + (n - x) >= b - (n - a)) flag = 1;
//             }else{
//                 if(y - (n - x) <= b + (n - a)) flag = 1;
//             }
//             if(flag == 1){
//                 x -= abs(y - b);
//                 y = min(y , b);
//             }
//         }
//     }
//     int num = n - x + 1;
//     cout << (num + 1) * num / 2;
// }

#include<iostream>
using namespace std;
int num[1000001];
int main(){
    int n , k;
    cin >> n >> k;
    for(int i = 0 ; i < k;i++){
        int a , b;
        cin >> a >> b;
        for(int j = b; j <= b + (n - a);j++){
            num[j] = 1;
        }
    }
    int m = 0;
    int sum = 0;
    for(int i = 1 ; i <= n;i++){
        if(num[i] == 1){
            m++;
        }else{
            sum += (m + 1) * m / 2;
            m = 0;
        }
    }
    if(num[n] != 1) sum += (m + 1) * m / 2;
    cout << sum;
}