#include<iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n , m , flag = 0;
        cin >> n >> m;
        string str[51];
        for(int i = 0 ; i < n ; i++){
            cin >> str[i];
        }
        for(int i = 0 ; i < n && flag == 0 ;i++){
            for(int j = 0 ; j < m ; j++){
                if(str[i][j] == '*'){
                    if(str[i][j + 1] == '*'){
                        if(str[i + 1][j] == '*'){
                            str[i][j] = '1';
                            str[i][j + 1] = '1';
                            str[i + 1][j] = '1';
                        }else if(str[i + 1][j + 1] == '*'){
                            str[i][j] = '1';
                            str[i][j + 1] = '1';
                            str[i + 1][j + 1] = '1';
                        }
                    }else if(str[i + 1][j] == '*'){
                        if(str[i + 1][j + 1] == '*'){
                            str[i][j] = '1';
                            str[i + 1][j] = '1';
                            str[i + 1][j + 1] = '1';
                        }else if(str[i + 1][j - 1] == '*'){
                            str[i][j] = '1';
                            str[i + 1][j] = '1';
                            str[i + 1][j - 1] = '1';
                        }
                    }else{
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if(flag == 1) cout << "NO" << endl;
    }
}