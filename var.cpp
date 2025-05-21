#include <iostream>
using namespace std;
//Obs1: O campo de defesa do time A é o lado que possui valores negativos. Logo, a posição dos jogadores que estivem no lado de ataque terão valores positivos. 
//O mesmo ocorre com o time B, só que os valores contrários: o campo de defesa possui valores positivos e o de ataque negativos.

//Obs2: Veja que o texto inicial em cada linha possui uma letra (A ou B), seguida de : , seguido de um espaço em branco. Haverá erro se não seguir estritamente este formato.

int main(){
    int timea[10], timeb[10];
    float maiorB, menorA;
    //leitura de dados
    for(int i = 0; i < 10; i++){
        cin >> timea[i];
    }
    
    for(int i = 0; i < 10; i++){
        cin >> timeb[i];
    }

    float posicaoa[10], posicaob[10];
    for(int i = 0; i < 10; i++){
        cin >> posicaoa[i];
    }
    menorA = posicaoa[0];
    for(int i = 0; i < 10; i++){
        cin >> posicaob[i];
    }
    maiorB = posicaob[0];

    //Descobre o maior valor de B
    for(int i = 0; i < 10; i++){
        
        if(maiorB < posicaob[i]){
            
            maiorB = posicaob[i];
            
        }
        
    }
    


    //Impedidos de A
    cout << "A: ";
    bool impedidoA = false;
    for(int i = 0; i < 10; i++){
        if(posicaoa[i] > 0){
        if(maiorB < posicaoa[i]){
            cout << timea[i] << " ";
            impedidoA = true;
        }
    }
    
    }
    if(impedidoA == false){
        cout << "sem impedimentos";
    }
    



    // Descobre qual o menor valor de A
    for(int i = 0; i < 10; i++){
        if(menorA > posicaoa[i]){
            menorA = posicaoa[i];
        }
    }
    
    
    //Impedidos de B
    cout << endl << "B: ";
    bool impedidoB = false;
    for(int i = 0; i < 10; i++){
        if(posicaob[i] < 0){
        if(menorA > posicaob[i]){
            cout << timeb[i] << " ";
            impedidoB = true;
        }
    }
    
    }
    if(impedidoB == false){
        cout << "sem impedimentos";
    }
    
    

    

    





    return 0;
}