#include <iostream>
#include <cstring>
int main(){
    std::string frase;
    std::getline(std::cin, frase);
    while (frase[0] != '*')
    {
       frase[0] = toupper(frase[0]);
       bool nova_palavra = false;
       bool deu_certo = true;
       for(char i:frase){
        if(nova_palavra){
            if(frase[0] != toupper(i)){
                std::cout << "N\n";
                deu_certo = false;
                break;
            }
            nova_palavra = false;
        }
        if(i == ' '){
            nova_palavra = true;
            continue;
        }
       }
       if(deu_certo){
        std::cout << "Y\n";
       }
       
       std::getline(std::cin,frase);
    }
    
}