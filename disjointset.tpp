template <class T> void Disjoint_Set<T>::make_set(T x)
{
  /**
   * Add an entry, it initially occupies its own set.
   **/
  parent[x] = x;
}

template <class T> T Disjoint_Set<T>::find(T x)
{
  /**
   * Finds the root node of the set that x belongs to.
   **/
  T p = parent[x];
  return p == x ? x : find(p);
}

template <class T> void Disjoint_Set<T>::do_union(T x, T y)
{
  /**
   * Make a new set, the union of the sets of x and y.
   **/
  T p_x = parent[x];
  T p_y = parent[y];

  parent[p_x] = p_y;
}
