#include <algorithm>   // copy
#include <array>       // array
#include <functional>  // function<>
#include <iostream>    // cout
#include <iterator>    // distance, ostream_iterator<>

#include <string_view>  // string_view

//=== Aliases
using value_type = int;
using Compare = std::function<bool(value_type, value_type)>;

//=== Function impementation

/// Print out the elements in the requested rante [first;last).
void print(const std::string_view& msg,
           const value_type* first,
           const value_type* last,
           bool new_line = true) {
  std::cout << msg;
  std::cout << "[ ";
  std::copy(first, last, std::ostream_iterator<value_type>(std::cout, " "));
  std::cout << "]";
  if (new_line) {
    std::cout << "\n";
  }
}

void insert(value_type* first, value_type* last,value_type* insert,  Compare cmp = std::less<>()){
    auto key{*insert};
    auto pos{insert};
    while (pos > first && cmp(key, *(pos - 1))) {
        *pos = *(pos - 1);
        --pos;
    }
    *pos = key;
}

void insertsort(value_type* first, value_type* last, Compare cmp = std::less<>()){
    if(std::distance(first,last) <= 1){
        return;
    }
    insertsort(first, std::prev(last), cmp);
    insert(first, std::prev(std::prev(last)), std::prev(last),cmp);
    return;
}

int main() {
//   ===================================================
//   // FIRST PART: Implementing the aux function merge().
//   // ---------------------------------------------------

//   // The array we wish to partition.
constexpr size_t ar_size{ 11 };
std::array<value_type, ar_size> a{ 9, 8, 1, 2, 10, 7, 5, 3, 4, 6, 0 };
auto* middle{ std::next(a.begin(), (a.size() / 2)) };


//   // ===================================================
//   // SECOND PART: Sorting the array.
//   // ---------------------------------------------------




//   // This is the array we wish to sort.
std::array<value_type, ar_size> b{ 9, 8, 1, 2, 10, 7, 5, 3, 4, 6, 0 };
print(">>> Original array befor SORTING: ", b.begin(), b.end());
std::cout << "\n";
//   // Calling mergesort...
insertsort(b.begin(), b.end());
print(">>> Sorted array: ", b.begin(), b.end());
 return 0;
 }