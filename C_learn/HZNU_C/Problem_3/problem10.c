// #include<stdio.h>
// int main(){
//     int vul;
//     while(scanf("%d",&vul)!=EOF){
//         int d,time,k,t;
//         time = -1;
//         k = 1;
//         scanf("%d",&d);
//         int d1 = d;
//         if(vul % d==0)
//             t=vul/d;
//         else
//             t=vul/t+1;        
//         while (vul > 0)
//         {
            
//             vul = vul - d1;
//             time = time + 1;
//             d1 = d1 + d;

//         }
//         printf("%d\n",time + t);
//     }
//     return 0;
// }

#include <stdio.h>
int main(){
    int t,n,i,a;
    while (scanf("%d%d",&n,&i) != EOF){
        if(n % i == 0){
            t = n / i;
        }else{
            t = n / i + 1;
        } 
        for(a = 1 ;n > 0 ;a++){
            n = n - a * i;
        }
        printf("%d\n",a + t - 2);
    }
}