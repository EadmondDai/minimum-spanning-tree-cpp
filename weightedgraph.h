#include <vector>

template <class T>
struct WeightedEdge
{
  T first, second;
  float weight;
};


template <class T>
struct WeightedGraph
{
  std::vector<T> nodes;
  std::vector< WeightedEdge<T> > edges;
};
