#include <iostream>
#include<algorithm>
#include<queue>
#include<unordered_map>
using namespace std;
unordered_map<string,int> map1;
// void way(){
//     string str = "0000";
//     queue<string> q;
//     queue<int> qt;
//     q.push(str);
//     qt.push(1);
//     while(!q.empty()) {
//         string x = q.front();
//         int ti = qt.front();
//         qt.pop();
//         q.pop();
//         if(map1[x] != 0) continue;
//         map1[x] = ti;
//         for(int i = 0 ; i < 4;i++){
//             for(int j = 0 ; j < 4;j++){
//                 string s = x;
//                 for(int k = i ; k <= j; k++){
//                     int z = s[k] - '0';
//                     z++;
//                     if(z == 10) z = 0;
//                     s[k] = z + '0';
//                 }
//                 q.push(s);
//                 qt.push(ti + 1);
//             }
//         }
//         for(int i = 0 ; i < 4;i++){
//             for(int j = 0 ; j < 4;j++){
//                 string s = x;
//                 for(int k = i ; k <= j;k++){
//                     int z = s[k] - '0';
//                     z--;
//                     if(z == -1) z = 9;
//                     s[k] = z + '0';
//                 }
//                 q.push(s);
//                 qt.push(ti + 1);
//             }
//         }
//     }
// }
void bfs(){
    string x="0000";
    queue<string>q;
    q.push(x);
    map1[x]=0;
    while(!q.empty()){
        string t=q.front();q.pop();
        for(int k=1;k<=4;k++){
            for(int i=0;i+k-1<4;i++){
                 int j=i+k-1;
                string add=t,sub=t;
                for(int w=i;w<=j;w++){
                    add[w]=(char)(((add[w]-'0'+1)%10)+'0');
                    sub[w]=(char)(((sub[w]-'0'+9)%10)+'0');
                }
                if(map1.find(add)==map1.end()){
                    q.push(add);
                    map1[add]=map1[t]+1;
                }
                if(map1.find(sub)==map1.end()){
                    q.push(sub);
                    map1[sub]=map1[t]+1;
                }
            }
        }
    }
}
int main(){
    int T;
    cin >> T;
    while(T--){
        string a , b , c = "0000";
        cin >> a >> b;
        for(int i = 0 ; i < 4;i++){
            c[i] = (char)((a[i] - b[i] + 10) % 10 + '0');
        }
        cout << map1[c] << endl;
    }
}