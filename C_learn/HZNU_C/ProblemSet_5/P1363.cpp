#include<iostream>
#include<cstring>
using namespace std;
const int Max = 1000001;
int num[Max];
void ways(){
    memset(num,0,sizeof(num));
    for(int i = 5 ; i <= Max;i+=4){
        for(int j = 5 ; j <= Max ;j+=4){
            int k = i * j;
            if(k > Max) break;
            if(num[i] == 0 && num[j] == 0) num[k] = 1;
            else num[k] = -1;
        }
    }
    int count = 0;
    for(int i = 1 ; i <= Max;i++){
        if(num[i] == 1) count++;
        num[i] = count;
    }
}
int main(){
    int n;
    ways();
    while (cin >> n , n != 0){
        cout << n << " " << num[n] << endl;
    }
    return 0;
}