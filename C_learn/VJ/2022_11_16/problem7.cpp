// #include<iostream>
// #include<string>
// #include<vector>
// #include<map>
// using namespace std;
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int n;
//     cin >> n;
//     int sum = 0;
//     vector<string>vec;
//     map<int,int> map1;
//     while(n--){
//         string str;
//         cin >> str;
//         if(str == "insert"){
//             int num;
//             cin >> num;
//             string s = str + " " + to_string(num);
//             vec.push_back(s);
//             map1[num]++;
//             if(map1[num] == 1) sum++;
//         }else if(str == "removeMin"){
//             if(sum == 0) {
//                 vec.push_back("insert 1");
//                 vec.push_back(str);
//                 continue;
//             }
//             vec.push_back(str);
//             std::map<int,int>::iterator it = map1.begin();
//             while(it->second == 0){
//                 it++;
//             }
//             it->second--;
//             if(it->second == 0) sum--;
//         }else if(str == "getMin"){
//             int flag = 0;
//             int num;
//             cin >> num;
//             for(auto i : map1){
//                 if(i.first < num && i.second != 0){
//                     for(int j = 0 ; j < i.second ; j++){
//                         vec.push_back("removeMin");
//                     }
//                     sum--;
//                     map1[i.first] = 0;
//                 }else if(i.first == num && i.second != 0){
//                     vec.push_back(str + " " + to_string(i.first));
//                     flag = 1;
//                     break;
//                 }
//             }
//             if(flag == 1) continue;
//             map1[num]++;
//             if(map1[num] == 1) sum++;
//             string s = "insert " + to_string(num);
//             vec.push_back(s);
//             s = str + " " + to_string(num);
//             vec.push_back(s);
//         }
//     }
//     cout << vec.size() << endl;
//     for(auto i : vec){
//         cout << i << endl;
//     }
// }

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
    for(auto i : vec) cout << i << endl;
}