# Binary Search Tree, Graphs, Heaps, Balanced Tree, N-ary Tree, Hash Tables

The different alogorithms will be found in a .dll with .lib and the necessary include files.

This project need to be compiled with -std=c++2a because it uses concepts and a **x86** platform.

# **Binary Search Tree**

The Binary Search Tree is a generic class that can be performed on those types:

    char

    int

    double

    float

    short

    long, long long. In other word, the available types are the **fundamental** types.

This class provides different methods to perform the standard algorithm **bst**:

    insert(value): void. to insert a value into the Tree. This method can catch an exception behind the scene.

    find(value): bool. to find a value. Be aware, this method throw an exception (const char*) if there's no data in the tree.

    remove(value): bool. to delete a value.

    in_order(): void. to get the ordered Tree.


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
