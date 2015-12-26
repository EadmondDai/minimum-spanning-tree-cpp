#include <boost/algorithm/string.hpp>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include "disjointset.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::pair;

using namespace boost;


template <class T>
struct WeightedEdge
{
  pair<T,T> edge;
  float weight;
};


template <class T>
struct WeightedGraph
{
  vector<T> nodes;
  vector< WeightedEdge<T> > edges;
};


WeightedGraph<string> get_input()
{
  WeightedGraph<string> g;

  // next line is the number of vectors
  int num_vectors;
  cin >> num_vectors;

  // get the vectors
  for(int i = 0; i < num_vectors; i++){
    string node;
    cin >> node;
    g.nodes.push_back(node);
  }

  // next line is the number of edges
  int num_edges;
  cin >> num_edges;

  vector <string> tokens;

  // get the edges
  for(int i = 0; i < num_edges; i++){
    string line;
    cin >> line;
    split(tokens, line, is_any_of(" ,"), token_compress_on);

    WeightedEdge<string> weighted_edge;
    weighted_edge.edge.first = tokens[0];
    weighted_edge.edge.second = tokens[1];

    weighted_edge.weight = std::stof(tokens[2]);

    g.edges.push_back(weighted_edge);
  }

  return g;
}


void print_graph( WeightedGraph<string> graph)
{
  cout << "nodes: " << endl;
  for(auto &node : graph.nodes){
    cout << node << " " << endl;
  }
  cout << endl;

  cout << "edges: " << endl;
  for(auto &entry : graph.edges){
    pair<string,string> edge = entry.edge;
    float weight = entry.weight;

    cout << edge.first << " - " << edge.second << ": " << weight << endl;
  }

  cout << endl;
}


vector< WeightedEdge<string> >  kruskals_algorithm( WeightedGraph<string> graph ){
  Disjoint_Set<string> connected;

  for(auto &node : graph.nodes){
    connected.make_set(node);
  }

  sort(graph.edges.begin(), graph.edges.end(),
       [](WeightedEdge<string> a, WeightedEdge<string> b){
	 return a.weight < b.weight;
       });

  vector< WeightedEdge<string> > output;

  for(auto &weighted_edge : graph.edges){
    string u = weighted_edge.edge.first;
    string v = weighted_edge.edge.second;
    if( connected.find(u) != connected.find(v) ){
      output.push_back(weighted_edge);
      connected.do_union(u, v);
    }
  }

  return output;
}


int main ()
{
  WeightedGraph<string> graph = get_input();

  print_graph(graph);

  vector< WeightedEdge<string> > mst = kruskals_algorithm(graph);

  cout << "Minimum spanning tree: " << endl;

  for(auto &weighted_edge : mst){
    cout << weighted_edge.edge.first << " - " << weighted_edge.edge.second << ": " << weighted_edge.weight << endl;
  }

  return 0;
}
