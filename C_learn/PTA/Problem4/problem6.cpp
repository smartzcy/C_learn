#include<iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
};
int main(){
    string num[100];
    int score[100];
    string next1[100];
    int n;
    string begin;
    cin >> begin >> n;
    for(int i = 0 ; i< n;i++){
        cin >> num[i] >> score[i] >> next1[i];
    }
    ListNode *head = new ListNode;
    for(int i = 0 ;i < n;i++){
        for(int j = 0 ; j < n;j++){
            if(num[j] == begin){
                begin = next1[j];
                if(i == 0){
                    head->val = j;
                    head->next = nullptr;
                }else {
                    ListNode *a = new ListNode;
                    a->val = j;
                    a->next = nullptr;
                    head->next = a;
                }
            }
        }
    }
    ListNode *b = head;
    int k = 0;
    while(b != nullptr){
        if(k != score[b->val]){
            cout << num[b->val] << " " << score[b->val] << " " << next1[b->val] << endl;
            k = score[b->val];
        }
        b = b->next;
    }
}