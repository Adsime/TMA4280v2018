//
// Created by adriasm on 2/14/18.
//

#include "iostream"
#include "functions.cpp"

using namespace std;

int main(int args, char* argv[]) {
    int n = atoi(argv[1]);
    if(n < 1) exit(1);
    double res = (4*machin_formula(n, 1.0/5.0) - machin_formula(n, 1.0/239.0));
    cout << "n = " << n << ". PI ~ " << 4 * res << endl;
}