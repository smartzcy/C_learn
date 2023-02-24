#include<stdio.h>
#include<map>
#include<string>
using namespace std;
int main(){
    map<string,int> Map;
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        char name[51];
        int score;
        for (int i = 0; i < n; i++){
            scanf("%s %d",name,&score);
            Map.insert(pair<string,int>(name,score));
        }
        int m;
        scanf("%d",&m);
        getchar();
        for(int i = 0;i < m;i++){
            char name1[51];
            scanf("%s",name1);
            if(Map.find(name1) == Map.end()){
                printf("error\n");
            }else{
                printf("%d\n",Map[name1]);
            }
        }
    }
    
}