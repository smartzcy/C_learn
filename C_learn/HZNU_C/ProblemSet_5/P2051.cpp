#include<iostream>
using namespace std;
int num[100001];
void ways(){
    num[0] = 0;
    num[1] = 0;
    num[2] = 2;
    for(int i = 3 ; i <= 100000;i++){
        if(i % 2 == 0) num[i] = num[i / 2] * 2 + i;
        else num[i] = num[i / 2] + num[i / 2 + 1] + i;
    }
}
int main(){
    int T;
    ways();
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        cout << num[n] << endl;
    }
    return 0;
}