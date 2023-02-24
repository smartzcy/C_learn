//搜索二叉树 BST
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct BstNode{
    int data;
    BstNode* left;
    BstNode* right;
    BstNode() : data(0) , left(NULL) , right(NULL){};
    BstNode(int data) : data(data) , left(NULL) , right(NULL){};
};
//输入
BstNode* Insert(BstNode* root, int data){
    if(root == NULL) root = new BstNode(data);
    else if(data <= root->data) root->left = Insert(root->left , data);
    else root->right = Insert(root->right , data);
    return root;
}
//删除
BstNode* Delete(BstNode* root , int data){
    if(root == NULL) return root;
    else if(data < root->data) root->left = Delete(root->left , data);
    else if(data > root->data) root->right = Delete(root->right , data);
    else {
        if(root->right == NULL && root->left == NULL) {
            delete root;
            root = NULL;
        }else if(root->left == NULL){
            BstNode* temp = root;
            root = root->right;
            delete temp;
        }else if(root->right == NULL){
            BstNode* temp = root;
            root = root->left;
            delete temp;
        }else{
            BstNode* temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right , temp->data);
        }
    }
    return root;
}
BstNode* Getsunccessor(BstNode* root , int data){
    BstNode* current = Find1(root,data);
    if(current == NULL) return NULL;
    if(current->right != NULL){
        return FindMin(current->right);
    }else{
        BstNode* successor = NULL;
        BstNode* ancestor = root;
        while(ancestor != current){
            if(current->data < ancestor->data){
                successor = ancestor;
                ancestor = ancestor->left;
            }else ancestor = ancestor->right;
        }
        return successor;
    }
}
BstNode* Find1(BstNode* root , int data){
    if(root == NULL) return NULL;
    if(root->data == data) return root;
    else if(root->data < data) return Find1(root->right , data);
    else return Find1(root->left , data);
}
//查找
bool Search(BstNode* root , int data){
    if(root == NULL) return false;
    if(root->data == data) return true;
    else if(root->data < data) return Search(root->right , data);
    else return Search(root->left , data);
}
//差找最小值（遍历）
BstNode* FindMin(BstNode* root){
    if(root == NULL) {
        cout << "Tree is empty" << endl;
        return NULL;
    }
    BstNode* temp = root;
    while(temp->left != NULL) temp = temp->left;
    return temp;
}
//找最小值（递归）
int FindMin1(BstNode* root){
    if(root == NULL) {
        cout << "Tree is empty" << endl;
        return -1;
    }
    if(root->left != NULL) return FindMin1(root->left);
    else return root->data;
}
//查找对大高
int FindHeight(BstNode* root){
    if(root = NULL) return -1;
    return max(FindHeight(root->right) , FindHeight(root->left)) + 1;
}
//层次遍历
void LevelOrder(BstNode* root){
    if(root == NULL) return ;
    queue<BstNode*>q;
    q.push(root);
    while(!q.empty()){
        cout << q.front()->data << " ";
        if(q.front()->left != NULL) q.push(q.front()->left);
        if(q.front()->right != NULL) q.push(q.front()->right);
        q.pop();
    }
}
//层次遍历 将每一行存入vector中
vector<vector<BstNode*>> vec;
void way(BstNode* root , int k){
    if(root == NULL) return;
    if(k == vec.size()){
        vector<BstNode*> v;
        vec.push_back(v);
    }
    vec[k].push_back(root);
    way(root->left, k + 1);
    way(root->right, k + 1);
}
//先序遍历
void PreOrder(BstNode* root){
    if(root == NULL) return ;
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}
//先序遍历（不递归）
void PreOrder1(BstNode* root){
    stack<BstNode *> s;
    s.push(root);
    while(!s.empty()){
        root = s.top();
        s.pop();
        cout << root->data << " ";
        if(root->right != NULL) s.push(root->right);
        if(root->left != NULL) s.push(root->left);
    }
    cout << endl;
}
//中序遍历
void InOrder(BstNode* root){
    if(root == NULL) return ;
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}
//中序遍历（不递归）
void InOrder1(BstNode* root){
    stack<BstNode*> s;
    while(!s.empty() || root != NULL){
        if(root != NULL){
            s.push(root);
            root = root->left;
        }else{
            root = s.top();
            s.pop();
            cout << root->data << " ";
            root = root->right;
        }
    }
    cout << endl;
}
//后序遍历
void PostOrder(BstNode* root){
    if(root == NULL) return ;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}
//后序遍历（不递归）
void PostOrder1(BstNode* root){
    stack<BstNode*> s;
    stack<BstNode*> shou;
    s.push(root);
    while(!s.empty()){
        root = s.top();
        s.pop();
        shou.push(root);
        if(root->right != NULL) s.push(root->right);
        if(root->left != NULL) s.push(root->left);
    }
    while(!shou.empty()){
        cout << shou.top()->data << " ";
        shou.pop();
    }
    cout << endl;
}
//判断一棵树是否为搜索二叉树
//方法一
bool InSubtreeLesser(BstNode* root, int value){
    if(root == NULL) return true;
    if(root->data <= value && InSubtreeLesser(root->left, value) && InSubtreeLesser(root->right,value)) return true;
    else return false;
}
bool IsSubtreeGreater(BstNode* root,int value){
    if(root == NULL) return true;
    if(root->data > value && IsSubtreeGreater(root->left, value) && IsSubtreeGreater(root->right, value)) return true;
    else return false;
}
bool IsBST(BstNode* root){
    if(root == NULL) return true;
    if(InSubtreeLesser(root->left,root->data) && IsSubtreeGreater(root->right,root->data) && IsBST(root->left) && IsBST(root->right)) return true;
    else return false;
}
//方法二
//IsBST1(root, INT_MIN, INT_MAX);
bool IsBST1(BstNode* root, int minValue, int maxValue){
    if(root == NULL) return true;
    if(root->data > minValue && root->data < maxValue && IsBST1(root->left, minValue, root->data) && IsBST1(root->right, root->data, maxValue)) return true;
    else return false;
}
//判断是否为完全二叉树
bool IsCBT(BstNode* head){
    if(head == NULL) return true;
    vector<BstNode*> vec;
    bool leaf = false;
    BstNode* l = NULL;
    BstNode* r = NULL;
    vec.push_back(head);
    while(!vec.empty()){
        head = *(vec.begin());
        vec.erase(vec.begin());
        l = head->left;
        r = head->right;
        //如果有一个原先有一个结点是无或者单边子结点的 那leaf记为true 之后的结点必须全为空子结点  或者 当一个结点无左结点 有右结点 那就不是完全二叉树
        if((leaf && (l != NULL || r != NULL)) || (l == NULL && r != NULL)) return false;
        if(l != NULL) vec.push_back(l);
        if(r != NULL) vec.push_back(r);
        if(l == NULL || r == NULL) leaf = true;
    }
    return true;
}
int main(){
    BstNode* root = NULL;
    int n;
    cin >> n;
    for(int i = 0 ; i < n;i++){
        int num;
        cin >> num;
        root = Insert(root,num);
    }
    int number;
    cin >> number;
    PreOrder(root);
    cout << endl;
    if(Search(root,number)) cout << "Found" << endl;
    else cout << "Not Found" << endl;
    return 0;
}