/*!
 * @file filter_students.cpp
 * @author Selan
 * @date April 11th, 2022
 *
 * Programa de suporte para exercício preparatório para aula sobre análise
 * empírica.
 *
 * Compilar: g++ -Wall -std=c++11 filter_students.cpp -o filter
 */

#include <iostream>
#include <iterator>

// Alias to the type we are working on.
using value_type = int;

/// Aqui é a função de filtragem que precisa ser implemetnada.
/*!
 * ENTRADA:
 * first_                                    last_
 *   |                                        |
 *   V                                        V
 * +---+---+---+---+---+---+---+---+---+---+
 * | -2| -8| 6 | 7 | -3| 10| 1 | 0 | -3| 7 |
 * +---+---+---+---+---+---+---+---+---+---+
 *
 * SAIDA:
 * first_               last_
 *   |                   |
 *   V                   V
 * +---+---+---+---+---+---+---+---+---+---+
 * | 6 | 7 | 10| 1 | 7 | ? | ? | ? | ? | ? |
 * +---+---+---+---+---+---+---+---+---+---+
 */
value_type *filter(value_type *first, value_type *last) {
    while (first != last){
        if(*first <= 0){
            std::copy(std::next(first),last,first);
            --last;
        }
        else{
            ++first;
        }
    } 
    return last;
} 
value_type *filter2(value_type *first, value_type *last, bool pred(value_type)) {
    auto fast{first};
    auto slow{first};
    while(fast != last){
        if(pred(*fast)){
            std::iter_swap(fast,slow);
            slow++;
        }
        fast++;
    }
    return slow;
}

int main() {
    value_type A[] = {-2, -8, 6, 7, -3, 10, 1, 0, -3, 7};
    size_t len = sizeof(A) / sizeof(value_type);

    // Printing the filtered array.
    std::cout << ">>> Original array  = [ ";
    // std::copy( std::begin(A), std::end(A),  std::ostream_iterator<value_type>(
    // std::cout, " " ) );
    for (auto i(0u); i < len; ++i) { std::cout << A[i] << " "; }
    std::cout << "], Size = " << std::distance(std::begin(A), std::end(A)) << "\n";

    // Filtering
    auto *new_end = filter2(std::begin(A), std::end(A), [](value_type value){return value > 0;});

    // Printing the filtered array.
    std::cout << ">>> FILTERED array  = [ ";
    std::copy(std::begin(A), new_end, std::ostream_iterator<value_type>(std::cout, " "));
    std::cout << "], Size = " << std::distance(std::begin(A), new_end) << "\n";

    return EXIT_SUCCESS;
}
