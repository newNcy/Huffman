#include <cstdio>
#include "huffman_tree.h"
#include <string.h>
#include <errno.h>

#define BYTE_MAX 255
#define RATE_TYPE int
#define RATE_SIZE (sizeof(RATE_TYPE))
//#include "encoder.h"
//#include "decoder.h"
//#include "vector.h"
/**
 * 用于计算频率
 */
//using std::stringstream;






bool check_visable(char c)
{
    if (c >31 && c< 127)
        return true;
    return false;
}
int * get_rate(const char * filename)
{
    RATE_TYPE * rate = new RATE_TYPE[BYTE_MAX+1];
    memset((char*)rate,0,(BYTE_MAX+1)*RATE_SIZE);
    FILE * fp = fopen(filename,"rb");
    if (fp == NULL) return rate;
    char ch = 0;
    while(1 ){
        ch = fgetc(fp);
        if (feof(fp)) break;
        rate[(unsigned char)ch] ++;
    }

    printf("\n");
    fclose(fp);
    return rate;
}

node * get_tree(RATE_TYPE * rate)
{
    node  *forest[BYTE_MAX+1] = {NULL};
    int fs = 0;
   // memset((char*)forest,0,sizeof(node)*257);
   printf("字节频率统计:\n");
    for (int i = 0 ; i < BYTE_MAX+1; i ++) {
        if (rate[i] != 0) {
            forest[fs] = new node;
            forest[fs]->c = i;
            forest[fs]->nt = LEAF;
            forest[fs]->w = rate[i];
            forest[fs]->left = forest[fs]->right = NULL;
            fs ++;
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


char * word[BYTE_MAX+1] = {NULL};
char wbit[100] = {0};
int wp = 0;
void recur_dict(node *root,char ** word)
{
    if (root == NULL) return;
    if (root->nt != LEAF) {
        //printf("%d ",root->w);
        wbit[wp++] = '0';
        recur_dict(root->left,word);
        wbit[wp++] = '1';
        recur_dict(root->right,word);
    }else {
       
        word[root->c] = new char[wp];
        int i = 0;
        for ( i = 0 ; i < wp; i ++) {
            word[root->c][i] = wbit[i];
        }
        word[root->c][i] = 0;
        //printf(" %s\n",word[root->c]);
    }
    wp --;
}



char ** get_dict(node * tree)
{
    char ** dict = new char *[BYTE_MAX+1];
    for (int i = 0 ; i < BYTE_MAX+1; i ++) {
        dict[i] = NULL;
    }
    recur_dict(tree,dict);
    return dict;
}
/* 打印树 */
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

template<typename T>
struct _nl
{
    T n;
    struct _nl<T> * next;
};

template <typename T>
class queue
{
    using entry=_nl<T>;
    entry * b;
    entry * e;
    int l;
public:
    using iterator = entry*;
    queue()
    {
        b = nullptr;
        e = nullptr;
        l = 0;
    }
    queue<T> & push(const T & _t)
    {
        entry * n = new entry;
        n->n = _t;
        n->next = nullptr;

        if (l == 0) {
            b = e = n;
        }else {
            e->next = n;
            e = e->next;
        } 
        l++;
        return *this;
    }

    int size()
    {
        return l;
    }
    void pop()
    {
        if (l > 0) {
            entry * t = b;
            b = b->next;
            delete t;
            l--;
        }
    }
    T & front()
    {
        return b->n;
    }

    entry * begin()
    {
        return b;
    }

    entry * end()
    {
        return e->next;
    }

};

using nl=_nl<node*>; 
int llen(nl * s,nl * e)
{
    if (s == e) return 1;
    else return 1+llen(s->next,e);
}

bool check_all_null(nl * s,nl * e)
{
    if (s->n != NULL) return false;
    if (s == e && s->n == NULL) return true;
    return true;
}

void cn(char c,int n)
{
    for (int j = 0; j < n ; j++) {
        printf("%c",c);

    }
}
void nextl(int i)
{
    for (int j = 0; j < i ; j++) {
        printf("\n");
    }

}
int get_tab_of_level(int l)
{
    if(l == 0) return 3;
    else if (l > 0)
        return (get_tab_of_level(l-1)*2)+1;
    else 
        return 0;
}
void p_tree(node *root)
{
    int  h = get_height_of_tree(root);
    printf("哈夫曼树结构[%d]层:\n",h);
    nl * s,*e;
    s = e = new nl;
    s->n = root;
    s->next = NULL;
    while (h>= 0) {
        int nowl = llen(s,e);
            int sc = get_tab_of_level(h-1);
        for (int i = 0 ; i < nowl; i ++) {
               
            cn(' ',sc-2);
            if (s->n != NULL) {
                if (s->n->nt == LEAF) {
                    if (check_visable(s->n->c))
                    printf("\'%c\'",s->n->c);
                else 
                    printf("\\%2d",s->n->c);
                }
                else 
                    printf("%3d",s->n->w);
            }else 
                printf ("   ");
            cn(' ',sc+1);
            fflush(stdout);
            nl * l = new nl;
            nl * r = new nl;
            if ( s->n == NULL || s->n->nt == LEAF) {
                l->n = NULL;
                r->n = NULL;
            }else {
                l->n = s->n->left;
                r->n = s->n->right;
            }
            if (e != NULL) {
            e->next = l;
            e = e->next;
            e->next = r;
            e = e->next;
            }

            nl * t = s;
            if (s!=NULL)
            s = s->next;
            delete t;
        }
        h--;
        nextl(h+1);
    }
    nextl(1);
    fflush(stdout);
}

/* 复制一棵树 */
node * copy_tree(node *root)
{
    if (root == NULL) return NULL;
    node *croot = new node;
    croot->c = root->c;
    croot->nt = root->nt;
    croot->w = root->w;
    if (root->nt != LEAF) {
        croot->left = copy_tree(root->left);
        croot->right = copy_tree(root->right);
    }
    return croot;
}

/* 删除树 */
void destroy_tree(node *root)
{
    if (root->nt != LEAF) {
        destroy_tree(root->left);
        destroy_tree(root->right);
    }
    delete root;
}



void p_rate(int * rate)
{
    for (int i = 0 ; i < BYTE_MAX+1; i++) {
        if (rate[i] > 0)
        if (!check_visable(i)) {
            printf("\\%d[%d] ",i,rate[i]);
        }else {
            printf("%c[%d] ",i,rate[i]);
        }

    }
    printf("\n");
}

void p_dict(char ** dict)
{
    for (int i = 0 ; i < BYTE_MAX+1; i ++) {
        if (dict[i] != NULL)
        if (check_visable(i))
            printf("  \'%c\' [%s]\n",i,dict[i]);
        else
            printf("\'\\%d\' [%s]\n",i,dict[i]);
    }
    printf("\n");
}



void char_to_bin(char c)
{
    int b = 7;
    while(b>=0) {
        if (c>=(1<<b)) { 
            printf("1");
            c -= (1<<b);
        }else {
            printf("0");
        }
        b--;
    }
    printf(" ");
}

/* 字节位操作 */
void put_bit_in_char(char & c,char bit, int ndx)
{
    // bit应该为{0 1}
    c &= ~(1<<(8-ndx));
    bit <<= (8-ndx);
    c |= bit;
}

/* 获取字节中某位 */
char get_bit_in_char(char c,int ndx)
{
    return (c>>(8-ndx) & 1);
}
/* 压缩文件 */
int huffman_compress(int *rate,char ** dict,  const char *filename,const char *oname)
{

    FILE * inf = fopen(filename,"rb");
    fseek(inf,0,SEEK_END);
    int all = ftell(inf);
    rewind(inf);
    FILE *out  = fopen(oname,"wb");

    if (inf == NULL) {
        printf("打开文件失败:%s\n",filename);
        perror("fopen");
        return 0;
    }
    
    if (out == NULL) {
        printf("创建文件失败:%s\n",oname);
        perror("fopen");
        return 0;
    }


    fwrite(rate,(BYTE_MAX+1)*RATE_SIZE,1,out);

    int c = 0;
    int bitc = 0;
    using byte = char;
    byte b = 0;
    queue<char> buff;
    while (true) {
        char ch = fgetc(inf);
        if (feof(inf)) break;
        for (int i = 0 ; i < strlen(dict[ch]); i++) {
            buff.push(dict[ch][i]);
            put_bit_in_char(b,dict[ch][i]-'0',bitc%8 +1 );
            bitc++;
            if (bitc%8 == 0) {
                int res = fputc(b,out);
                //if (res < 1) perror("fwrite");
                char_to_bin(b);
                fflush(out);
                b = 0;
            }

        }
        c++;
            //printf("\r[%d/%d]",c,all);

    }
    nextl(1);
    printf("编码[%d]字节\n",c);
    fflush(stdout);
    fclose(inf);
    fclose(out);
    return 0;
}


int huffman_uncompress(const char *filename, const char * oname)
{   
    int rate[BYTE_MAX+1] = {0};
    FILE * inf = fopen(filename,"rb");
    FILE * out = fopen(oname, "wb");
    if (inf == NULL) {
        perror("fopen");
        return 0;
    }
    if (out == NULL) {
        perror("fopen");
        return 0;
    }
    /* 读取词频 */
    fread(rate,(BYTE_MAX+1)*RATE_SIZE,1,inf);

    /* 构建树 */
    node * tree = get_tree(rate);
    printf("读取待解压文件头\n");
    //p_rate(rate);
    //p_tree(tree);

    node * tree_p = tree;
    int c = 0;
    int bitc = 0;
    while(true) {
        char ch = 0;
        ch = fgetc(inf);
        if(feof(inf)) break;
        //char_to_bin(ch);
        for (int  i = 0 ; i < 8; i ++) {
            char bit = get_bit_in_char(ch,i+1);

            if (bit == 0) 
                tree_p = tree_p->left;
            else if (bit == 1)
                tree_p = tree_p->right;

            if (tree_p->nt == LEAF) {
                fputc(tree_p->c,out);
                printf("%c",tree_p->c);
                tree_p = tree;
            }
        }
    }
    printf("\n");
    fflush(stdout);
    fclose(inf);
    fclose(out);
}


int main (int argc, char *argv[])
{
    int * rate = get_rate(argv[1]);
    node * tree = get_tree(rate);
    char ** dict = get_dict(tree);
    //p_rate(rate);
    //p_tree(tree);
    p_dict(dict);
    huffman_compress(rate, dict, argv[1],"a.e");
    huffman_uncompress("a.e","a.d");

    char t = 64;
    char g = get_bit_in_char(t,2);
    //char_to_bin(g);
    printf("\n");
}
