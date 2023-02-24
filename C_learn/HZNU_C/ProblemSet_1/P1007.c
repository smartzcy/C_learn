// #include<stdio.h>
// int main(){
//     int N;
//     long long X;
//     int t = 1;
//     while (scanf("%d %lld",&N,&X) != EOF){
//         if(t != 1) printf("\n");
//         int flag = 0;
//         printf("Case %d:\n",t++);
//         for (int i = 0; i < N; i++)
//         {
//             long long num;
//             scanf("%lld",&num);
//             if(num != X){
//                 if(flag) printf(" ");
//                 if(i != N - 1) printf("%lld",num);
//                 flag = 1;
//             }
//         }
//         if(flag) printf("\n");
//         else printf("Empty!");
//     }
    
// }
#include<stdio.h>
int main() {
	int flag;
	int N, t = 0;
	long long num, X;
	while (~scanf("%d %lld", &N, &X)) {
		flag = 0;
		if (t != 0)printf("\n");
		printf("Case %d:\n", ++t);
		for (int i = 0; i < N; i++) {
			scanf("%lld", &num);
			if (num != X) {
				if (flag) printf(" ");
				printf("%lld", num);
				flag = 1;
			}
		}
		if (flag) printf("\n");
		else printf("Empty!");
	}
	return 0;
}

#include<stdio.h>
int main() {
	int flag;
	int isFirstCase = 1;
	int n, t = 0;
	long long num, x;
	while (~scanf("%d %lld", &n, &x)) {
		flag = 0;
		if (isFirstCase) isFirstCase = 0;
		else puts("");
		printf("Case %d:\n", ++t);
		for (int i = 0; i<n; i++) {
			scanf("%lld", &num);
			if (num != x) {
				if (flag) printf(" ");
				printf("%lld", num);
				flag = 1;
			}
		}
		if (flag) puts("");
		else puts("Empty!");
	}
	return 0;
}