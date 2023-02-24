#include<iostream>
#include<string>
using namespace std;
int main(){
    int A , B , C;
    string str1[2000];
    string str2[2000];
    string str3[2000];
    while (cin >> A >> B >> C){
        int flag[1001] = {0};
        for(int i = 1; i <= A;i++) cin >> str1[i];
        for(int i = 1; i <= B;i++) cin >> str2[i];
        for(int i = 1; i <= C;i++) cin >> str3[i];
        int cout1 = 0;
        for(int i = 1; i <= B;i++){
            for(int j = 1; j <= A;j++){
                if(str2[i].compare(str1[j]) == 0){
                    flag[i] = 1;
                    cout1++;
                    break;
                }
            }
            for(int j = 1; j <= C;j++){
                if(str2[i].compare(str3[j]) == 0){
                    flag[i] = 0;
                    cout1--;
                    break;
                }
            }
        }
        int f = 1;
        if(cout1 == 0){
            cout << "No enemy spy" << endl;
        }else{
            for(int i = 1 ; i <= B;i++){
                if(flag[i] == 1){
                    if(f == 1){
                        cout << str2[i];
                        f = 0;
                    }else cout << " " << str2[i];
                }
            }
            cout << endl;
        }
    }
    return 0;
}