#include <iostream>
using namespace std;
//Dado um valor positivo N e uma sequência de N inteiros, imprimir
//quantos números da sequência são positivos e quantos são
//não-positivos (um número é não-positivo se é negativo ou se é igual a
//0)
int main(){
    int n, seq, pos = 0, neg = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> seq;
        if (seq > 0 ){
            pos++;
        }
        else{
            neg++;
        }


    }
    cout << "Tem se "  << pos <<" positivos e " << neg << " não positivos" << endl;

    
    return 0;
}
