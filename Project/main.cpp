#include <iostream>
#include "headers/Tetravex.h"
#include "headers/Helper.h"
using namespace std;

int main(int argc, char **argv)
{
    int algo, format;
    if(argc==1){
        Tetravex::jouer();
    }else{
        format = Helper::char2Int(*argv[1]);
        algo = Helper::char2Int(*argv[2])  - 1;
        Tetravex::jouer(format, algo);
    }
    return 0;
}