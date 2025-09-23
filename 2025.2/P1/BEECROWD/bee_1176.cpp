#include <iostream>
#include <vector>



int main(){
    int quant{};
    std::cin >> quant;
    std::vector<int> fib ={0,1};
    std::vector<int> seq={};
    for(int i = 0; i < quant; i++){
        int x{};
        std::cin >> x;
        seq.push_back(x);
    }
    for(const int i : seq){
        for(int j = 2; j < i; j++){
            int prox{};
            prox = fib[j-2] + fib[j-1];
            fib.push_back(prox);  
        }
        std::cout << "Fib(" << i <<") = " << fib[i] << std::endl;

    }
   
    
    return 0;
}