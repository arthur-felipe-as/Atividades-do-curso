pointer first_smallest(pointer first, const_pointer last, CompareFunc cmp) {
  auto smallest{first};
  while(first != last){
    if(cmp(*first, *smallest)){
      smallest = first;
    }
    first++;
  }
  return smallest;  
}
void selection_sort(pointer first, pointer last, CompareFunc compare_ints) {
  auto fast{first};
  while(fast != last){
    auto smallest{first_smallest(fast, last, compare_ints)};
    std::swap(*smallest, *fast);
    fast++;
  }
}