#include <iostream>
#include <array>
#include <iterator>
using value_type = int;

value_type *bsearch(value_type *first, value_type *last, value_type value) {
    std::cout << "nova iteracao" << std::endl;
  if(std::distance(first,last) == 0){
    std::cout << "acabou/nao existe" << std::endl;
    std::cout << *last << std::endl;
    return last;
  }
  value_type *middle = first+(std::distance(first,last-1)/2);
  if(*middle == value){
    std::cout << "acabou" << std::endl; 
    return middle;
  }
  if(value < *middle){
    std::cout << *middle << " e maior que " << value << std::endl;
    return bsearch(first, middle, value);
  }
  if(value > *middle){
    std::cout << *middle << " e menor que " << value << std::endl;
    return bsearch(middle+1, last, value);
  }

  return last; 
}


int main(){
    //Esses são os dois testes que estão dando errado na busca binária
    //O problema ta sendo que como ele vai procurando um numero menor, ele vai atualizando o valor last que vai ser retornado quando não encontra um termo, vou deixar pra resolver
    //amanhã na aula
    std::array<value_type, 7> arr1{1, 2, 3, 4, 5, 6, 7};

    auto target{-4};
    auto result = bsearch(arr1.begin(), arr1.end(), target);
    std::cout << *result << " x " << *arr1.end() << std::endl;


 std::array<value_type, 6> arr2{1, 3, 5, 7, 9, 11};

    for (auto i{2}; i < 11; i += 2) {
      auto result = bsearch(arr2.begin(), arr2.end(), i);
       std::cout << *result << " x " << *arr2.end() << std::endl;
    }

    return 0;
}

