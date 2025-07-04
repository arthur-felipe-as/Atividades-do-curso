#include <iostream>
using namespace std;

void intervalo_primos(int inicio, int final){
    int num_divisores = 0; 
    for (int i = inicio; i <= final; i++){
        num_divisores = 0;
        
    for (int j = 1; j <= i; j++){
        //conta a quantidade de divisores
        if (i%j == 0){
            num_divisores++;
        }  
    }
    //se tiver dois divisores, é primo e manda pra saída
    if (num_divisores == 2){
        cout << i << " ";
    }
    }
    cout << endl;   
}

int main(){
    int inicio, final;
    cin >> inicio >> final;
    intervalo_primos(inicio, final);
    return 0;
}

