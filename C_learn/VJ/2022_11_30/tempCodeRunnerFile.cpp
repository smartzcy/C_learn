
int main(){
    int n;
    vector<int> vec;
    cin >> n;
    int num1[100000] , num2[100000] = {0};
    for(int i = 0 ; i < n ; i++){
        cin >> num1[i];
        vec.push_back(num1[i]);
    }