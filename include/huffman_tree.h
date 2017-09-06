#ifndef _HUFFMAN_TREE_H
#define _HUFFMAN_TREE_H

/**
 * 节点类型
 */
enum node_type
{
    LEAF,
    BRANCH
};

/**
 * 节点
 */
typedef struct _node
{
    int weight;
    node_type nt;
    char c;
}node;

/**
 * 霍夫曼树
 */

using huffman_tree = node;


#endif

