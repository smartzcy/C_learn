#include<iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        long long a , b , max = 0 , sum = 0;
        int n;
        cin >> n;
        for(int i = 0 ; i < n;i++){
            cin >> a >> b;
            if(a > b){
                sum += b;
                if(max < a) max = a;
            }else{
                sum += a;
                if(max < b) max = b;
            }
        }
        cout << max * 2 + sum * 2 << endl;
    }
}