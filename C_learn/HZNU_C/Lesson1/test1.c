#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a, const void *b){
	char *x = (char *)a;
	char *y = (char *)b;
	while(*x != '\0' && *y != '\0' && *x == *y){
		x++;
		y++;
	}
	if(*x == '\0') return 1;
	else if(*y == '\0') return 0;
	return *x - *y;
}
int main(){
	char str[2][10] = {"abadw","aaada"};
	qsort(str , 2 , sizeof(str[0]), cmp);
	printf("%s\n",str[0]);
	printf("%s",str[1]);
}