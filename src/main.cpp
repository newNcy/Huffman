#include <cstdio>
#include "vector.h"
#include "encoder.h"
/**
 * 用于计算频率
 */
typedef struct _e
{
    char ch;
    int count;
    struct _e * next;
}e;




int main (int argc, char *argv[])
{


    vector <char> str;
    encoder ec;
    while (true) {
        char ch = getchar();
        if (ch != '\n') {
            str<<ch;
        }else {
            printf("%s\n",str.value());
        
            break;
        }
    }
}
