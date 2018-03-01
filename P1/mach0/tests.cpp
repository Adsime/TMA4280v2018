//
// Created by adrian on 01.03.18.
//

#include "functions.cpp"
#include "iostream"

using namespace std;

int main() {
    double res = (4*machin_formula(3, 1.0/5.0) - machin_formula(3, 1.0/239.0));
    double test_case = 37012.0/46875.0 - 48941844013.0/11697168977985.0;
    cout << "Test = " << test_case << ". Actual = " << res << endl;
    cout << "Actual equality = " << ((res == test_case) ? "True" : "False") << endl;
}