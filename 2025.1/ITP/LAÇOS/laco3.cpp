#include <iostream>
using namespace std;
//Dizemos que um número natural é triangular se é o produto de três
//números naturais consecutivos. Por exemplo, 120 é triangular, pois 4 x
//5 x 6 = 120. Dado um número N, imprimir na tela “TRIANGULAR” caso
//seja triangular ou “NÃO TRIANGULAR” caso não seja.
int main(){
    int N, A;
    cin >> N;
    
    A = 1;
    while (A <= N ){
        if (A * (A+1) * (A+2) == N){
            cout << "TRIANGULAR" << endl;
            break;
        }
        
        A++;
    }
    if (A * (A+1) * (A+2) != N){
        cout << "NÃO TRIANGULAR" << endl;
    }




    return 0;
}
