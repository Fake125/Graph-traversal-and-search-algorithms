#include "Heuristic.h"
using namespace std;

Heuristic::Heuristic() {

}

Heuristic::Heuristic(char city, float H) {
    this->city = city;
    this->H = H;
}

Heuristic::~Heuristic() {

}

void Heuristic::Set(char city, float H) {
    this->city = city;
    this->H = H;
}

char Heuristic::get_City() {
    return city;
}

float Heuristic::get_H() {
    return H;
}