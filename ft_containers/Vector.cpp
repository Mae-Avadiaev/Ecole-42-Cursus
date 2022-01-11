#include "Vector.hpp"

//----------Public methods----------

ft::Vector::Vector() {

}

ft::Vector::Vector(const ft::Vector &other) {

}

ft::Vector::~Vector() {}

ft::Vector& ft::Vector::operator=(const ft::Vector& other) {
    if (*this != &other)
    
    return *this;
}

//----------Private methods----------

void ft::Vector::reAlloc(size_t newCapacity
}