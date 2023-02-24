#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
using namespace std;
int main(){
    map<char , vector<pair<char , int> > > map1;
    string str;
    cin >> str;
    for(int i = 0 ;i < 8;i++){
        cin >> str;
        int k = 0;
        for(int j = 0 ; j < str.length() ;j++){
            if(str[j] == '|') k++;
            if(str[j] <= 'z' && str[j] >= 'a' || str[j] <= 'Z' && str[j] >= 'A'){
                map1[str[j]].push_back({(char)('a' + k - 1),i + 1});
            }
        }
        cin >> str;
    }
    cout << "White: ";
    if(map1.find('K') != map1.end()){
        cout << "K" << map1['K'][0].first << abs(map1['K'][0].second - 9);
    }
    if(map1.find('Q') != map1.end()){
        for(auto i : map1['Q']) cout << "," << "Q" << i.first << abs(i.second - 9);
    }
    if(map1.find('R') != map1.end()){
        for(auto i : map1['R']) cout << "," << "R" << i.first << abs(i.second - 9);
    }
    if(map1.find('B') != map1.end()){
        for(auto i : map1['B']) cout << "," << "B" << i.first << abs(i.second - 9);
    }
    if(map1.find('N') != map1.end()){
        for(auto i : map1['N']) cout << "," << "N" << i.first << abs(i.second - 9);
    }
    if(map1.find('P') != map1.end()){
        for(auto i : map1['P']) cout << "," << i.first << abs(i.second - 9);
    }
    cout << endl;
    cout << "Black: ";
    if(map1.find('k') != map1.end()){
        cout << "K" << map1['k'][0].first << abs(map1['k'][0].second - 9);
    }
    if(map1.find('q') != map1.end()){
        for(auto i : map1['q']) cout << "," << "Q" << i.first << abs(i.second - 9);
    }
    if(map1.find('r') != map1.end()){
        for(auto i : map1['r']) cout << "," << "R" << i.first << abs(i.second - 9);
    }
    if(map1.find('b') != map1.end()){
        for(auto i : map1['b']) cout << "," << "B" << i.first << abs(i.second - 9);
    }
    if(map1.find('n') != map1.end()){
        for(auto i : map1['n']) cout << "," << "N" << i.first << abs(i.second - 9);
    }
    if(map1.find('p') != map1.end()){
        for(auto i : map1['p']) cout << "," << i.first << abs(i.second - 9);
    }
}
