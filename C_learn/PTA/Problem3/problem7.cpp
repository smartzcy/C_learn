#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    int num[200] = {0};
    string ch[] = {"/*","(","[","{"};
    int k = 0;
    int nm = 0;
    while(getline(cin,str)){
        if(str == ".") break;
        for(int i = 0 ; i < str.length() && nm == 0;i++){
            if(str.substr(i,1) == "/" && str.substr(i + 1,1) == "*"){
                num[k++] = 1;
                i++;
            }else if(str.substr(i,1) == "("){
                num[k++] = 2;
            }else if(str.substr(i,1) == "["){
                num[k++] = 3;
            }else if(str.substr(i,1) == "{"){
                num[k++] = 4;
            }else if(str.substr(i,1) == "*" && str.substr(i + 1,1) == "/"){
                if(k != 0 && num[k - 1] == 1){
                    k--;
                }else {
                    for(int j = k;j >= 0 ;j--){
                        if(num[j] == 1){
                            cout << "NO" << endl;
                            cout << ch[num[k - 1] - 1] << "-?";
                            nm = 1;
                            break;
                        }else if(k == 0) {
                            cout << "NO" << endl;
                            cout << "?-*/";
                            nm = 1;
                        }
                    }
                }
                i++;
            }else if(str.substr(i,1) == ")"){
                if(k != 0 && num[k - 1] == 2){
                    k--;
                }else {
                    for(int j = k;j >= 0 ;j--){
                        if(num[j] == 2){
                            cout << "NO" << endl;
                            cout << ch[num[k - 1] - 1] << "-?";
                            nm = 1;
                            break;
                        }else if(k == 0) {
                            cout << "NO" << endl;
                            cout << "?-)";
                            nm = 1;
                        }
                    }
                }
            }else if(str.substr(i,1) == "]"){
                if(k != 0 && num[k - 1] == 3){
                    k--;
                }else {
                    for(int j = k;j >= 0 ;j--){
                        if(num[j] == 3){
                            cout << "NO" << endl;
                            cout << ch[num[k - 1] - 1] << "-?";
                            nm = 1;
                            break;
                        }else if(k == 0) {
                            cout << "NO" << endl;
                            cout << "?-]";
                            nm = 1;
                        }
                    }
                }
            }else if(str.substr(i,1) == "}"){
                if(k != 0 && num[k - 1] == 4){
                    k--;
                }else {
                    for(int j = k;j >= 0 ;j--){
                        if(num[j] == 4){
                            cout << "NO" << endl;
                            cout << ch[num[k - 1] - 1] << "-?";
                            nm = 1;
                            break;
                        }else if(k == 0) {
                            cout << "NO" << endl;
                            cout << "?-}";
                            nm = 1;
                        }
                    }
                }
            }
        }
    }
    if(nm == 0 && k != 0) {
        cout << "NO" << endl;
        cout << ch[num[k - 1] - 1] << "-?";
    }else if(nm == 0) cout << "YES";
}