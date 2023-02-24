#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n , flag = 0;
    cin >> n;
    vector<string> vec;
    for(int i = 0 ; i < n ; i++){
        string str;
        cin >> str;
        vec.push_back(str);
    }
    string str = vec[vec.size()-1];
    string s = str[0] + "";
    for(int i = vec.size() - 2 ; i >= 0 ; i--){
        for(int j = 0 ; j < min(vec[i].size() , str.size()) ; j++){
            if(vec[i][j] != str[j]){
                if(s.find(vec[i][j]) == string::npos){
                    s = vec[i][j] + s;
                }else{
                    if(s.find(vec[i][j]) > s.find(str[j])){
                        flag = 1;
                    }
                }
                break;
            }
        }
    }
    if(flag == 1) cout << "Impossible" << endl;
    else {
        for(int i = 0 ; i < 26;i++){
            char ch = i + 'a';
            if(s.find(ch) == string::npos){
                cout << ch;
            }else if(ch == s[0]){
                cout << s;
            }
        }
    }
}