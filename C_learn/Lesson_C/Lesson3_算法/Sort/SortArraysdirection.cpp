#include<iostream>
#include<queue>
using namespace std;
int sort(){
    priority_queue<int> heap;
}
int main(){
    //优先级队列 小根堆
    priority_queue<int,vector<int>,greater<int>> heap;
    //优先级队列 大根堆
    //priority_queue<int> heap;
    heap.push(3);
    heap.push(4);
    heap.push(6);
    heap.push(2);
    heap.push(1);
    heap.push(0);
    while(!heap.empty()) {
        cout << heap.top() << endl;
        heap.pop();
    }
}