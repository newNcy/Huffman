#include "map.hpp"
#include "vector.h"

template<typename T,typename R>
struct _mnode 
{
    T first;
    R second;
};

template<typename T,typename R>
class map
{
    private:
        using entry=_mnode<T,R>;
        vector<entry> _entry;
        int _size;
    public:
        map()
        {
            _size = 0;
        }

        R & operator[](const T & _t)
        {
            for(int i = 0 ; i < _entry.size(); i++) {
                if (_entry[i].first == _t) {
                    return _entry[i].second;
                }
            }
            entry e;
            e.first = _t;
            _entry<<e;
            return _entry[_entry.size() - 1].second;
        }
};

#include <cstdio>
int main ()
{
    map<char,int> m;
    vector <char> v;
    v<<'a'<<'b'<<'c';
    m['c'] = 1;
    m['b'] = 2;
    m['d'] = 3;
    for (vector<char>::iterator it = v.begin(); it != v.end(); it ++) {
        printf("%c ",*it);
    }
    printf("[%d]\n",m['d']);
    fflush(stdout);
}

