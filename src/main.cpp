#include <cstdio>
#include "huffman_tree.h"
//#include <sstream>
//#include "encoder.h"
//#include "decoder.h"
//#include "vector.h"
/**
 * 用于计算频率
 */
//using std::stringstream;


struct byte
{
};


int memset (char * mem, int v, int size)
{
    for (int i = 0; i < size-1; i ++) {
        mem[i] = v;
    }
}
int * get_rate(const char * filename)
{
    int * rate = new int[257];
    memset((char*)rate,0,257*sizeof(int));
    FILE * fp = fopen(filename,"rb");
    if (fp == NULL) return rate;
    char ch = 0;
    while(1 ){
        ch = fgetc(fp);
        if (feof(fp)) break;
        rate[(unsigned char)ch] ++;
        printf("%c",ch);
    }

    fclose(fp);
    return rate;
}

node * get_tree(int * rate)
{
    node  *forest[257] = {NULL};
    int fs = 0;
   // memset((char*)forest,0,sizeof(node)*257);
    for (int i = 0 ; i < 257; i ++) {
        if (rate[i] != 0) {
            forest[fs] = new node;
            forest[fs]->c = i;
            forest[fs]->nt = LEAF;
            forest[fs]->w = rate[i];
            forest[fs]->left = forest[fs]->right = NULL;
            fs ++;
            printf("%c[%d] ",i,rate[i]);
        }
    }

    printf("\n");
    fflush(stdout);
    while (fs > 1) {
        /* 将最小的放到最后 */
        for (int i = 0 ; i < fs; i++) {
            if (forest[i]->w < forest[fs-1]->w) {
                node * t = forest[i];
                forest[i] = forest[fs-1];
                forest[fs-1] = t;
            }
        }
        
        for (int i = 0 ; i < fs-1; i++) {
            if (forest[i]->w < forest[fs-2]->w) {
                node * t = forest[i];
                forest[i] = forest[fs-2];
                forest[fs-2] = t;
            }
        }

        node * new_tree = new node;
        new_tree->w = forest[fs-1]->w + forest[fs-2]->w;
        new_tree->nt = BRANCH;
        new_tree->left = forest[fs-1];
        forest[fs-1]->parent = new_tree;
        new_tree->right = forest[fs-2];
        forest[fs-2]->parent = new_tree;
        fs --;
        forest[fs-1] = new_tree;
    } 
    return forest[0];
}

char * word[257] = {NULL};
char wbit[100] = {0};
int wp = 0;
void tree(node *root)
{

    if (root == NULL) return;
    printf("%c[%d] ",root->c,root->w);
    if (root->nt != LEAF) {
        wbit[wp++] = '0';
        tree(root->left);
        wbit[wp++] = '1';
        tree(root->right);
    }else {
        word[root->c] = new char[wp];
        int i = 0;
        for ( i = 0 ; i < wp; i ++) {
            word[root->c][i] = wbit[i];
        }
        word[root->c][i] = 0;
        printf(" %s\n",word[root->c]);
    }
    wp --;
}



int get_height_of_tree(node * root)
{
    if (root->nt == LEAF) return 1;
    int ll = get_height_of_tree(root->left);
    int rl = get_height_of_tree(root->right);
    if (ll > rl ) {
        return ll+1;
    }else {
        return rl+1;
    }
}

struct nl
{
    node * n;
    struct ls * next;
};


int llen(nl * s,nl * e)
{
    if (s == e) return 1;
    else return 1+p_sub(s->next,e);
}

bool check_all_null(nl * s,nl * e)
{
    if (s->n != NULL) return false;
    if (s == e && s->n == NULL) return true;;
}

void p_tree(node *root)
{
    int  h = get_height_of_tree(root);
    printf("%d\n",h);
    nl * s,*e;
    s = e = root;
    while (!check_all_null(s,e)) {
        int nowl = llen(s,e);
        for (int i = 0 ; i < nowl; i ++) {
            for (int j = 0 ; j < h*2-1; j ++) {

            }
        }
    }
}

int main (int argc, char *argv[])
{
    int * rate = get_rate(argv[1]);
    node * t = get_tree(rate);
    p_tree(t);
    tree(t);
    //huffman_tree ht (t);
}
