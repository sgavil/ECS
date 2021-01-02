#pragma once
#include <vector>
#include <stdint.h>
#include "data_types.hpp"

namespace ecg {

template <typename T>
class sparse_set
{
public:
    sparse_set(){
        reserve(50);
    }

    void reserve(size_t val){
        if(val > capacity){
            sparse.resize(val,0);
            dense.resize(val,T());
            capacity = val;
        }
    }
    void insert(const T& elem){
        if(!exists(elem.id)){

            if (elem.id >= capacity)
                reserve(elem.id + 1);

            dense[size] = elem;
            sparse[elem.id] = size;
            ++size;
        }

    }
    bool exists(EntityID val){
        return val < capacity &&
                sparse[val] < size &&
                dense[sparse[val]].id == val;
    }
    void erase(const T& elem){
        if(exists(elem.id)){
            dense[sparse[elem.id]] = dense[size - 1];
            sparse[dense[size - 1].id] = sparse[elem.id];
            --size;
        }
    }

private:
    std::vector<uint64_t> sparse;
    std::vector<T> dense;

    size_t capacity{0};
    size_t size{0};
};

}
