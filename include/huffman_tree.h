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

//using huffman_tree = node *;
typedef node* nodep;

class huffman_tree 
{

    node * _tree;
    node * copy(node * root)
    {
        node * n = new node;
        n->c = root->c;
        n->nt = root->nt;
        if (root->nt != LEAF) {
            n->left = copy(root->left);
            n->right = copy(root->right);
        }
        return n;
    }
public:
    huffman_tree(node * root)
    {
       _tree = copy(root); 
    }
    void operator = (const huffman_tree & c)
    {
        _tree = copy(c._tree);
    }
    nodep  operator nodep()
    {
        return copy(_tree);
    }
};

#endif

