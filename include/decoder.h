#ifndef _DECODE_H
#define _DECODE_H
#include "huffman_tree.h"
#include <cstring>
#include <cstdio>
class decoder 
{
    private:
        huffman_tree _tree;
    public:
        void set_tree(huffman_tree & tree);
        const char *decode(const char * code);
};
#endif
