//
// Created by adriasm on 2/23/18.
//

#include "../common/functions.cpp"
#include "iostream"
#include "math.h"
#include <iomanip>

using namespace std;

int main(int args, char* argv[]) {
    char c = *argv[1];
    if(c == 'u') {
        utest(true);
    } else if(c == 'v') {
        vtest(true);
    } else if(c == 'e') {
        int iter = atoi(argv[2]);
        etest(iter, true);
    }
}
