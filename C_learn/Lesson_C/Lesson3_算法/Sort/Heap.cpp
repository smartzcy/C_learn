#include<iostream>
#include<algorithm>
using namespace std;
/*
*堆 用数组实现
*左侧为i * 2 + 1
*右侧为i * 2 + 2
*大堆：父要比所有的子都大
*小堆：父要比所有的子都小
*/
// 某个数现在处在index位置，往上继续移动
void heapInsert(int arr[] , int index){
    while(arr[index] > arr[(index - 1) / 2]){
        swap(arr[index] , arr[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}
//删除堆中最大的
//并且重新变为大堆
//某个数在index位置，能否往下移动
void heapify(int arr[] , int index , int heapSize){
    int left = index * 2 + 1;//左孩子的下标
    while(left < heapSize){ //下方还有孩子的时候
        //两个孩子中，谁的值大，吧下标给largest
        int largest = left + 1 < heapSize && arr[left + 1] > arr[left] ? left + 1 : left;
        //父和较大孩子之间，谁的值大，把下标给largest
        largest = arr[largest] > arr[index] ? largest : index;
        if(largest == index) break;
        swap(arr[largest], arr[index]);
        index = largest;
        left = index * 2 + 1;
    }
}

//堆排序
void heapSort(int arr[]){
    int k = sizeof(arr) / sizeof(*arr);
    if(arr == NULL || ( k < 2)){
        return;
    }
    for(int i = 0 ;  i < k ; i++){
        heapInsert(arr,i);
    }
    //更快的
    // for(int i = k - 1 ; i >= 0 ;i--){
    //     heapify(arr , i , k);
    // }
    int heapSize = k;
    swap(arr[0],arr[--heapSize]);
    while(heapSize > 0){
        heapify(arr,0,heapSize);
        swap(arr[0],arr[--heapSize]);
    }
}