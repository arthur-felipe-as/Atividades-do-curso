#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int cont, res = -1;
    string texto, palavra;
    getline(cin, texto);
    cin >> palavra;
    for(int i = 0; i < texto.length(); i++){
        
        if(texto.find(palavra, i) >= 0 && texto.find(palavra, i) != texto.npos && texto.find(palavra, i) != res){
            cont++;
            res = texto.find(palavra, i);
            
            

        }
    }
    cout << cont << endl;

    return 0;
}
