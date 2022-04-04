#include "SFEncode.h"

using namespace std;

const bool DEBUG = false;

int main(){


    SFEncode sfe("AAAABBCD");
    // sfe.printFreqencies();
    // sfe.printBinary();

    sfe.encode();

    return 0;
}