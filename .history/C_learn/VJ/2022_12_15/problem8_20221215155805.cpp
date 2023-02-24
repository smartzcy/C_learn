#include<iostream>
using namespace std;
struct Tree{
    int val;
    int length;
    Tree* left;
    Tree* right;
    Tree(int val):val(val){}
};
Tree* root = new Tree(1);
void insert(int u , int v , int w , Tree* head){
    if(head->val == u){
        if(head->left == NULL) head->left = new Tree(v);
        else head->right = new Tree(v);
    }
}
int main(){
    int n , m;
    cin >> n >> m;
    for(int i = 1 ; i < n ; i++){
        int u , v , w;
        cin >> u >> v >> w;

    }
}