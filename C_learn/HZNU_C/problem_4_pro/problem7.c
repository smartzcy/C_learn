#include<stdio.h>
#include<math.h>
void happy(int row){
   if(row != 1){
        happy(row - 1);
   }
   for(int i = 1; i <= row; i++){
        if(i == row){
            printf("%d*%d=%d\n",i,row,i * row);
        }else{
            printf("%d*%d=%d ",i,row,i * row);
        }
   }
}
int main() {
    happy(9);
    return 0;
}