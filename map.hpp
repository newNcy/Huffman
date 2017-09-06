#ifndef _MAP_H
#define _MAP_H

namespace ncy 
{
    template <typename T,typename R>
    struct _m_e
    {
        T & t;
        R & r;
    };


    template<typename T, typename R>
    class map
    {
        using entry=_m_e<T,R>;
    private:
        _m_e<T,R> * _map;
    public:
        using iterator=entry;
        R & operator [](const T & _t)
        {
            if (_map == 0) {
                _map = new entry;
                _map->t = _t;
                return _map->r;
            }
            entry * p = _map;
            while (p != 0) {
                if (p->t == _t) {
                    return p->r;
                }
                p = p->next;
            }
            p->next = new entry;
            p = p->next;
            p->t = _t;
            return p->r;
        }
    };
}


#endif
