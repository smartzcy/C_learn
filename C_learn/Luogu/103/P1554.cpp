#include <iostream>
using namespace std;
int main(){
    int num[10] = {0};
    int n , m;
    cin >> n >> m;
    for(int i = n ; i <= m;i++){
        int k = i;
        while(k != 0){
            num[k % 10]++;
            k /= 10;
        }
    }
    for(int i = 0 ; i < 10;i++){
        cout << num[i] << " ";
    }
}