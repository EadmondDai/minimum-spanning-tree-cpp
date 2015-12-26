#include <map>

template <class T>
class Disjoint_Set
{
  /**
   * An abstract data type for disjoint-set data structures.
   * Algorithm: https://en.wikipedia.org/wiki/Disjoint-set_data_structure
   **/
  std::map<T,T> parent;
public:
  void make_set (T x);
  T find (T x);
  void do_union (T x, T y);
};

#include "disjointset.tpp"
