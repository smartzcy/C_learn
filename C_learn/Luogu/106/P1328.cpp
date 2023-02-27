#include<iostream>
using namespace std;
int vs[5][5] = {{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}};
int main(){
    int num1[210] , num2[210];
    int N , N1 , N2;
    cin >> N >> N1 >> N2;
    for(int i = 0 ; i < N1;i++){
        cin >> num1[i];
    }
    for(int i = 0 ; i < N2;i++){
        cin >> num2[i];
    }
    int x = 0 , y = 0;
    for(int i = 0 ; i < N;i++){
        x += vs[num1[i % N1]][num2[i % N2]];
        y += vs[num2[i % N2]][num1[i % N1]];
    }
    cout << x << " " << y << endl;
}