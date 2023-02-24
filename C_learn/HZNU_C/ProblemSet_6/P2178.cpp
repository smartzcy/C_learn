#include<iostream>
#include<map>
using namespace std;
int main(){
    map<string,int>map;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int Level[10] , score[30][10] = {{0}} , Problem_People[10] = {0};
    int T , M , n = 0;
    cin >> T;
    for(int i = 0 ; i < T;i++) cin >> Level[i];
    cin >> M;
    for(int i = 0 ; i < M;i++){
        string str;
        char ch;
        cin >> str >> ch;
        if(map.find(str) == map.end()) map.insert(pair<string,int>(str,n++));
        score[map[str]][ch - 'A'] = 50 * Level[ch - 'A'] + (int)(50 * Level[ch - 'A'] / (0.8 + 0.2 * (++Problem_People[ch - 'A'])));
    }
    for(auto i : map)
        for(int j = 0 ; j < T;j++)
            score[i.second][9] += score[i.second][j];
    for(int i = 0 ; i < n;i++){
        int max = 0;
        for(int j = 1 ; j < n;j++) if(score[max][9] < score[j][9]) max = j;
        for(auto j : map)
            if(j.second == max){
                cout << i + 1 << " " << j.first;
                for(int k = 0 ; k < T;k++) cout << " " << score[max][k];
                cout << " " << score[max][9] << endl;
                score[max][9] = 0;
                break;
            }
    }
    return 0;
}