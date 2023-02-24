// #include<stdio.h>
// #include<map>
// using namespace std;
// int main(){
//     typedef map<int,int> Map;
//     Map map;
//     int T;
//     scanf("%d",&T);
//     while (T--){
//         int N;
//         scanf("%d",&N);
//         while (N--){
//             int n,m;
//             scanf("%d %d",&n,&m);
//             if(map.find(m) == map.end()) map.insert(pair<int,int>(m,n));
//             else map[m] += n;
//         }
//         for(Map::reverse_iterator rit = map.rbegin();rit!=map.rend();rit++) {
//             if((*rit).second == 1){
//                 if((*rit).first == 0) printf("1");
//                 else if((*rit).first == 1) printf("x");
//                 else printf("x^%d",(*rit).first);
//             }else if((*rit).second == -1){
//                 if((*rit).first == 0) printf("-1");
//                 else if((*rit).first == 1) printf("-x");
//                 else printf("-x^%d",(*rit).first);
//             }else if((*rit).second != 0){
//                 if(rit == map.rbegin()){
//                     if((*rit).first == 0) printf("%d",(*rit).second);
//                     else printf("%dx^%d",(*rit).second,(*rit).first);
//                 }else{
//                     if((*rit).first == 0) printf("%+d",(*rit).second);
//                     else printf("%+dx^%d",(*rit).second,(*rit).first);
//                 }
//             }
//         }
//         printf("\n");
//         map.clear();
//     }
//     return 0;
// }
#include <iostream>
#include <map>
using namespace std;
#define ll long long
int main()
{
    int t, n, a, b;
    map<int, int> map1;
    cin >> t;
    while (t--)
    {
        int c;
        cin >> c;
        map1.clear();
        for (int i = 0; i < c; i++)
        {
            int n;
            int m;
            cin >> n >> m;
            map1[m] += n;
        }
        int flag = 0;
        for (map<int, int>::reverse_iterator it = map1.rbegin(); it != map1.rend(); ++it)
        {
            if (map1.size() == 1 && it->second == 0)
                cout << 0;
            if (it->second == 0)
                continue;
            if (it->second > 0 && flag)
                cout << "+";
            if (it->second != 1 && it->second != -1)
                cout << it->second;
            if (it->second == -1)
                cout << "-";
            if (it->first != 0 && it->first != 1)
                cout << "x^" << it->first;
            if (it->first == 1)
                cout << "x";
            flag = 1;
        }
        cout << endl;
    }
    return 0;
}