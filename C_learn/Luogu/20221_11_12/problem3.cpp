#include<iostream>
using namespace std;
int way(int a , int b){
    if(a == b || b == 0) return 1;
    return (way(a - 1 , b) + way(a - 1 , b - 1)) % 998244353;
}
int main(){
    int n;
    cin >> n;
    int l1 = 0 , l2 = 0;
    for(int i = 0 ; i < n;i++){
        int num;
        cin >> num;
        if(num == -1) l2++;
        if(num == 1) l1++;
    }
    if(l1 > l2){
        int num = l1 - l2;
        l1 = l1 - num + 1;
        cout << l1 - 1;
    }else if(l1 == l2){
        if(l1 == 2) cout << "3";
        else cout << "2";
    }else{
        cout << way(l2 + 1 , l1);
    }
}