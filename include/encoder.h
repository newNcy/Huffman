#ifndef _DECODER_H
#define _DECODER_H
#include "huffman_tree.h"

/**
 * 霍夫曼编码器
 */
class encoder
{
    huffman_tree _htree;
    void get_code_word(char *raw);
public:
    encoder();
    const char * encode(char * raw);
    ~encoder();
};

#endif
