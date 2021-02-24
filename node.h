#ifndef NODE_H
#define NODE_H
#include <cstdlib>
#include "link.h"
#include "vector"
#include "list.h"

using namespace std;
class list;
class node {
private:
    char name;
    node* Parent;
    node* Next;
    float cost;
    float H;
    float F;
    bool explored;
public:
    // Constructor 
    node();
    node(char name);
    // Destructor
    ~node();
    // Setting
    void Set_name(char name);
    void Set_Parent(node* Parent);
    void Set_Next(node* Next);
    void Set_cost(float cost);
    void Set_explored(bool ex);
    void Set_H(float h);
    void Set_F(float f);
    // Getting
    char Get_name();
    node* Get_Parent();
    node* Get_Next();
    float Get_cost();
    bool Get_explored();
    float Get_H();
    float Get_F();
    // Role play
    void expand(vector<link>& links, list* &pFrontier,void(*Algorithm)(node*,vector<link>&, list* &));
    void pushNodeToList(list* &pFrontier);
    bool isGoal(char goalCity);
    void isQualified(list* pFrontier);
    // My functions
    void Get_child(vector<link>& links,int index,char my_name,char& c_name);
    bool Goal_Test(list* pFrontier);
    bool is_explored(list* pFrontier);
    void Push_Explored(list* &pFrontier);
};
#endif

