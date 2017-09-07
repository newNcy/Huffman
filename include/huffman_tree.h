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
    int w;
    node_type nt;
    char c;
    struct _node *left;
    struct _node * right;
}node;

/**
 * 霍夫曼树
 */

using huffman_tree = node *;


#endif

