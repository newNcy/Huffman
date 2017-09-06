#include "encoder.h"


encoder::encoder()
{

}

encoder::rate encoder::get_rate(const char *raw)
{
    for(int i = 0;raw[i] != 0; i++) {
        _rate[raw[i]] ++;
    }
    for(rate::iterator it = _rate.begin(); it !=  _rate.end(); it++) {
        printf("%c[%d] ",it->first,it->second);
    }
    printf("\n");
    fflush(stdout);
    return _rate;
}

const char * encoder::encode(const char * raw)
{
    get_rate(raw);
    get_tree(_rate);
    return raw;     
}

encoder::~encoder()
{}
