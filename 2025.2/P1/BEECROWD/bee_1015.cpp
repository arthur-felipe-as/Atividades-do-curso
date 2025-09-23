#include <iostream>
#include <iomanip>
#include <cmath>

struct Ponto{
    double x,y;
};

float distancia(Ponto p1, Ponto p2){
    return sqrt(pow(2,(p2.x - p1.x)) + pow(2, (p2.y - p1.y)));
}


int main(){
    
    Ponto p1;
    Ponto p2;
    std::cin >> p1.x >> p1.y >> p2.x >> p2.y;
    std::cout << std::fixed << std::setprecision(4) << distancia(p1,p2) << '\n';


    return 0;    
}