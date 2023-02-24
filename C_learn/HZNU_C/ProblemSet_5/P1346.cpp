#include<iostream>
using namespace std;
long long num[31];
void ways(){
    num[0] = 1;
    num[1] = 0;
    num[2] = 3;
    for(int i = 3;i <= 30;i++){
        if(i % 2 == 1){
            num[i] = 0;
        }else {
            num[i] = num[i - 2] * 4 - num[i - 4];
        }
    }
}
int main(){
    ways();
    int n;
    while (cin >> n,n != -1){
        cout << num[n] << endl;
    }
    return 0;
}