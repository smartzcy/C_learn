#include<stdio.h>
struct WaiHao{
        char name[30];
        int time;
};
int main(){
    struct WaiHao waihao[110];
    int num[110];
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for(int i = 0;i<n;i++){
            scanf("%s %d",&waihao[i].name,&waihao[i].time);
            num[i] = 0;
        }
        for(int i = 0;i < n; i++){
            int k = 0;
            for(int j = 1;j < n;j++){
                if(waihao[k].time < waihao[j].time && num[j] == 0 || num[k] == 1) {
                    k = j;
                }
            }
            printf("%s\n",waihao[k].name);
            num[k] = 1;
        }
    }
}