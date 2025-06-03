int teto(float x){
    int n = 0; 
    bool achou = false;
    do{
        if(n-1 < x && x <= n){//Condição que testa se n está dentro do intervalo que define a função teto
            return n;
            achou = true;
        }
        if(x > 0){
            n++;
        }
        if(x < 0){
            n--;
        }
    } while(achou == false);
    return 0;
}