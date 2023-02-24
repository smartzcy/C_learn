#include<iostream>
using namespace std;
int main(){
    int N;
    cin >> N;
    while(N--){
        int n;
        cin >> n;
        string str;
        cin >> str;
        int cot1 = 0 , cot2 = 0;
        for(int i = 0 ; i < str.length();i++){
            if(str[i] == 'Q') cot1++;
            else if(str[i] == 'A') cot2++;
        }
        if(cot1 <= cot2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}