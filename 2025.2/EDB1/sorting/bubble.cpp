void bubble_sort(pointer first, pointer last, CompareFunc compare_ints) {
  auto biggest{first};
  bool swapped = true;
  while(swapped){
  biggest = first;
  swapped = false;
    while(biggest+1 != last){
      if(compare_ints(*(std::next(biggest)), *biggest)){
        std::iter_swap(biggest, std::next(biggest));
        swapped = true;
      }
      else{
        biggest++;
      }
    }
  }
}