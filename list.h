#ifndef LIST_H
#define LIST_H
#include <stack>
#include <queue>
#include "Heuristic.h"
using namespace std;
class node;

class list {
private:
    node* First;
    node* Last;
    // My Members
    char GOAL;
    char Start;
    char type;
    int size;
    vector<char> PATH;
    float FinalCost;
    int expansions;
    int Flag;
public:
    vector<Heuristic> HS;
    vector<node*> Explored;
    // Constructor
    list();
    // Destructor
    ~list();
    // Setting


    // Adding to list
    void PushLast(node* x);
    void PushFirst(node* x);
    void Push_By_Prority(node* x);
    void Push_By_Prority_H(node* x);
    void Push_By_Prority_F(node* x);
    // Removing
    void RemoveFirst();
    void RemoveLast();
    void discard(char name);
    // General Adding and Removing
    void Push(node* x);
    void Remove();
    // Getting
    node* Get_Frist();
    node* Get_Last();
    vector<Heuristic> Get_Heuristics();
    char get_type();
    // Role play;
    node* Get_node(char name);
    void printList();
    void printResult();
    void replace(node* New);
    // My functions
    bool is_empty();
    bool if_exist(char c);
    void Set_GOAL(char goal);
    char Get_GOAL();
    void Set_Start(char start);
    char Get_Start();
    void Get_Path();
    void Set_HS(vector<Heuristic> HSS);
    node* Get_From_Explored(char name);
    void Set_FinalCost(float cost);
    void expand_count();
    void print_explored();
    void clear();
    int get_expansions();
    float Get_Hcost(char name);
    // Data structures
    void MakeMeStack();
    void MakeMeQueue();
    void MakeMePQueue(int z);
};
#endif

