#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n , m;
        cin >> n >> m;
        int num[100];
        for(int i = 0 ; i < m;i++){
            cin >> num[i];
        }
        sort(num,num + m);
        int sum = 0;
        int count = 0;
        for(int i = 0 ; i < m;i++){
            sum = sum + num[i];
            count++;
            if(sum > n){
                count--;
                break;
            }
        }
        cout << count << endl;
    }
    return 0;
}