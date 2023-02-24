// #include<iostream>
// #include<algorithm>
// #include<map>
// #include<string>
// #include<string.h>
// using namespace std;
// int main(){
//     string str1[10001];
//     map<string,int> map;
//     int T;
//     cin>>T;
//     while (T--){
//         int k = 0;
//         int n;
//         cin>>n;
//         for(int i = 0; i < n; i++){
//             string str;
//             cin>>str;
//             if(map.find(str) == map.end()){
//                 str1[k++] = str;
//                 map.insert(pair<string,int>(str,1));
//             }else map[str]++;
//         }
//         cout<<k<<'\n';
//         sort(str1,str1 + k);
//         for(int i = 0; i < k;i++) cout<<str1[i]<<": "<<map[str1[i]]<<'\n';
//         cout<<'\n';
//     }
// }
#include<iostream>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
const int N=1e5+7;
string s[N];
int main() {
    int T;
    cin >> T;
    while(T--) {
        map<string,int>mp;
        int n;
        int cnt=0;
        cin >> n;
        for(int i=1; i<=n; ++i) {
            cin >> s[i];
            mp[s[i]]++;
            if(mp[s[i]]==1) cnt++;
        }
        cout << cnt << endl;
        for(auto i:mp) cout << i.first << ": " <<i.second<<endl;
        cout << endl;
    }
}