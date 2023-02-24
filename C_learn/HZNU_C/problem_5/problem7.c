#include<stdio.h>
void fun0(){
    printf("这是1号函数的打印输出。\n");
}
void fun1(){
    printf("这是2号函数的打印输出。\n");
}
void fun2(){
    printf("这是3号函数的打印输出。\n");
}
int main(){
    void(*ptr[3])(int)={fun0,fun1,fun2};
    int n;
    while (scanf("%d", &n)!=EOF)
    {
        ptr[n-1](1);
    }
}