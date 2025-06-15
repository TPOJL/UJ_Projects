#ifndef SPARSEARRAY_H
#define SPARSEARRAY_H

#include <iostream>
#include <map>
#include <vector>
#include <stdexcept>
using namespace std;


template<class V, unsigned D>
class SparseArray {
public:
    SparseArray() {}
    SparseArray(const SparseArray& other) : elements(other.elements) {}


    class Index {
    private:
        vector <unsigned> data;
        size_t next_pos;

    public:
        Index() : data(D, 0), next_pos(0) {}
        unsigned& operator [] (size_t i) {
              if (i >= D) throw out_of_range("error");
            return data[i];
        }

        const unsigned& operator [] (size_t i) const {
            if (i >= D) throw out_of_range("error");
          return data[i];
        }

        bool operator < (const Index& other) const {
             return data < other.data;
        }

        friend ostream& operator << (ostream& os, const Index& idx) {
            os << "{";

            for (size_t i = 0; i < D; ++i) {
                if (i > 0) {
                   os << ",";
                }
                os << idx.data[i];
            }

            os << "}";
            return os;
        }

        Index& operator = (unsigned value) {
            data[0] = value;
            next_pos = 1;
            return *this;
        }

        Index& operator , (unsigned value) {
            if (next_pos < D) {
                data[next_pos++] = value;
            }
            return *this;
        }
    };


    class reference {
    public:
        reference(SparseArray& arr, const Index& idx) : array(arr), index(idx) {}
        operator V() const {
            auto it = array.elements.find(index);
            if (it != array.elements.end()) {
                return it -> second;
            }
            return V();
        }

        reference& operator = (const V& value) {
            if (value == V()) {
                array.elements.erase(index);
            } else {
                array.elements[index] = value;
            }

            return *this;
        }

    private:
        SparseArray& array;
        Index index;
    };


    class const_reference {
    public:
        const_reference(const SparseArray& arr, const Index& idx) : array(arr), index_(idx) {}
        operator V() const {
            auto it = array.elements.find(index_);
            if (it != array.elements.end()) {
                return it -> second;
            }

            return V();
        }

    private:
        const SparseArray& array;
        Index index_;
    };


    class iterator {
    public:
        using Iterator = typename map<Index, V>::iterator;
        iterator(Iterator it, SparseArray* arr) : it_(it), array_(arr) {}

        iterator& operator ++ () {
            ++it_;
            return *this;
        }

        iterator operator ++ (int) {
            iterator temp = *this;
            ++(*this);
            return temp;
        }

        reference operator * () {
            return reference(*array_, it_ -> first);
        }

        bool operator != (const iterator& other) const {
            return it_ != other.it_;
        }

        Index key() const {
            return it_ -> first;
        }

        V value() const {
            return it_ -> second;
        }

    private:
        Iterator it_;
        SparseArray* array_;
    };


    class const_iterator {
    public:
        using internal_iterator = typename map<Index, V>::const_iterator;
        const_iterator(internal_iterator it, const SparseArray* arr) : it_(it), array_(arr) {}

        const_iterator& operator ++ () {
            ++it_;
            return *this;
        }

        const_iterator operator ++ (int) {
            const_iterator temp = *this;
            ++(*this);
            return temp;
        }

        const V operator * () const {
            return it_ -> second;
        }

        bool operator != (const const_iterator& other) const {
            return it_ != other.it_;
        }

        Index key() const {
            return it_ -> first;
        }

        V value() const {
            return it_ -> second;
        }

    private:
        internal_iterator it_;
        const SparseArray* array_;
    };


    reference operator [] (const Index& index) {
        return reference(*this, index);
    }

    const_reference operator [] (const Index& index) const {
        auto it = elements.find(index);
        if (it != elements.end()) {
            return it->second;
        }
        return const_reference(*this, index);
    }



    iterator begin() {
        return iterator(elements.begin(), this);
    }

    iterator end() {
        return iterator(elements.end(), this);
    }

    const_iterator begin() const {
        return const_iterator(elements.cbegin(), this);
    }

    const_iterator end() const {
        return const_iterator(elements.end(), this);
    }

    unsigned size() const {
        return elements.size();
    }

private:
    map<Index, V> elements;
};

#endif
