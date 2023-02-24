#include <stdio.h>
int strcmp(char *p1, char *p2);
int main() {
	char str1[101], str2[101], *p1, *p2;
	while (gets(str1) != NULL) {
		gets(str2);
		p1 = &str1[0];
		p2 = &str2[0];
		int m = strcmp(p1, p2);
		printf("%d\n", m);
	}
	return 0;
}
int strcmp(char *p1, char *p2) {
	for (; *p1 == *p2; p1++, p2++)
		if ('\0' == *p1)
			return 0;
	return *p1 - *p2;
}