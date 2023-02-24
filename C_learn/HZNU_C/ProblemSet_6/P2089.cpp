#include<iostream>
#include<map>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int num[20][20];
        map<int,int> map;
        int n;
        cin >> n;
        for(int i = 0 ; i < n;i++){
            for(int j = 0 ; j < n;j++){
                cin >> num[i][j];
                if(map.find(num[i][j]) != map.end()){
                    num[i][j] = 1030;
                }else{
                    map.insert(pair<int,int>(num[i][j],1));
                }
            }
        }
        for(int i = 0 ;i < n;i++){
            for(int j = 0;j < n;j++){
                if(num[i][j] == 1030){
                    cout << "X";
                }else {
                    cout << num[i][j];
                }
                if(j != n - 1) cout << " ";
            }
            cout << endl;
        }
        map.clear();
        cout << endl;
    }
    return 0;
}