#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
};
Node* head;
void InsertAtHead(int x){
    Node* temp = new Node();
    temp->data = x;
    temp->prev = NULL;
    if(head == NULL) temp->next = NULL;
    else temp->next = head;
    head = temp;
}
void Insert(int x , int n){
    Node* temp = new Node();
    temp->data = x;
    if(n == 1){
        temp->next = head;
        temp->prev = NULL;
        head = temp;
        return ;
    }
    Node* temp1 = head;
    for(int i = 0 ; i < n - 2;i++){
        temp1 = temp1->next;
    }
    if(temp1->next == NULL){
        temp->next = NULL;
    }else{
        Node* temp2 = temp1->next;
        temp->next = temp2;
        temp2->prev = temp;
    }
    temp1->next = temp;
    temp->prev = temp1;
}
void Delete(int n){
    Node* temp1 = head;
    for(int i = 0 ;i < n - 1;i++){
        temp1 = temp1->next;
    }
    if(temp1->next != NULL){
        temp1->prev->next = temp1->next;
        temp1->next->prev = temp1->prev;
    }else{
        temp1->prev->next = NULL;
    }
    delete temp1;
}
void Print(){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){
    head = NULL;
    int n;
    cin >> n;
    for(int i = 0 ; i < n;i++){
        int num , n;
        cin >> num >> n;
        Insert(num,n);
    }
    Print();
    cin >> n;
    for(int i = 0 ; i < n;i++){
        int num;
        cin >> num;
        Delete(num);
    }
    Print();
}