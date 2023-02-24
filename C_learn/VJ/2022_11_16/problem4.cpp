#include<iostream>
#include<string>
using namespace std;
int main(){
    int T;
    cin >> T;
    string str[] = {"C" , "C#" , "D" , "D#" , "E" , "F" , "F#" , "G" , "G#" , "A" , "A#" , "B"};
    while(T--){
        string a , b , c;
        cin >> a >> b >> c;
        int x , y , z;
        for(int i = 0 ; i < 12;i++){
            if(str[i] == a) x = i;
            if(str[i] == b) y = i;
            if(str[i] == c) z = i;
        }
        if(x > y) y += 12;
        if(y > z) z += 12;
        if(y > z) z += 12;
        if(y - x == 4 && z - y == 3) cout << "Major triad" << endl;
        else if(y - x == 3 && z - y == 4) cout << "Minor triad" << endl;
        else cout << "Dissonance" << endl;
    }
}