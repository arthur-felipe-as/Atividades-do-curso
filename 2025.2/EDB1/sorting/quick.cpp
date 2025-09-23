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