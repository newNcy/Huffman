#include <cstdio>
#include <sstream>
#include "encoder.h"
#include "decoder.h"
/**
 * 用于计算频率
 */
using std::stringstream;

int main (int argc, char *argv[])
{


    stringstream str;
    encoder ec;
    decoder dc; 
    while (true) {
        char ch = getchar();
        if (ch != '\n') {
            str<<ch;
        }else {
            const char * res = ec.encode(str.str().c_str());
            dc.set_tree(ec.tree());
            printf("\n%s",res);        
            printf("\n");        
            printf("%s\n",dc.decode(res));
            fflush(stdout);
            return 0;
        }
    }
}
