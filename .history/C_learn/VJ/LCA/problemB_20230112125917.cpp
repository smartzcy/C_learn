#include<cstdio>
#include<vector>
using namespace std;
const int N = 1000;
int n;
vector<int> vec[N];
int main(){
    while(~scanf("%d",&n)){
        for(int i = 0 ; i < n ; i++){
            int m , nm;
            scanf("%d:(%d)" , &m , &nm);
            for(int j = 0 ; j < nm ; j++){
                int num;
                scanf("%d", &num);
                vec[m].push_back(num);
            }
        }
        int m;
        scanf("%d", &m);
        while(m--){
            int u , v;
            scanf(" (%d %d)" , &u , &v);
            
        }
    }
}