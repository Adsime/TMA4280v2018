//
// Created by adriasm on 2/23/18.
//

#include "functions.cpp"
#include "iostream"

using namespace std;

int main() {
    double test_case = 49.0/36.0;
    double res = riemann_zeta(3);
    cout << "Test = " << test_case << ". Actual = " << res << endl;
    cout << "Actual equality = " << ((res == test_case) ? "True" : "False") << endl;
}
