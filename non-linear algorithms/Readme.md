# Binary Search Tree, Graphs, Heaps, Balanced Tree, N-ary Tree, Hash Tables, Divide and Conquer 

The different alogorithms will be found in a .dll with .lib and the necessary include files.

This project need to be compiled with -std=c++2a because it uses concepts and a **x86** platform.

# **Binary Search Tree**

The Binary Search Tree is a generic class that can be performed on those types:

    char

    int

    double

    float

    short

    long, long long. In other word, the available types are the fundamental types.

This class provides different methods to perform the standard algorithm **bst**:

    insert(value): void. to insert a value into the Tree. This method can catch an exception behind the scene.

    find(value): bool. to find a value. Be aware, this method throw an exception (const char*) if there's no data in the tree.

    remove(value): void. to delete a value.

    in_order(): void. to get the ordered Tree.


# **Graphs**

This class is accepting only integral template parameter.

    get edges, the method is: get_vertices(): std::size_t
    
    get the vector which contains all edges: e(): std::vector<Edge<T>>
    
    add_edge(Edge<T>&& e): void. Be aware, this method throw an exception if the edge is out of range

# **Hash Tables**

This class is a generic class that can be performed on those types:

    char

    int

    double

    float

    short

    long, long long

    std::string

**N.B.: this class provides only one ctor which takes the size of the table.**

This class provides different methods to perform the standard algorithm **Hashing**:

You can use 2 methods:

  **1/ close addressing:**
    
    insert_chain(value): bool. inserting in chaining mode.
    
    find_chain(value): bool. finding in chaining mode.
    
    remove_chain(value): bool. deleting a value in chaining mode.

  **2/ open addressing:**
  
   **a/ Linear probe:**
  
    insert_Linear_probing(value): bool. inserting in linear probing mode
    
    find_Linear_probing(value): bool. finding in linear probing mode.
    
    remove_Linear_probing(value): bool. deleting a value in linear probing mode.
    
   **b/ Quadratic probe:**
   
    insert_Quadratic_probing(value): bool. inserting in Quadratic probing mode. //Quadratic mode used to avoid the density.
    
    find_Quadratic_probing(value): bool. finding in Quadratic probing mode.
    
    remove_Quadraticr_probing(value): bool. deleting a value in Quadratic probing mode.
    
# **Bloom Filter:**

In contrast to the Hash Table and BST algorithms, this class is not templatized.

The Bloom Filter offers the following methods:

    find(key): void. it allows you to find a key entered by the user.
    
    insert(key): void. it allows to insert a key.
    
Behind the scene, this algorithm uses a function that allows to choice the 3 values to fill in the vector.

**N.B.: The ctor will throw an std::bad_alloc if the size entered is less than 3.**

# **Kruskall's MST or Disjoint-Set**

This class accepts only integral template parameter.

    add_mst(const T& set): void
    
    find(T const& _val): std::vector<_node>::iterator
    
    union_set(const T& x, const T& y): void

# **Divide and Conquer**

Here we will see the merge sort and quicksort algorithms and why we need both of them. Also we will see the binary search algorithm. Those are function template.


