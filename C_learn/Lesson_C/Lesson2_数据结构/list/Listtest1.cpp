#include<iostream>
#include<math.h>
#include<stack>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* head;//开头指针
//头部插入
void Insert(int x){
    Node* temp = new Node();
    // Node* temp = (Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if(head != NULL) temp->next = head;
    head = temp;
}
//中间插入
void Insert1(int data , int n){ // data数据 , n位置
    Node* temp1 = new Node();
    temp1->data = data;
    temp1->next = NULL;
    if(n == 1){
        temp1->next = head;
        head = temp1;
    }else{
        Node* temp2 = head;
        for(int i = 0 ; i < n - 2;i++){
            temp2 = temp2->next;
        }
        temp1->next = temp2->next;
        temp2->next = temp1;
    }
}
//尾部插入
void Insert2(int data){
    Node* temp1 = new Node();
    temp1->data = data;
    temp1->next = NULL;
    if(head == NULL) head = temp1;
    else{
        Node* temp2 = head;
        while(temp2->next != NULL){
            temp2 = temp2->next;
        }
        temp2->next = temp1;
    }
}
//删除
void Delete(int n){
    Node* temp1 = head;
    if(n == 1){
        head = temp1->next;
        delete temp1;
    }else{
        for(int i = 0 ; i < n - 2;i++){
            temp1 = temp1->next;
        }
        Node* temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;//释放内存
    }
}
//翻转 迭代
void Reverse(){
    Node *temp = head , *prev = NULL;
    while(temp != NULL){
        Node* next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    head = prev;
}
void Print(){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
//打印 递归
void Print1(Node* head1){
    cout << head1->data << " ";
    if(head1->next != NULL) Print1(head1->next);
    else cout << endl;
}
//翻转 递归
void Reverse1(Node* p){
    if(p->next == NULL){
        head = p;
        return;
    }
    Reverse1(p->next);
    Node* q = p->next;
    q->next = p;
    p->next = NULL;
}
//判断是否回文
//方法一.分半
//快慢指针
bool isPalindrome2(Node *head){
    if(head == NULL || head->next == NULL) return true;
    Node *right = head->next;
    Node *cur = head;
    while(cur->next != NULL && cur->next->next != NULL){
        right = right->next;
        cur = cur->next->next;
    }
    stack<Node *> stack1;
    while(right != NULL){
        stack1.push(right);
        right = right->next;
    }
    while(!stack1.empty()){
        if(head->data != stack1.top()->data) return false;
        head = head->next;
        stack1.pop();
    }
    return true;
}
// 1->2->3->2->1;
// 后半进行翻转（双指针）
// 1->2->3<-2<-1;
// 最后变回去
bool isPalindrome3(Node *head){
    if(head == NULL || head->next == NULL) return true;
    Node *n1 = head;
    Node *n2 = head;
    while(n2->next != NULL && n2->next->next != NULL){
        n1 = n1->next;
        n2 = n2->next->next;
    }
    n2 = n1->next;
    n1->next = NULL;
    Node *n3 = NULL;
    //后半部分倒叙
    while(n2 != NULL){
        n3 = n2->next;
        n2->next = n1;
        n1 = n2;
        n2 = n3;
    }
    //n3方便还原
    n3 = n1;
    n2 = head;
    bool res = true;
    while(n1 != NULL && n2 != NULL){
        if(n1->data != n2->data){
            res = false;
            break;
        }
        n1 = n1->next;
        n2 = n2->next;
    }
    n1 = n3->next;
    n3->next = NULL;
    while(n1 != NULL){
        n2 = n1->next;
        n1->next = n3;
        n3 = n1;
        n1 = n2;
    }
    return res;
}
//链表partition <int ==int >int
Node *Sort(Node *head , int pivot){
    Node* sH = NULL;
    Node* sT = NULL;
    Node* eH = NULL;
    Node* eT = NULL;
    Node* mH = NULL;
    Node* mT = NULL;
    Node* next = NULL;
    while(head != NULL){
        next = head->next;
        head->next = NULL;
        if(head->data == pivot){
            if(eH == NULL){
                eH = head;
                eT = head;
            }else{
                eT->next = head;
                eT = head;
            }
        }else if(head->data < pivot){
            if(sH == NULL){
                sH = head;
                sT = head;
            }else{
                sT->next = head;
                sT = head;
            }
        }else{
            if(mH == NULL){
                mH = head;
                mT = head;
            }else{
                mT->next = head;
                mT = head;
            }
        }
        head = next;
    }
    if(sT != NULL){
        sT->next = eH;
        eT = eT == NULL ? sT : eT;
    }
    if(eT != NULL){
        eT->next = mH;
    }
    return sH != NULL ? sH : (eH != NULL ? eH : sH);
}
//判断一个链表是否循环 如果循环输出第一个循环的点
//用快慢指针 快指针一次走两步 慢指针一次走一步
//当快指针和慢指针相遇 快指针回到起点 然后每个都走一步 相遇的点就是第一个循环点
Node *isXunHuan(Node *head){
    if(head == NULL || head->next == NULL || head->next->next == NULL) return NULL;
    Node *fast = head->next->next;
    Node *slow = head->next;
    while(fast != slow){
        if(fast->next == NULL || fast->next->next == NULL) return NULL;
        fast = fast->next->next;
        slow = slow->next;
    }
    fast = head;
    while(fast != slow){
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}
//查找两个链表是否有交叉 如果有 返回第一个先交的点
//第一种情况 先找到最后的结点 如果最后的结点相等 说明有相交的 如果不相等 说明没有相交
//如果有相交 长的链表 先进行max - min步 使剩下的和短的一样长 然后遍历查找 找到一样的就是第一个相交的
Node *way1(Node *head1 , Node *head2){
    if(head1 == NULL || head2 == NULL) return NULL;
    int n = 0;
    Node *end1 = head1 , *end2 = head2;
    while(end1->next != NULL) {
        end1 = end1->next;
        n++;
    }
    while(end2->next != NULL) {
        end2 = end2->next;
        n--;
    }
    if(end1 != end2) return NULL;
    Node* cur1 = n > 0 ? head1 : head2;
    Node* cur2 = n > 0 ? head2 : head1;
    n = abs(n);
    while(n--){
        cur1 = cur1->next;
    }
    while(cur1 != cur2){
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return cur1;
}
Node *isawd(Node *head1 , Node *head2){
    //情况一：没有循环的链表 有两种情况 一种是无相交的 一种是先交的
    if(isXunHuan(head1) == NULL && isXunHuan(head2) == NULL){
        return way1(head1 , head2);
    }else if(isXunHuan(head1) == NULL || isXunHuan(head2) == NULL){
        return NULL;
    }else{
        Node *loop1 = isXunHuan(head1) , *loop2 = isXunHuan(head2);
        if(loop1 == loop2){
            Node *temp1 = loop1->next , *temp2 = loop2->next;
            loop1->next = NULL;
            loop2->next = NULL;
            Node *temp = way1(head1 , head2);
            loop1->next = temp1;
            loop2->next = temp2;
            return temp;
        }else{
            Node *temp = loop1;
            loop1 = loop1->next;
            while(loop1 != loop2 && loop1 != temp){
                loop1 = loop1->next;
            }
            if(loop1 == loop2) return loop1;
            else return NULL;
        }
    }
}
int main(){
    // head = NULL;
    // Node* temp = new Node();
    // //首选 new
    // //Node* temp = (Node*)malloc(sizeof(Node));
    // // malloc是开启一个内存块 用于存放Node 返回的是这个内存快的void性地址 要进行类型转换
    // {//建立一个新的结点
    // temp->data = 2;
    // //(*temp).data = 2;一样的
    // temp->next = NULL;
    // //(*temp).next = NULL;
    // head = temp;
    // }
    // //结尾插入
    // //遍历 遍历到最后 然后将temp放到最后
    // Node* temp1 = head;
    // while(temp1->next != NULL){
    //     temp1 = temp1->next;
    //     cout << temp1->data << endl;
    // }
    // temp1->next = temp;
    head = NULL;
    int n , x;
    cin >> n;
    for(int i = 0 ; i < n;i++){
        cin >> x;
        Insert2(x);
    }
    Print1(head);
    Reverse();
    Print();
    return 0;
}