#include<stdio.h>
int main(){
    int N,K,S;
    int num[116] = {0};
    int Pta[116] = {0};
    scanf("%d %d %d",&N,&K,&S);
    while (N--)
    {
        int score , pta;
        scanf("%d %d",&score,&pta);
        if(score >= 175){
            num[score - 175]++;
            if(pta >= S) Pta[score - 175]++;
        }
    }
    int people = 0;
    for(int i = 0; i <= 115;i++){
        if(num[i] != 0){
            if(Pta[i] != 0){
                people = people + Pta[i] + ((num[i] - Pta[i]) > K ? K:num[i] - Pta[i]); 
            }else{
                people = people + (num[i] > K ? K:num[i]);
            }
        }
    }
    printf("%d",people);
}