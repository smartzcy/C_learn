#include<iostream>
#include<vector>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int k , n , m , num1[100] , num2[100];
        cin >> k >> n >> m;
        vector<int> vec;
        for(int i = 0 ; i < n;i++){
            cin >> num1[i];
        }
        for(int i = 0 ; i < m;i++){
            cin >> num2[i];
        }
        int i = 0 , j = 0;
        while(i < n || j < m){
            if(i < n && num1[i] == 0){
                vec.push_back(num1[i++]);
                k++;
            }else if(j < m && num2[j] == 0){
                vec.push_back(num2[j++]);
                k++;
            }else if(i < n && num1[i] <= k){
                vec.push_back(num1[i++]);
            }else if(j < m && num2[j] <= k){
                vec.push_back(num2[j++]);
            }else if((i < n && num1[i] > k) || (j < m && num2[j] > k)) {
                cout << "-1" << endl;
                break;
            }
        }
        if(i == n && j == m) {
            for(auto i : vec) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}