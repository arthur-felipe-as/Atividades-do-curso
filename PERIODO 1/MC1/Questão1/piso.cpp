int piso(float x){
    int n = 0; //Número inteiro que será dado como a resposta
    bool achou = false; //Variável booleana de controle do laço
        
        do{
            if(n <= x && x < n+1){ //Condição que testa se n está dentro do intervalo que define a função piso
                return n; 
                achou = true;
            }
            if(x > 0){ //Se o número de entrada for positivo, passa para o próximo positivo
            n++;
            }
            else if(x < 0){ //Se o número de entrada for negativo, passa para o próximo negativo
                n--;
            }
        }while(achou == false);
        return 0; // Retorno de controle()
}
