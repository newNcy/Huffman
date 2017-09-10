#include "decoder.h"

void decoder::set_tree(huffman_tree & tree)
{
    _tree = tree;
}

const char * decoder::decode(const char * code)
{
    if (_tree == nullptr) {
        printf("未配置解码树 终止...\n");
        return nullptr;
    }
    char * res = new char[strlen(code)];   

    node *  p = _tree;
    int i = 0;
    int j = 0;
    while(code[i] != 0) {
        if (code[i] == '0' ) {
            p = p->left; 
        }else if (code[i] == '1') {
            p = p->right;
        }else {
            printf("%c 不是合法的编码\n",code[i]);
            break;
        }
        if (p->nt == LEAF) {
            res[j++] = p->c;
            //printf("%c",p->c);
            fflush(stdout);
            p = _tree;
        }
        i++;
    }
    res[j] = 0;
    return res;
}
