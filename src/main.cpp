#include <cstdio>
#include <sstream>
#include "encoder.h"
/**
 * 用于计算频率
 */
using std::stringstream;

int main (int argc, char *argv[])
{


    stringstream str;
    encoder ec;
    while (true) {
        char ch = getchar();
        if (ch != '\n') {
            str<<ch;
        }else {
            printf("\n%s",ec.encode(str.str().c_str()));        
            printf("\n");        
            fflush(stdout);
            return 0;
        }
    }
}
