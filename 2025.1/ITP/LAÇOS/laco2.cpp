#include <iostream>
using namespace std;
//Dado um número inteiro positivo N e dois números naturais não nulos I
//e J, imprimir em ordem crescente os N primeiros naturais múltiplos de I
//ou de J (ou de ambos).

int main(){
    int N, I , J, C = 1, A = 1;
    cin >> N >> I >> J;
    while (A <= N ){
        if (C%I == 0 or C%J == 0){
            cout << C << endl;
            A++;
        }
        C++;
    }
    return 0;
}
