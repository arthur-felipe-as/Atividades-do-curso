#include <iostream>
using namespace std;

int teto(float x){
    for(int i = x-1; i <= x+1; i++){
        if(i-1 < x && x <= i){//Condição que testa se n está dentro do intervalo que define a função teto
            return i;          
        }
    }  
    return 0;
}

int main(){
    float x;
    cin >> x;
    cout << teto(x) << endl;
    return 0;
}