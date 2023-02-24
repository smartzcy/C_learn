#include<iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        char str[51][51];
        int n , m;
        cin >> n >> m;
        for(int i = 0 ; i < n;i++){
            cin >> str[i];
        }
        for(int i = n - 2 ; i >= 0 ; i--){
            for(int j = 0 ; j < m ; j++){
                if(str[i][j] == '*'){
                    int num = i;
                    for(int k = i + 1 ; k < n;k++){
                        if(str[k][j] == '.'){
                            num = k;
                        }else if(str[k][j] == 'o' || str[k][j] == '*'){
                            num = k - 1;
                            break;
                        }
                    }
                    str[i][j] = '.';
                    str[num][j] = '*';
                }
            }
        }
        for(int i = 0 ; i < n; i++){
            cout << str[i] << endl;
        }
    }
}