#include<iostream>
using namespace std;
int main(){
    char str[] = {"BCJ"};
    int N;
    cin >> N;
    int num[3] = {0};
    int m1[3] = {0};
    int m2[3] = {0};
    for(int i = 0 ; i < N;i++){
        string x , y;
        cin >> x >> y;
        if(x == "C"){
            if(y == "C") {
                num[1]++;
            }else if(y == "J"){
                num[0]++;
                m1[1]++;
            }else{
                num[2]++;
                m2[0]++;
            }
        }else if(x == "J"){
            if(y == "C"){
                num[2]++;
                m2[1]++;
            }else if(y == "J"){
                num[1]++;
            }else {
                num[0]++;
                m1[2]++;
            }
        }else {
            if(y == "C"){
                num[0]++;
                m1[0]++;
            }else if(y == "J"){
                num[2]++;
                m2[2]++;
            }else{
                num[1]++;
            }
        }
    }
    cout << num[0] << " " << num[1] << " " << num[2] << endl;
    cout << num[2] << " " << num[1] << " " << num[0] << endl;
    int n = 0 , m = 0;
    for(int i = 1 ; i < 3;i++){
        if(m1[n] < m1[i]) n = i;
        if(m2[m] < m2[i]) m = i;
    }
    cout << str[n] << " " << str[m];
}