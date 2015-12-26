template <class T> void Disjoint_Set<T>::make_set(T x)
{
  parent[x] = x;
}

template <class T> T Disjoint_Set<T>::find(T x)
{
  T p = parent[x];
  return p == x ? x : find(p);
}

template <class T> void Disjoint_Set<T>::do_union(T x, T y)
{
  T p_x = parent[x];
  T p_y = parent[y];

  parent[p_x] = p_y;
}
