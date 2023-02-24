// #include<stdio.h>
// void Pr(int n){
//     int num[1000];
//     int k = 0;
//     int m = 1;
//     while (n > 0)
//     {
//         if(n % 2 == 1){
//             num[k++] = m;
//         }
//         n /= 2;
//         m++;
//     }
//     int j = k - 1;
//     for(int i = 0;i < k;i++){
//         if(i != k - 1){
//             printf("%d ",num[j]);
//         }else{
//             printf("%d\n",num[j]);
//         }
//         j--;
//     }
// }
// int main(){
//     char ch;
//     int n = 1;
//     long long num1 = 0;
//     long long num2 = 0;
//     while (scanf("%c",&ch) != EOF)
//     {
//         if(ch == '\n'){
//             if(n == 2){
//                 Pr(num1 + num2);
//                 n = 1;
//                 num1 = 0;
//                 num2 = 0;
//             }else n++;
//         }else{
//             if(n == 1){
//                 num1 = num1 * 2 + ch - 48;
//             }else{
//                 num2 = num2 * 2 + ch - 48;
//             }
//         }
//     }
// }
// #include<stdio.h>
// #include<string.h>
// int main(){
//     char str1[201];
//     char str2[201];
//     while (scanf("%s", &str1)!=EOF){
//         char str3[201] = {'0'};
//         scanf("%s", &str2);
//         int n = strlen(str1) - 1;
//         int m = strlen(str2) - 1;
//         int k = 200;
//         int num = 0;
//         while (n >= 0 || m >= 0){
//             if(n >= 0 && m >= 0){
//                 if(str1[n] == '1' && str2[m] == '1'){
//                     if(num == 1) str3[k] = '1';
//                     else str3[k] = '0';
//                     num = 1;
//                 }else if (str1[n] == '0' && str2[m] == '1' || str2[m] == '0' && str1[n] == '1'){
//                     if(num == 0) str3[k] = '1';
//                     else str3[k] = '0';
//                     num = 0;
//                 }else{
//                     if(num == 1)str3[k] = '1';
//                     else str3[k] = '0';
//                     num = 0;
//                 }
//                 n--;
//                 m--;
//                 k--;
//             }else{
//                 if(n >= 0){
//                     if(num == 1 && str1[n] == '1'){
//                         str3[k] = '0';
//                         num = 1;
//                     }else if(num == 1 || str1[n] == '1'){
//                         str3[k] = '1';
//                         num = 0;
//                     }else{
//                         str3[k] = '0';
//                     }
//                     n--;
//                     k--;
//                 }else if(m >= 0){
//                     if(num == 1 && str2[m] == '1'){
//                         str3[k] = '0';
//                         num = 1;
//                     }else if(num == 1 || str2[m] == '1'){
//                         str3[k] = '1';
//                         num = 0;
//                     }else{
//                         str3[k] = '0';
//                     }
//                     m--;
//                     k--;
//                 }
//             }
//         }
//         if(num = 1) str3[k--] = '1';
//         int s = 0;
//         for(int i = k + 1;i <= 200;i++){
//             if(str3[i] == '1') s++;
//         }
//         for(int i = k + 1;i <= 200;i++){
//             if(str3[i] == '1'){
//                 if(s == 1){
//                     printf("%d\n",201 - i);
//                 }else{
//                     printf("%d ",201 - i);
//                 }
//                 s--;
//             }
//         }
//     }
// }
// #include<stdio.h>
// #include<string.h>
// int main(){
//     char a[201];
//     char b[201];
//     while (scanf("%s %s",a,b) != EOF)
//     {
//         int n1 = strlen(a);
//         int n2 = strlen(b);
//         int k = n1 > n2 ? n1 : n2;
//         for(int i = 0; i < k;i++){
//             a[k - i] = a[n1 - i + 1];
//         }
//         for(int i = 0 ; i <= k - n1;i++){
//             a[i] = '0';
//         }
//         for(int i = 0 ; i <= k ;i++){
//             b[k - i] = b[n2 - i + 1];
//         }
//         for(int i = 0 ; i <= k - n2;i++){
//             b[i] = '0';
//         }
//         int j = 0;
//         for(int i = k;i > 0;i--){
//             j = a[i] - '0' + b[i] - '0' + j;
//             a[i] = j % 2 +'0';
//             j /= 2;
//         }
//         a[0] = j + '0';
//         int flag = 0;
//         printf("%s",a);
//         for(int i = 0;i <= k;i++){
//             if(!flag && a[i] == '1'){
//                 printf("%d",k + 1 - i);
//                 flag = 1;
//             }else if (a[i] == '1' && flag){
//                 printf(" %d",k + 1 - i);
//             }
//         }
//         printf("\n");
//     }
//     return 0;
// }
#include<stdio.h>
#include<string.h>
int main() {
	char a[210],b[210];
	int n1,n2,k;
	while(scanf("%s %s",a,b)!=EOF) {
		n1=strlen(a),n2=strlen(b);
        k = n1 > n2 ? n1 : n2; 
		for(int i=0; i<k; i++)
			a[k-i]=a[n1-i-1];
		for(int i=0; i<=k-n1; i++)
			a[i]='0';
		for(int i=0; i<=k; i++)
			b[k-i]=b[n2-i-1];
		for(int i=0; i<=k-n2; i++)
			b[i]='0';
        int j = 0;
        for(int i = k;i > 0;i--){
            j = a[i] - '0' + b[i] - '0' + j;
            a[i] = j % 2 +'0';
            j /= 2;
        }
		a[0] = j + '0';
		int flag=0;
		for(int i=0; i<=k; i++) {
			if(a[i]=='1'&& !flag) {
				printf("%d",k+1-i);
				flag = 1;
			} 
			else if(a[i]=='1'&& flag) printf(" %d",k+1-i);
		}
		printf("\n");
	}
	return 0;
}