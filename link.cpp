#include "link.h"
#include <cstdlib>

link::link() {
}

link::link(char c1, char c2, float linkcost) {
    this->c1 = c1;
    this->c2 = c2;
    this->linkcost = linkcost;
}

void link::set(char c1, char c2, float linkcost) {
    this->c1 = c1;
    this->c2 = c2;
    this->linkcost = linkcost;
}

char link::get_c1() {
    return c1;
}

char link::get_c2() {
    return c2;
}

float link::get_linkcost() {
    return linkcost;
}