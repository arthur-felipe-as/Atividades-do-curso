/*!
 * This function receives two ranges of values, each individually already sorted.
 * @precondition Each individual half is already sorted.
 * @postcondition The whole range is sorted.
 * @param first the begining of the original range.
 * @param middle the end of the 1st sorted half and the beginning of the 2nd sorted half.
 * @param last address just past the last element of the 2nd half (and the original range).
 * @param comp The comparison function that implements a _strict order_ binary
 * relation among the elements we want to merge.
 */
void merge(value_type* first,
           value_type* middle,
           value_type* last,
           const Compare& comp = std::less<>()) {
  // TODO: Implemente merge aux function.
  // 0: Determinar as dimensões dos sub-vetores.
  value_type size_left = std::distance(first, middle);
  value_type size_right = std::distance(middle, last);
  // 1: Criar vetores left e right
  value_type* left = new value_type[size_left];
  value_type* right = new value_type[size_right];
  // 2: Copiar a primeira metade para left e a segunda metade para right
  std::copy(first, middle, left);
  std::copy(middle, last, right);
  // 3: Fazer o merge entre left e right
  auto destination{first};
  auto l_iter{left};
  auto r_iter{right};
  while(destination != last){
    if(l_iter == &left[size_left]){
       std::copy(r_iter, &right[size_right], destination);
       break;
    }
    if(r_iter == &right[size_right]){
      std::copy(l_iter, &left[size_left], destination);
      break;
    }
    if(comp(*l_iter, *r_iter)){
      *destination = *l_iter;
      l_iter++;
    }
    else{
      *destination = *r_iter;
      r_iter++;
    }
    destination++;
  }
  // 4: Liberar a memória de left e right
  delete[] left;
  delete[] right;
}

void mergesort(value_type* first, value_type* last, const Compare& comp = std::less<>()) {
  auto n = std::distance(first,last);
  if(n <= 1){
    return;
  }
  auto middle{std::next(first, n/2)};
  mergesort(first, middle, comp);
  mergesort(middle, last, comp);
  merge(first, middle,last);
}