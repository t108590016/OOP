using namespace std;
#ifndef BUBBLESORT
#define BUBBLESORT
template <class T, class C>
void bubbleSort(T begin, T end, C comp){
  int len = end - begin;
  //COMPARE comp(RandomAccessIterator a, RandomAccessIterator b);
  for(int i = 0 ; i < len - 1 ; i++){
    for(int j = i + 1 ; j < len ; j++){
      if(comp(*(begin+i), *(begin+j))){
        swap(*(begin+i), *(begin+j));
      }
    }
  }

}
#endif
