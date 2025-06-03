#include <iostream>
using namespace std;
int div_1(int num,int den){
    bool parou = true;
    int i = 0;
    int q = 0; //Valor aleatorio pra facilitar testes (Caso não declarado o valor assumido será o do teste anterior)
    do{
        parou = false;
       if(num > 0){ 
          if(i*den <= num){
            parou = true;
            q = i;
            (den > 0) ? i++ : i--; //Aumenta o quociente a ser testado, caso o denominador for positivo
                                   //Diminui caso o denominador for negativo, pois assim estará testando os 

           }
           if(num-q*den < 0 && parou == false){
            (q > 0) ? q++ : q--;

          }
           
        }
        if(num < 0){
          if(i*den >= num){ // Como o numerador é negativo, uma 
            parou = true;
            q = i;
            (den < 0) ? i++ : i--;
          }
          if(num-q*den < 0 && parou == false){
            (q > 0) ? q++ : q--;

          }
        }
        

    }while(parou == true);
    
    return q;
}