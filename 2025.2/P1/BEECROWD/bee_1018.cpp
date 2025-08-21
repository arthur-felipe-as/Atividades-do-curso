#include <iostream>
#include <vector>

int main(){
    std::vector<int> notas = {100, 50, 20, 10, 5, 2, 1};
    int valor{};
    std::cin >> valor;
    std::cout << valor << '\n';
    for(const int &i : notas){
      std::cout << valor/i << " nota(s) de R$ " << i << ",00\n";
      valor %= i;
    }

    return 0;
}