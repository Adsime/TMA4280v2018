//
// Created by adriasm on 2/14/18.
//

#include "iostream"
#include "functions.cpp"

using namespace std;

int main(int args, char* argv[]) {
    int n = atoi(argv[1]);
    if(n < 1) exit(1);
    double res = riemann_zeta(n);
    res = fix_to_pi(res);
    cout << "n = " << n << ". PI ~ " << res << endl;
}