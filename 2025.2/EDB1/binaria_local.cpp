#include <iostream>
#include <iterator>
#include <array>

int* min_local(int *first, int *last){
    auto middle = first + std::distance(first, last);
    auto new_first{first};
    auto new_last{last};
    while(new_first < new_last){
        if(middle+1 < last && middle-1 >= first){
            if(*middle < *(middle+1) && *middle < *(middle-1)){
                return middle;
            }
            else if(*middle > *(middle+1)){
                new_first = middle+1;
            }
            else if(*middle > *(middle-1)){
                new_last = middle;
            }
        }
        middle = first + std::distance(new_first, new_last);
    }

    return first;
}

int main(){
    int a[4] = {1,2,3,4};
    int *result = min_local(&a[0], &a[4]);
    std::cout << *(&a[0] + std::distance(&a[0],result)) << std::endl;
}