#include<iostream>
using namespace std;
int main(){
    int n , x , y , num[100] , min_x = 0;
    cin >> n >> x >> y;
    for(int i = 0; i < n; i++){
        cin >> num[i];
        if(num[i] <= x) min_x++;
    }
    if(x <= y){
        cout << (min_x + 1) / 2;
    }
}