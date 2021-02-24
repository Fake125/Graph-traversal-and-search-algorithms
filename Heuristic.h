#ifndef HEURISTIC_H
#define HEURISTIC_H
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

class Heuristic {
private:
    char city;
    float H;
public:
    // Constructor;
    Heuristic();
    Heuristic(char city, float H);
    // Destructor
    ~Heuristic();
    // Querying
    void Set(char city, float h);
    float get_H();
    char get_City();
};
#endif
