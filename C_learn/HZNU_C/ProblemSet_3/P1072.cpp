#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	int ans;
	char put[200];
	while(~scanf("%s",&put) && put[0] != 48)
	{
		if(strlen(put) == 1 && put[strlen(put) - 1] == '0') break;
		ans = 0;
		for(int i = 0;i < strlen(put);++i) ans = (ans * 10 + put[i] - 48) % 17;
		printf("%d\n",ans == 0?1:0);
	}
	return 0;
}