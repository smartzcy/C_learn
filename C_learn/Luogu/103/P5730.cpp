#include<iostream>
using namespace std;
int main(){
    string str1[5][10] = {{"XXX","..X","XXX","XXX","X.X","XXX","XXX","XXX","XXX","XXX"},{"X.X","..X","..X","..X","X.X","X..","X..","..X","X.X","X.X"},{"X.X","..X","XXX","XXX","XXX","XXX","XXX","..X","XXX","XXX"},{"X.X","..X","X..","..X","..X","..X","X.X","..X","X.X","..X"},{"XXX","..X","XXX","XXX","..X","XXX","XXX","..X","XXX","XXX"}};
    int n;
    cin >> n;
    string str;
    cin >> str;
    for(int i = 0 ; i < 5;i++){
        for(int j = 0 ; j < n;j++){
            cout << str1[i][str[j] - '0'];
            if(j != n - 1) cout << ".";
        }
        cout << endl;
    }
}