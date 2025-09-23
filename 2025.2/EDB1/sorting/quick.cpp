int *partition(int *first, int *last, int *pivot, Compare comp) {
  auto *fast{first};
  auto *slow{first};
  while(fast != pivot){
    if(comp(*fast, *pivot)){
      std::iter_swap(fast, slow);
      slow++;
    }
    fast++;
  }
  std::iter_swap(slow, pivot);
  return slow; // STUB, modificar...
}

void quicksort(int *first, int *last, Compare cmp) {
  if(std::distance(first, last) <= 1){
    return;
  }
  auto *pivot = partition(first, last, std::prev(last),cmp);
  quicksort(first, pivot, cmp);
  quicksort(std::next(pivot), last, cmp);
}


void median_of_3(int* first, int* last, Compare cmp){
    auto *middle = first+(std::distance(first,std::prev(last))/2);
    if(cmp(*middle, *first)){
        std::iter_swap(middle,first);
    }
    if(cmp(*std::prev(last),*middle)){
        std::iter_swap(std::prev(last), middle);
    }
    if(cmp(*std::prev(last), *first)){
        std::iter_swap(std::prev(last), first);
    }
    std::iter_swap(middle, std::prev(last));
}