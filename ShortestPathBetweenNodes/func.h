#include <vector>
#include <set>
#include <iostream>

template <typename Vertex, typename Weight>
   void shortest_path(
      graph<Vertex, Weight> const & g,
      Vertex const source,
      std::map<Vertex, Weight>& min_distance,
      std::map<Vertex, Vertex>& previous)
   {
      auto const n = g.vertex_count();
      auto const verteces = g.verteces();
      min_distance.clear();
      for (auto const & v : verteces)
         min_distance[v] = graph<Vertex, Weight>::Infinity;
      min_distance[source] = 0;
previous.clear();
      std::set<std::pair<Weight, Vertex> > vertex_queue;
      vertex_queue.insert(std::make_pair(min_distance[source], source));
      while (!vertex_queue.empty())
      {
         auto dist = vertex_queue.begin()->first;
         auto u = vertex_queue.begin()->second;
         vertex_queue.erase(std::begin(vertex_queue));
         auto const & neighbors = g.neighbors(u);
         for (auto const & neighbor : neighbors)
         {
            auto v = neighbor.first;
            auto w = neighbor.second;
            auto dist_via_u = dist + w;
            if (dist_via_u < min_distance[v])
            {
               vertex_queue.erase(std::make_pair(min_distance[v], v));
               min_distance[v] = dist_via_u;
               previous[v] = u;
               vertex_queue.insert(std::make_pair(min_distance[v], v));
} 
}
}
 }

template <typename Vertex>
   void build_path(
      std::map<Vertex, Vertex> const & prev, Vertex const v,
      std::vector<Vertex> & result)
   {
      result.push_back(v);
      auto pos = prev.find(v);
      if (pos == std::end(prev)) return;
      build_path(prev, pos->second, result);
   }
   template <typename Vertex>
   std::vector<Vertex> build_path(std::map<Vertex, Vertex> const & prev,
                                  Vertex const v)
   {
      std::vector<Vertex> result;
      build_path(prev, v, result);
      std::reverse(std::begin(result), std::end(result));
      return result;
}
   template <typename Vertex>
   void print_path(std::vector<Vertex> const & path)
   {
      for (size_t i = 0; i < path.size(); ++i)
      {
         std::cout << path[i];
         if (i < path.size() - 1) std::cout << " -> ";
      }
}
