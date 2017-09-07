#include "encoder.h"


encoder::encoder()
{

}

encoder::rate encoder::get_rate(const char *raw)
{
    for(int i = 0;raw[i] != 0; i++) {
        _rate[raw[i]] ++;
    }
    for(rate::iterator it = _rate.begin(); it !=  _rate.end(); it++) {
        printf("%c[%d] ",it->first,it->second);
    }
    printf("\n");
    fflush(stdout);
    return _rate;
}

int get_min_index(const vector<node *> & forest) 
{
    int minv = forest[0]->w;
    int ndx = 0;
    for(int i = 1 ; i < forest.size();i++) {
        if (forest[i]->w < minv) {
            minv = forest[i]->w;
            ndx = i;
        }
    }
    return ndx;
}


void encoder::order_get_word(node * root) 
{
    if (root->nt == LEAF) {
        printf("%c ",root->c);
        _word[root->c] = bitB;
        for(int i = 0; i < bitB.size(); i ++) {
            _word[root->c][i] = bitB[i];
            printf("%c",bitB[i]);
        }
        printf("\n");
        fflush(stdout);
    }else{
        //printf("%d ",root->w);
        bitB.push_back('0');
        order_get_word(root->left);
        bitB.push_back('1');
        order_get_word(root->right);
    }
    bitB.erase(bitB.begin() + bitB.size() -1);
}

huffman_tree encoder::get_tree(const char * raw)
{
    
    get_rate(raw);
    node * root = nullptr;
    vector<node * > forest;
    for (rate::iterator it = _rate.begin(); it != _rate.end(); it++) {
        node * t= new node;
        t->c = it->first;
        t->w = it->second;
        t->nt = LEAF; 
        forest.push_back(t);
    }
    while (forest.size() > 1) {
        int ndx1 = get_min_index(forest);
        node * min1 = forest[ndx1];
        forest.erase(forest.begin() + ndx1);
        int ndx2 = get_min_index(forest);
        node * min2 = forest[ndx2];
        forest.erase(forest.begin() + ndx2);
        if (min1->nt != BRANCH) { 
            printf("min1[%c] ",min1->c);
        }else {
            printf("min1[B] "); 
        }
        if (min2->nt != BRANCH) { 
            printf("min2[%c]\n",min2->c);
        }else {
            printf("min1[B]\n"); 
        }
        
        node * n = new node;
        n->nt = BRANCH;
        n->w = min1->w + min2->w;
        n->left = min1;
        n->right = min2;
        forest.push_back(n);
        for (int i = 0; i < forest.size(); i ++) {
            if (forest[i]->nt != BRANCH) 
                printf("%c[%d] ",forest[i]->c,forest[i]->w);
            else 
                printf("B_[%d] ",forest[i]->w);
        }
        printf("\n");
    }
    root = forest[0];
    order_get_word(root);
    fflush(stdout);
    //return _htree = root; 
}

encoder::word encoder::get_word(const char *raw)
{
    get_tree(raw);
    for(word::iterator it = _word.begin(); it !=  _word.end(); it++) {
       // printf("%c[%s] ",it->first,it->second);
    }
    return _word;
    //fflush(stdout);
}

const char * encoder::encode(const char * raw)
{
    get_word(raw);
    int i = 0 ; 
    vector<char> res;
    while (raw[i] != 0 ) {
        vector<char>& vt = _word[raw[i]];
        for (int i = 0 ; i < vt.size(); i ++) {
            res.push_back(vt[i]);
            printf("%c",vt[i]);
        }
        i++;
    }
    char * res_v = new char[res.size()];
    for( i = 0; i < res.size() ; i ++) {
        res_v[i] = res[i];
    }
    res_v[i] = 0;
    return res_v;
}

encoder::~encoder()
{}
