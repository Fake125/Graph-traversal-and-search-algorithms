#ifndef LINK_H
#define LINK_H
class link {
private:
    char c1, c2;
    float linkcost;
public:
    link();
    link(char c1, char c2, float linkcost);
    void set(char c1, char c2, float linkcost);
    char get_c1();
    char get_c2();
    float get_linkcost();
};
#endif

