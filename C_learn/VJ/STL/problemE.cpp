#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    multiset<int> set1;
    vector<string>vec;
    while(n--){
        string str;
        cin >> str;
        if(str == "insert"){
            int num;
            cin >> num;
            vec.push_back(str + " " + to_string(num));
            set1.insert(num);
        }else if(str == "removeMin"){
            if(set1.size() == 0) {
                vec.push_back("insert 1");
                vec.push_back(str);
                continue;
            }
            vec.push_back(str);
            set1.erase(set1.begin());
        }else if(str == "getMin"){
            int num;
            cin >> num;
            while(set1.size() && (*set1.begin() < num)){
                set1.erase(set1.begin());
                vec.push_back("removeMin");
            }
            if(set1.size() && (*set1.begin()) == num){
                vec.push_back("getMin " + to_string(num));
            }else{
                set1.insert(num);
                vec.push_back("insert " + to_string(num));
                vec.push_back(str + " " + to_string(num));
            }
        }
    }
    cout << vec.size() << endl;
    for(auto i : vec){
        cout << i << endl;
    }
}