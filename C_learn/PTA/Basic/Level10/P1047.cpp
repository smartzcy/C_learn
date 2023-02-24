#include<iostream>
#include<map>
using namespace std;
int main(){
    int N;
    map<int,int>Map;
    cin >> N;
    while(N--){
        int dui , cy , score;
        cin >> dui >> cy >> score;
        Map[dui] += score;
    }
    int max = 0;
    for(auto i : Map){
        if(max == 0) max = i.first;
        if(Map[max] < i.second) max = i.first;
    }
    cout << max << " " << Map[max] << endl;
}