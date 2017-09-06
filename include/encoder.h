#ifndef _DECODER_H
#define _DECODER_H
#include "vector.h"
#include "huffman_tree.h"
#include <map>

using std::map;
/**
 * 霍夫曼编码器
 */
class encoder
{
    using rate = map<char,int>;
    using word = map<char,vector<char> >;
    rate _rate;
    huffman_tree _htree;
    word _word;
    rate get_rate(char *raw);
    huffman_tree get_tree(rate & _r);
    word get_word(huffman_tree & tree);

public:
    encoder();
    const char * encode(char * raw);
    ~encoder();
};

#endif
