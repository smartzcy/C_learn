// #include<stdio.h>
// int main(){
//     while (1)
//     {
//         char str;
//         scanf("%c",&str);
//         if (str == '@'){
//             break;
//         }
//         int n;
//         scanf("%d",&n);
//         for (int i = 1; i <= n; i++){
//             if(i == 1){
//                 for (int j = 1; j < n; j++) printf(" ");
//                 printf("%c\n",str);
//             }else if(i == n){
//                 for (int j = 1; j <= n * 2 - 1; j++) printf("%c",str);
//                 printf("\n");
//             }else {
//                 for (int j = 1; j < n + i - 1; j++){
//                     if(j == n - i + 1){
//                         printf("%c",str);
//                     }else {
//                         printf(" ");
//                     }
//                 }
//                 printf("%c\n",str);
//             }
//             if(i == n){
//                 printf("\n");
//                 printf("\n");
//             }
//         }
//         n = 0;
//     }
// }
#include<stdio.h>
int main(){
    while (1)
    {
        char str;
        scanf("%c",&str);
        if (str == '@'){
            break;
        }
        int n;
        scanf("%d",&n);
        getchar();
        for (int i = 1; i <= n; i++){
            if(i == 1){
                for (int j = 1; j < n; j++) printf(" ");
                printf("%c\n",str);
            }else if(i == n){
                for (int j = 1; j <= n * 2 - 1; j++) printf("%c",str);
                printf("\n");
            }else {
                for (int j = 1; j < n + i - 1; j++){
                    if(j == n - i + 1){
                        printf("%c",str);
                    }else {
                        printf(" ");
                    }
                }
                printf("%c\n",str);
            }
            if(i == n) printf("\n");
        }
        n = 0;
    }
}

// #include<stdio.h>
// int main() {
//    char q;
//    int n;
//    while (scanf("%c%d", &q, &n) != EOF && q != '@') {
//       for (int i = 1; i <= n; i++) {
//          for (int x = 1; x <= n + i - 1; x++)
//             if (x == n - i + 1 || x == n + i - 1 || i == n)
//                printf("%c", q);
//             else
//                printf(" ");
//          printf("\n");
//       }
//       printf("\n");
//    }
// }