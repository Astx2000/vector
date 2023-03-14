#include <iostream>
#include "vector.hpp"

template <typename T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator++() {
    ++m_Index;
    return *this;
}
template <typename T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator++(int)  {
    Iterator retval = *this;
    ++(*this); 
    return retval;
}
template <typename T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator--() {
    --m_Index;
    return *this;
}
template <typename T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator--(int) {
    Iterator retval += *this;
    --(*this);
    return retval; 
}
template <typename T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator-(const Vector<T>::Iterator& other) const {
    return *this -= other;
}
template <typename T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator+(const Vector<T>::Iterator& other) const {
    return *this += other;
}
template <typename T>
bool Vector<T>::Iterator::operator!=(const Vector<T>::Iterator& other) const {
    return m_Index != other.m_Index;
}
template <typename T>
bool Vector<T>::Iterator::operator==(const Vector<T>::Iterator& other) const {
    return m_Index == other.m_Index;
}
template <typename T>
bool Vector<T>::Iterator::operator<(const Vector<T>::Iterator& other) const {
    return m_Vector < other.m_Vector;
}
template <typename T>
bool Vector<T>::Iterator::operator>(const Vector<T>::Iterator& other) const {
    return m_Vector > other.m_Vector;
}
template <typename T>
const T &Vector<T>::Iterator::operator*() const {
    return m_Vector->operator[](m_Index);
}

template <typename T>
Vector<T>::Vector() {
    m_size = 0;
    m_cap = 5;
    m_buff = new T[m_cap];
}

template <typename T>
Vector<T>::Vector(T in_cap) {
    m_size = 0;
    m_cap = in_cap;
    m_buff = new T[m_cap];
}
template <typename T>
Vector<T>::~Vector() {
    delete[] m_buff;
}


