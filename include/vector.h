#ifndef _VECTOR_H
#define _VECTOR_H
//#include "def.h"
#include <cstring>
/**
 * 向量
 */

template <typename T>
class vector 
{
private:
    T * _buff;
    int _size;
    int _len;
public:
    vector();
    void push_back (const T & _t);
    void operator << (const T & _t);
    T &  operator [] (int index);
    const T * value()const ;

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
const T *vector<T>::value() const
{
    T * rev = new T[_len];
    memset((char*)rev,0,_len);
    for (int i =0; i < _len; i++) {
        rev[i] = _buff[i];

    }
    return rev;
}

/**
 * 析构函数
 */
template <typename T>
vector<T>::~vector()
{
    if (_size != 0) {
        delete [] _buff;
    }
}

#endif
