#ifndef _DECODER_H
#define _DECODER_H
#include <cstring>
//#include "vector.h"
#include <vector>
#include "huffman_tree.h"
#include <map>



using std::map;
using std::vector;


/**
 * 霍夫曼编码器
 */
class encoder
{
    using rate = map<char,int>;
    using word = map<char,vector<char> >;

    /* 字符<->出现次数 映射 */
    rate _rate;
    /* 霍夫曼树 */
    huffman_tree _htree;
    /* 字符<->编码 映射 */
    word _word;

    /* 编码缓冲区 */
    vector<char> bitB;

    /* 先序遍历树得到编码 */
    void order_get_word(node * h);

    /* 获取频率 */
    rate get_rate(const char *raw);
    /* 调用get_rate 获取huffman tree */
    huffman_tree get_tree(const char * raw);
    /* 调用order_get_word获取编码映射 */
    word get_word(const char * raw);

public:
    encoder();
    /* 对字符串进行哈夫曼编码 */
    const char * encode(const char * raw);
    huffman_tree & tree();
    ~encoder() = default;
};

#endif
