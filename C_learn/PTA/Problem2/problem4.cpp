#include<stdio.h>
#include<map>
using namespace std;
int main(){
    map<int,int> hang;
    map<int,int> li;
    int N , M , Q;
    scanf("%d %d %d",&N,&M,&Q);
    int H  = 0, L = 0;
    for(int i = 1 ; i <= Q;i++){
        int n , m;
        scanf("%d %d",&n,&m);
        if(n == 0){
            if(hang.find(m) == hang.end()){
                hang.insert(pair<int,int>(m,1));
            }
        }else{
            if(li.find(m) == li.end()){
                li.insert(pair<int,int>(m,1));
            }
        }
    }
    H = hang.size();
    L = li.size();
    printf("%lld",N * M - N * H - M * L + H * L);
}