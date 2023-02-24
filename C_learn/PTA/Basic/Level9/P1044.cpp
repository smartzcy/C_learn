#include<iostream>
#include<string>
using namespace std;
int main(){
    int N;
    cin >> N;
    getchar();
    string s1[] = {"jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
    string s2[] = {"tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
    while(N--){
        string str;
        getline(cin,str);
        if(str[0] <= '9' && str[0] >= '0'){
            int num = 0;
            for(int i = 0 ; i < str.length() ; i++){
                num = num *10 + (str[i] - '0');
            }
            if(num == 0) cout << "tret" << endl;
            else if(num / 13 != 0){
                cout << s2[num/13 - 1];
                if(num % 13 == 0) cout << endl;
                else cout << " " << s1[num % 13 - 1] << endl;
            }else{
                cout << s1[num - 1] << endl;
            }  
        }else{
            int t1 = 0 , t2 = 0;
            string s3 = str.substr(0,3),s4;
            if(str.length() > 4) s4 = str.substr(4,3);
            for(int i = 0 ; i < 12;i++){
                if(s3 == s1[i] || s4 == s1[i]) t2 = i + 1;
                if(s3 == s2[i]) t1 = i + 1;
            }
            cout << t1 * 13 + t2 << endl;
        }
    }
}