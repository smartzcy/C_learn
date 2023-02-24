#include<stdio.h>
int isLeap(int x){
    if(x % 4 == 0 && x % 100 != 0 || x % 400 == 0) return 29;
    return 28;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",isLeap(n));
	}
}