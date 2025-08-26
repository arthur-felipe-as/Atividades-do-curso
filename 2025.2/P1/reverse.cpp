#include "negate.cpp"

void reverse(int *first, int *last){
    while(first < last){
        int temp = *first;
        *first = *(last-1);
        *(last-1) = temp;
        ++first;
        --last;
    }
}

int main(){
    std::array<int, 7> V{1, -2, 4, 20, -84, 0, -5};
    std::cout << "Original " << to_string(std::begin(V), std::end(V)) << '\n';
    reverse(std::begin(V), std::end(V));
    std::cout << "Revertido " << to_string(std::begin(V), std::end(V)) << '\n';
    return 0;
}