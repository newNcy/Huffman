#ifndef _DECODER_H
#define _DECODER_H
#include <cstring>
#include <vector>
#include "huffman_tree.h"
#include <map>

using std::map;
using std::vector;
/**
 * 用于计算频率
 */
typedef struct _e
{
    char ch;
    int count;
    struct _e * next;
}e;


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
    rate get_rate(const char *raw);
    huffman_tree get_tree(rate & _r);
    word get_word(huffman_tree & tree);

public:
    encoder();
    const char * encode(const char * raw);
    ~encoder();
};

#endif
