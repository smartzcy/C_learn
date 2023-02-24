#include<iostream>
#include<map>
using namespace std;
int main(){
    int N;
    cin >> N;
    map<int,int>Map;
    for(int i = 0; i < N;i++){
        int num;
        cin >> num;
        Map[num]++;
    }
    cin >> N;
    for(int i = 0 ; i < N;i++){
        int num;
        cin >> num;
        if(i != 0) cout << " ";
        cout << Map[num];
    }
    cout << endl;
    return 0;
}