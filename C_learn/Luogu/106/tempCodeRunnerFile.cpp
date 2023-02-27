#include<iostream>
using namespace std;
string str[110];
int main(){
    int n , m;
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        cin >> str[i];
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(str[i][j] == '?'){
                int num = 0;
                if(j != 0){
                    if(str[i - 1][j - 1] == '*') num++;
                    if(str[i][j - 1] == '*') num++;
                    if(str[i + 1][j - 1] == '*') num++;
                }
                if(str[i - 1][j] == '*') num++;
                if(str[i - 1][j + 1] == '*') num++;
                if(str[i][j + 1] == '*') num++;
                if(str[i + 1][j] == '*') num++;
                if(str[i + 1][j + 1] == '*') num++;
                str[i][j] = (char)(num + '0');
            }
        }
    }
    for(int i = 1 ; i <= n;i++){
        cout << str[i] << endl;
    }
}