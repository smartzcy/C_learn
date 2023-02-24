#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int T;
    cin >> T;
    vector<pair<int,pair<int,int>>> vec;
    vec.push_back({0,{0,0}});
    int num[2001] = {0};
    for(int m = 1 ; m <= T;m++){
        int k;
        cin >> k;
        if(k == 1){
            int a , b;
            cin >> a >> b;
            for(int i = a ; i <= b;i++){
                num[i] = m;
            }
            vec.push_back({1,{a , b}});
        }else if(k == 2){
            int a , b;
            cin >> a >> b;
            for(int i = a ; i <= b; i++){
                num[i] = -m;
            }
            vec.push_back({2,{a , b}});
        }else if(k == 3){
            int a;
            cin >> a;
            vec.push_back({3,{a , 0}});
            while(true){
                if(vec[a].first == 1){
                    for(int i = vec[a].second.first;i <= vec[a].second.second;i++){
                        if(num[i] == 0) num[i] = a;
                        else if(num[i] == a) num[i] = 0;
                    }
                    break;
                }else if(vec[a].first == 2){
                    for(int i = vec[a].second.first;i <= vec[a].second.second;i++){
                        if(num[i] == 0) num[i] = -a;
                        else if(num[i] == -a) num[i] = 0;
                    }
                    break;
                }else{
                    a = vec[a].second.first;
                }
            }
        }
        int sum = 0;
        int flag = 0;
        for(int i = 1 ; i <= 2000 ; i++){
            if(num[i] > 0){
                if(flag == 0){
                    flag = 1;
                    sum++;
                }
            }else{
                flag = 0;
            }
        }
        cout << sum << endl;
    }
}