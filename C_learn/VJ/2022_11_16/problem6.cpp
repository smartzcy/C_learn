#include<iostream>
#include<map>
using namespace std;
int main(){
    int n;
    map<int,int> map1;
    while(cin >> n){
        if(n == 0) break;
        if(n == 1){
            int K , P;
            cin >> K >> P;
            map1[P] = K;
        }else if(n == 2){
            if(map1.size() == 0){
                cout << "0" << endl;
                continue;
            }
            std::map<int,int>::iterator it = map1.end();
            --it;
            cout << it->second << endl;
            map1.erase(it);
        }else if(n == 3){
            if(map1.size() == 0){
                cout << "0" << endl;
                continue;
            }
            std::map<int,int>::iterator it = map1.begin();
            cout << it->second << endl;
            map1.erase(it);
        }
    }
}