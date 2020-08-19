#include <vector>
#include <map>
#include <cmath>
#include <stdexcept>

template <typename Vertex = int, typename Weight = double>
   class graph
   {
   public:
      typedef Vertex                     vertex_type;
      typedef Weight                     weight_type;
      typedef std::pair<Vertex, Weight>  neighbor_type;
      typedef std::vector<neighbor_type> neighbor_list_type;
   public:
      void add_edge(Vertex const source, Vertex const target,
                    Weight const weight, bool const bidirectional = true)
      {
         adjacency_list[source].push_back(std::make_pair(target, weight));
         adjacency_list[target].push_back(std::make_pair(source, weight));
}
size_t vertex_count() const { return adjacency_list.size(); }
      std::vector<Vertex> verteces() const
      {
         std::vector<Vertex> keys;
         for (auto const & kvp : adjacency_list)
            keys.push_back(kvp.first);
         return keys;
}
      neighbor_list_type const & neighbors(Vertex const & v) const
      {
         auto pos = adjacency_list.find(v);
         if (pos == adjacency_list.end())
            throw std::runtime_error("vertex not found");
         return pos->second;
}
      constexpr static Weight Infinity =
                std::numeric_limits<Weight>::infinity();
   private:
      std::map<vertex_type, neighbor_list_type> adjacency_list;
};
