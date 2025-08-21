#include <iostream>
#include <vector>



int main(){
    int quant{};
    std::cin >> quant;
    std::vector<int> fib ={0,1};
    std::vector<int> seq={};
    for(int i = 0; i < quant; i++){
        std::cin >> seq[i];
    }
    for(int j:seq){
        std::cout << j << std::endl;
    }

    
    return 0;
}