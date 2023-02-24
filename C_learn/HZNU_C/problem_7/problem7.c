#include<stdio.h>
struct Door
{
    int direction;
    int time;
};

int main(){
    int n;
    int k = -1;
    struct Door door[100];
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d %d",&door[i].direction,&door[i].time);
    }
    int min_v;
    int max_v;
    scanf("%d %d",&min_v,&max_v);
    for(int i = 0; i < n; i++){
        if(door[i].direction / (double)max_v + door[i].time >= door[i].direction / (double)min_v){
            if(k == -1 || door[k].direction > door[i].direction) k = i;
        }
    }
    if(k != -1){
        printf("%.2f",door[k].direction / (double)min_v);
    }else{
        printf("let_s_die_together");
    }
}