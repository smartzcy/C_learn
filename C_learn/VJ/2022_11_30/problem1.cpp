#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int num;
    int max1 = 0;
    int min1 = 100000;
    while(cin >> num){
        if(num % 2 == 1){
            max1 = max(max1 , num);
        }else{
            min1 = min(min1 , num);
        }
    }
    if(max1 != 0 && min1 != 100000) cout << max1 - min1 << endl;
    else cout << "None";
}