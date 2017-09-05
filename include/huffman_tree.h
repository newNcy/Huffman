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
    float weight;
    
}node;

/**
 * 霍夫曼树
 */
class huffman_tree
{
private:
    node * _root;
public:

};


#endif

