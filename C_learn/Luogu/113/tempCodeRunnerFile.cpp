
    cin >> N;
    vector<int> vec;
    vec.push_back(1);
    for(int i = 2 ; i <= N;i++){
        int k , p;
        cin >> k >> p;
        vector<int>::iterator it = find(vec.begin(), vec.end(), k);
        if(p == 1) it++;
        vec.insert(it , i);
    }
    cin >> N;
    for(int i = 0 ; i < N; i++){
        int num;
        cin >> num;
        vector<int>::iterator it = find(vec.begin(), vec.end() , num);
        vec.erase(it);
    }
    for(auto i : vec) cout << i << " ";
}