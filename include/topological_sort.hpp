/**
 * @file topological_sort.hpp
 * @author Sofya Sergeeva
 *
 * Реализация топологической сортировки.
 */

#ifndef INCLUDE_TOPOLOGICAL_SORT_HPP_
#define INCLUDE_TOPOLOGICAL_SORT_HPP_

#include <algorithm>
#include <unordered_map>
#include <vector>
#include <graph.hpp>

#define Edge std::pair<size_t, size_t>


template<class Graph>
void dfs(const Graph &graph,
         std::unordered_map<size_t, bool> *used,
         size_t root, size_t dest
         std::vector<Edge> *res) {
  (*used)[root] = true;
  for (size_t way : graph.Edges(root)) {
    if (!(*used)[way]) {
      dfs(graph, used,root, way, res);
    }
  }
  if (way > root) {
          (*res).push_back({root, way});
        } else {
          (*res).push_back({way, root});
        }
         
}

template<class Graph>
std::vector<Edge> TopologicalSort(const Graph &graph) {
  /**
   * @brief Алгоритм топологической сортировки.
   *
   * @param graph Граф.
   *
   * На вход подаётся ссылка на объект типа graph::Graph, описанный в файле:
   * @sa graph.cpp
   * Алгоритм возвращает отсортированный список вершин в виде пар:
   * (id одной вершины, id второй вершины).
  */
  std::unordered_map<size_t, bool> used;
  std::vector<Edge> res;
  for (auto vert : graph.Vertices()) 
    used[vert] = false;
  res.clear();
  for (auto vert : graph.Vertices()) {
    if (!used[vert]) {
      dfs(graph, &used, vert, &res);
    }
  }
  reverse (res.begin(), res.end());
  return res;
}

#endif  // INCLUDE_BRIDGE_SEARCH_HPP_