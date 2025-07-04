#include <iostream>
using namespace std;

int piso(float x){
    for(int i = x-1; i <= x+1; i++){
            if(i <= x && x < i+1){ //Condição que testa se n está dentro do intervalo que define a função piso
                return i; 
                
            }
        }
        return 0; // Retorno de controle
}

int main(){
    float x;
    cin >> x;
    cout << piso(x) << endl;
    return 0;
}

