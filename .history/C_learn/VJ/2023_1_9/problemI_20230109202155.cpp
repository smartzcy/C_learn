// #include<iostream>
// #include<algorithm>
// #include<vector>
// using namespace std;
// int main(){
//     int n , flag = 0;
//     cin >> n;
//     vector<string> vec;
//     for(int i = 0 ; i < n ; i++){
//         string str;
//         cin >> str;
//         vec.push_back(str);
//     }
//     string str = vec[vec.size()-1];
//     string s = str.substr(0,1);
//     for(int i = vec.size() - 2 ; i >= 0 ; i--){
//         for(int j = 0 ; j < min(vec[i].size() , str.size()) ; j++){
//             if(vec[i][j] != str[j]){
//                 if(s.find(vec[i][j]) == string::npos){
//                     s = vec[i][j] + s;
//                 }else if(s.find(vec[i][j]) > 0){
//                     flag = 1;
//                 }
//                 break;
//             }
//         }
//     }
//     if(flag == 1) cout << "Impossible" << endl;
//     else {
//         for(int i = 0 ; i < 26;i++){
//             char ch = i + 'a';
//             if(s.find(ch) == string::npos){
//                 cout << ch;
//             }else if(ch == s[0]){
//                 cout << s;
//             }
//         }
//     }
// }

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> vec[50];
int d[50];
int main(){
    int n;
    cin >> n;
    string s1 , s2;
    cin >> s1;
    for(int i = 2 ; i <= n;i++){
        cin >> s2;
        for(int j = 0 ; j < s1.size();j++){
            if(j >= s2.size()){
                cout << "Impossible" << endl;
                return 0;
            }
            if(s1[j] != s2[j]){
                vec[s1[j] - 'a' + 1].push_back(s2[j] - 'a' + 1);
                d[s2[j] - 'a' + 1]++;
                break;
            }
        }
        s1 = s2;
    }
    queue<int> q;
    for(int i = 1; i <= 26;i++){
        if(d[i] == 0) q.push(i);
    }
    vector<int> ans;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        ans.push_back(now);
        for(int i = 0 ; i < vec[now].size() ; i++){
            d[vec[now][i]]--;
            if(d[vec[now][i]] == 0) q.push(vec[now][i]);
        }
    }
    if(ans.size() == 26){
        for(int i = 0 ; i < ans.size() ; i++) cout << (char)(ans[i] + 'a' - 1);
    }else cout << "Impossible" << endl;
}