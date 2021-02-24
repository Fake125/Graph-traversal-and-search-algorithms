#include "functions.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

void acquireLinks(vector<link> &links) {
    ifstream in;
    in.open("./DAT/links.dat");
    string x;
    char c1;
    char c2;
    char c;
    string temp;
    float cost;
    link N;
    while (in.eof() == 0) {
        getline(in, x);
        temp = "";
        c1 = x[0];
        c2 = x[2];
        for (int i = 4; i < x.size(); i++) {
            temp += x[i];
        }
        istringstream convert(temp);
        convert >> cost;
        N.set(c1, c2, cost);
        links.push_back(N);

    }


}
