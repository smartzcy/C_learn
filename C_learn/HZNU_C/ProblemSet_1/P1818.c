// #include<stdio.h>
// int main(){
//     FILE *file;
//     file = fopen("1.txt","r");
//     if(file == NULL){
//         file = fopen("1.txt","w+");
//         printf("1");
//     }else{
//         printf("0");
//     }
//     return 0;
// }

#include<stdio.h>
int main() {
    FILE *fp;
    if(fopen("aaabbb.txt","r")==NULL)printf("1");
    else printf("0");
    fp=fopen("aaabbb.txt","w");
}