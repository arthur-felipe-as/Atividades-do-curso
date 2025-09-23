#include <iostream>
#include <array>
#include <string>
using value_type = int;
template<typename FwrdItr, typename CmpFunc>;


class Fighter{
    public:
    std::string m_name;
    int m_power{500};
    int m_life{50};
    Fighter(std::string n="no name", int p=0, int l=0){
        m_name = n;
        m_power = p;
        m_life = l;
    }
};


template<typename FwrdItr, typename CmpFunc> FwrdItr max_value(FwrdItr first, FwrdItr last, CmpFunc cmp){
    FwrdItr max{first};
    while(first != last){
        if(cmp(*max, *first)){
            max = first;
        }
        first++;
    }
    return max;
}

int main(){
    std::array<Fighter, 3> guilda{
        Fighter{"Aquiles", 300, 200} , 
        Fighter{"Perseu",200, 100},
        Fighter{"Conan", 500, 300},
    };
    constexpr std::array arr{-3, 0, 4, 7 , -5, 2 , 10 ,3};
    std::cout << ">>> Max value is: " <<
        *max_value(arr.cbegin(), arr.cend()) << '\n';


    return 0;
}