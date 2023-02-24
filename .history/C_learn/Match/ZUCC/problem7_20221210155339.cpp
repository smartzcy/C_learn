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


#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n , k;
    cin >> n >> k;
    int x = 0 , y = 0;
    for(int i = 0 ; i < k ; i++){
        int a , b;
        cin >> a >> b;
        if(x == 0){
            x = a;
            y = b;
        }else{
            x -= abs(y - b);
            y = min(y , b);
        }
    }
    int num = n - x + 1;
    cout << (num + 1) * num / 2;
}