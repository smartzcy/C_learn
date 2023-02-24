while(num != 0){
        k = k * 10 + num % 10;
        num /= 10;
    }
    while(k != 0){
        cout << s[k % 10];
        if(k / 10 == 0) cout << endl;
        else cout << " ";
        k /= 10;
    }