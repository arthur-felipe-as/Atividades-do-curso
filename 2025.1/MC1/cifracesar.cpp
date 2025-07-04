#include <iostream>
#include <cstring>
using namespace std;


string cesar(string str, int des){
    for(int i = 0; i < str.length(); i++){
        if(str[i] !=  ' ' ){
        str[i] += des - 13; //13 é 'A' resto de 26
        str[i] = str[i]%26 + 'A';
       
    }
    }        
    return str;
}

int main(){
    string str;
    int des;
    getline(cin, str);
    cin >> des;
    cout << cesar(str, des) << endl;
    return 0;
}