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
            printf("%s\n",ec.encode(str.str().c_str()));        
            fflush(stdout);
            break;
        }
    }
}
