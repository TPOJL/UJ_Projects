# Sparse Multidimensional Array

**Language**: C++

## Problem Statement

Implement a templated data structure representing a sparse multidimensional array. The array should support any number of dimensions specified at compile time and store only non-default values to save memory.

## Interface

The class must have the following interface:

```cpp
template<class V, unsigned D>
class SparseArray {
public:
    // Types to define
    typedef std::array<unsigned, D> Index;
    typedef V& reference;
    typedef const V& const_reference;
    typedef std::pair<const Index, V> value_type;
    typedef typename std::map<Index, V>::iterator iterator;
    typedef typename std::map<Index, V>::const_iterator const_iterator;

    // Constructors
    SparseArray();
    SparseArray(const SparseArray& other);
    SparseArray& operator=(const SparseArray& other);

    // Element access
    reference operator[](const Index& idx);
    const_reference operator[](const Index& idx) const;

    // Iterators
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

    // Size
    unsigned size() const;
};
```
Description

V: the type of the stored values.

D: the number of dimensions (a compile-time constant).

Index: an alias for std::array<unsigned, D>, representing coordinates in the array.

Only non-default values should be stored internally (sparsity).

Accessing a missing element with non-const operator[] should insert a default-constructed value.

Accessing a missing element with const operator[] should not insert anything, but should throw or handle appropriately.

Behavior

The structure should behave like a multidimensional map.

Iterators should allow traversal over all stored (non-default) entries.

size() should return the number of stored elements.
