#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    while(cin >> n , n != 0){
        int num[1422];
        for(int i = 0 ; i < n ;i++){
            cin >> num[i];
        }
        sort(num,num + n);
        if(num[n - 1] >= 1322 && ((num[0] != 0 && num[0] <= 200) || num[0] == 0)){
            for(int i = 1; i < n ;i++){
                if(num[i] - num[i - 1] > 200){
                    cout << "IMPOSSIBLE" << endl;
                    break;
                }
                if(i == n - 1){
                    cout << "POSSIBLE" << endl;
                }
            }
        }else{
            cout << "IMPOSSIBLE" << endl;
        }   
    }
    return 0;
}