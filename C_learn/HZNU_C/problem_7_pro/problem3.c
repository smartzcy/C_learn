#include<stdio.h>
#include<stdlib.h>
struct Student
{
    char name[10];
    double n1;
    double n2;
    double n3;
    double average;
};
int cmp( const void *a ,const void *b) { 
return (*(struct Student *)a).average > (*(struct Student *)b).average ? 1 : -1; 
} 
int main(){
    int N;
    int max1 = 0;
    int max2 = 0;
    int max3 = 0;
    scanf("%d",&N);
    struct Student student[10000];
    for (int i = 0; i < N; i++){
        scanf("%s %lf %lf %lf",&student[i].name,&student[i].n1,&student[i].n2,&student[i].n3);
        student[i].average = (student[i].n1 + student[i].n2 + student[i].n3) / 3;
        if(student[max1].n1 < student[i].n1) max1 = i;
        if(student[max2].n2 < student[i].n2) max2 = i;
        if(student[max3].n3 < student[i].n3) max3 = i;
    }
    printf("%s,%.2f,%.2f,%.2f\n",student[max1].name,student[max1].n1,student[max1].n2,student[max1].n3);
    printf("%s,%.2f,%.2f,%.2f\n",student[max2].name,student[max2].n1,student[max2].n2,student[max2].n3);
    printf("%s,%.2f,%.2f,%.2f\n",student[max3].name,student[max3].n1,student[max3].n2,student[max3].n3);
    printf("\n");
    qsort(student,N,sizeof(student[0]),cmp);
    for(int i = N - 1; i>=0;i--){
        printf("%s,%.2f,%.2f,%.2f\n",student[i].name,student[i].n1,student[i].n2,student[i].n3);
    }
    printf("\n");
    for(int i = N - 1;i>=0;i--){
        if(student[i].average > 80){
            printf("%s,%.2f,%.2f,%.2f,%.2f\n",student[i].name,student[i].n1,student[i].n2,student[i].n3,student[i].average);
        }else break;
    }
}