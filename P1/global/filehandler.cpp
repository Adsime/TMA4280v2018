//
// Created by adrian on 01.03.18.
//

#include "iostream"
#include "fstream"
#include <chrono>
#include <ctime>

using namespace std;

ofstream mfile;
string test_path = "out/tests.txt";
string six_test_path = "out/six_tests.txt";

string get_time_stamp() {
    auto start = chrono::system_clock::now();
    time_t end_time = chrono::system_clock::to_time_t(start);
    string time = ctime(&end_time);
    time = time.substr(0, time.size()-1);
    return time;
}

void write_to_file(string text) {
    mfile << get_time_stamp() << " : " << text << endl;
}

void task(string file, bool start, string exercise) {
    if(start) {
        mfile.open(file, ios_base::app);
    }
    string text = start ? "START - " : "END - ";
    text.append(exercise);
    text.append(start ? "" : "\n\n");
    write_to_file(text);
    if(!start) {
        mfile.close();
    }
}