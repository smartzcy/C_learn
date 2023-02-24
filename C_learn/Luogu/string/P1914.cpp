#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    string str;
    cin >> str;
    for(auto i : str){
        cout << char((i - 'a' + n) % 26 + 'a');
    }
}