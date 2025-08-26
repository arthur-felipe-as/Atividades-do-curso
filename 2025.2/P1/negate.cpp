#include <iostream>
#include <iterator>
#include <sstream>
#include <array>

void negate(int *first, int *last){
    while(first != last){
        *first *= -1;
        ++first;
    }
}

std::string to_string(int *first, int *last){
    std::ostringstream oss;
    oss << "[ ";
    while(first != last){
        oss << *first;
        if(std::next(first) != last){
            oss << ',';
        }
        oss << ' ';
        ++first;
    }
    oss << "]";
    return oss.str();
}

// int main(){
//     std::array<int, 7> V{1, -2, 4, 20, -84, 0, -5};
//     std::cout << "Original " << to_string(std::begin(V), std::end(V)) << '\n';
//     negate(std::begin(V), std::end(V));
//     std::cout << "Negado " << to_string(std::begin(V), std::end(V)) << '\n';
//     return 0;
// }