#include <vector>

using std::vector;

template <class T>
struct WeightedEdge
{
  T first, second;
  float weight;
};


template <class T>
struct WeightedGraph
{
  vector<T> nodes;
  vector< WeightedEdge<T> > edges;
};
