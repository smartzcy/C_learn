#include<iostream>
using namespace std;
int main(){
    int num;
    int n;
    cin >> n;
    while(n--){
        cin >> num;
        if(num <= 1399) cout << "Division 4" << endl;
        else if(num <= 1599) cout << "Division 3" << endl;
        else if(num <= 1899) cout << "Division 2" << endl;
        else cout << "Division 1" << endl;
    }
}