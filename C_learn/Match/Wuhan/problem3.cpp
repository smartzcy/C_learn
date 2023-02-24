#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    string a , b;
    cin >> a >> b;
    int flag = 0;
    for(int i = 0; i < n; i++){
        if(b[i] == 'A' || b[i] == 'C' || b[i] == 'M'){
            flag = 1;
            cout << a[i];
        }else{
            if(flag == 1){
                flag = 0;
                cout << " ";
            }
        }
    }
}