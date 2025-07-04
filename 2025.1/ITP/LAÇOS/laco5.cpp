#include <iostream>
using namespace std;
//Dado um valor inteiro N e uma sequência de N valores inteiros,
//imprimir a média dos valores da sequência


int main(){
    int n, soma = 0, aux = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
         cin >> aux;
         soma += aux;
    }
    cout << soma/n << endl;



    return 0;
}
