#ifndef VECTORITER_H
#define VECTORITER_H
#include <iostream>

template <typename T>
class Vector {
public:
    class Iterator : public std::iterator<std::random_access_iterator_tag, T>
    {
    public:
        Iterator();
        Iterator(const Vector<T> *vector, int Index);

    public:
        const T& operator*() const;
        Iterator& operator++();
        Iterator& operator++(int);
        Iterator& operator--();
        Iterator& operator--(int);
        Iterator& operator+(const Iterator& other) const;
        Iterator& operator-(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
        bool operator==(const Iterator& other) const;
        bool operator<(const Iterator& other) const;
        bool operator>(const Iterator& other) const;

    private:
        const Vector<T> *m_Vector;
        int m_Index = -1;
    };
public:
    Vector();
    Vector(T);
    ~Vector();
    
public:
    void insert(T,T);

    const T &operator[](int nIndex) const;
    Iterator begin() const;
    Iterator end() const;

private:
    int m_cap;
    int m_size;
    T* m_buff;
};

#endif //VECTORITER_H