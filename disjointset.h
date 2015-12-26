#include <map>

using std::map;

template <class T>
class Disjoint_Set
{
  map<T,T> parent;
public:
  void make_set (T x);
  T find (T x);
  void do_union (T x, T y);
};

#include "disjointset.tpp"
