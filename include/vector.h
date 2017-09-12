#ifndef _VECTOR_H
#define _VECTOR_H
//#include "def.h"
#include <cstring>
/**
 * 向量
 */

namespace ncy {
template <typename T>
class vector 
{
private:
    T * _buff;
    int _size;
    int _len;
    //friend class iterator;
    /*
    class iterator
    {
    private:
        int ndx;
    public:
        void operator ++()
        {
            ndx ++;
        }
        void operator +(int i)
        {
            ndx +=i;
        }
        T & operator *()
        {
            return _buff[ndx];
        }
    };
    */
public:
    using iterator=T*;
    vector();
    void push_back (const T & _t);
    void operator << (const T & _t);
    T &  operator [] (int index) const ;
    inline const T * value()const ;
    inline int size() const ;
    inline iterator begin();
    inline iterator end();
    void operator = (const vector<T> & v);
    void erase(T * it);

    ~vector();

};

/**
 * 构造函数
 */
template <typename T>
vector<T>::vector()
{
    _buff = NULL;
    _size = 0;
    _len = 0;
}

/**
 * 插入到尾部
 */
template <typename T>
void vector<T>::push_back(const T&_t)
{
    if (_len == _size ) {
        _size += 1;
        T * new_buff = new T[_size];
        memset((char*)new_buff,0,_size);
        for (int i = 0 ; i < _len; i++) {
            new_buff[i] = _buff[i];
        }
        delete [] _buff;
        _buff = new_buff;
    }
    _buff[_len++] = _t;

}

/** 插入到尾部
 */
template <typename T>
void vector<T>::operator <<(const T&_t)
{
    push_back(_t);
}

template<typename T>
inline T &  vector<T>::operator [] (int index)const
{
    return _buff[index];
}
template<typename T>
inline const T *vector<T>::value() const
{
    T * rev = new T[_len];
    memset((char*)rev,0,_len);
    for (int i =0; i < _len; i++) {
        rev[i] = _buff[i];

    }
    return rev;
}

template <typename T>
inline int vector<T>::size() const 
{
    return _len;
}

template<typename T>
void vector<T>::erase(T * it)
{
    for(it;it!=begin()+_len-1;it++) {
        *it = *(it+1);
    }
    _len --;
}

template <typename T>
inline T* vector<T>::begin()
{
    return &_buff[0];
}

template <typename T>
inline T* vector<T>::end()
{
    return &_buff[_len-1];
}

template <typename T>
void vector<T>::operator = (const vector<T> & v)
{
    if (_size != 0) {
        delete [] _buff;
    }
    _size = v.size();
    _len = v.size();
    _buff = new T[v.size()];
    for(int i = 0; i != v.size() ; i++) {
        _buff[i] = v[i];
    }
}
/**
 * 析构函数
 */
template <typename T>
vector<T>::~vector()
{
    if (_size != 0 &&  _buff != nullptr) {
        delete [] _buff;
    }
}
}
#endif
