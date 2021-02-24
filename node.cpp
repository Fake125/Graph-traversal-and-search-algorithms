#include "node.h"
#include <iostream>
using namespace std;
// Constructor 

node::node() {

}

node::node(char name) {
    this->name = name;
    this->Parent = NULL;
    this->Next = NULL;
    this->explored = false;
}
// Destructor

node::~node() {
    delete Parent;
    delete Next;
}
// Setting

void node::Set_name(char name) {
    this->name = name;
}

void node::Set_Parent(node* Parent) {
    this->Parent = Parent;
}

void node::Set_Next(node* Next) {
    this->Next = Next;
}

void node::Set_cost(float cost) {
    this->cost = cost;
}

void node::Set_explored(bool ex) {
    this->explored = ex;
}

void node::Set_F(float f) {
    this->F = f;
}

void node::Set_H(float h) {
    this->H = h;
}
// Getting

char node::Get_name() {
    return name;
}

node* node::Get_Parent() {
    return (Parent);
}

node* node::Get_Next() {
    return (Next);
}

float node::Get_cost() {
    return cost;
}

bool node::Get_explored() {
    return explored;
}

float node::Get_F() {
    return (F);
}

float node::Get_H() {
    return H;
}

void node::expand(vector<link>& links, list*& pFrontier, void(*Algorithm)(node*,vector<link>&, list* &)) {
    Algorithm(this,links, pFrontier);
}

// Role play

/*
void node::expand(vector<link>& links, list* &pFrontier) {
    pFrontier->MakeMeStack();
    pFrontier->expand_count();
    char Myname = this->name;
    node* Child;
    if (pFrontier->is_empty()) this->Set_cost(0);
    float Mycost = this->cost;
    char C_name;
    float C_cost;
    this->Push_Explored(pFrontier);
    this->isQualified(pFrontier);

    if (this->Goal_Test(pFrontier)) {
        pFrontier->Set_FinalCost(Mycost);
        pFrontier->printResult();
        return;
    }
    // Walk Forward
    for (int i = 0; i < links.size(); i++) {
        this->Get_child(links, i, Myname, C_name);
        if (C_name == '?') continue;
        Child = new node(C_name);
        C_cost = Mycost + links[i].get_linkcost();
        Child->Set_Parent(this);
        Child->Set_cost(C_cost);
        if (!Child->is_explored(pFrontier)) {
            Child->expand(links, pFrontier);
            return;
        }
    }
    // Backtracking
    pFrontier->Remove();
    if (pFrontier->is_empty()) {
        cout << "No solution" << endl;
        return;
    }
    Child = pFrontier->Get_Frist();
    Child->expand(links, pFrontier);
    return;
}

void node::bfs(vector<link>& links, list*& pFrontier) {
    pFrontier->MakeMeQueue();
    pFrontier->expand_count();
    char Myname = this->name;
    node* Child;
    if (pFrontier->is_empty()) this->Set_cost(0);
    if (!pFrontier->is_empty()) pFrontier->Remove();
    float Mycost = this->cost;
    char C_name;
    float C_cost;
    this->Push_Explored(pFrontier);
    if (this->Goal_Test(pFrontier)) {
        pFrontier->Set_FinalCost(Mycost);
        pFrontier->printResult();
        return;
    }
    for (int i = 0; i < links.size(); i++) {
        this->Get_child(links, i, Myname, C_name);
        if (C_name == '?') continue;
        Child = new node(C_name);
        C_cost = Mycost + links[i].get_linkcost();
        Child->Set_Parent(this);
        Child->Set_cost(C_cost);

        if (!Child->is_explored(pFrontier) && !pFrontier->if_exist(C_name)) {
            Child->pushNodeToList(pFrontier);
            if (this->Goal_Test(pFrontier)) {
                pFrontier->Set_FinalCost(Mycost);
                pFrontier->printResult();
                return;
            }
        }
    }
    if (pFrontier->is_empty()) {
        cout << "No solution" << endl;
        return;
    }
    Child = pFrontier->Get_Frist();
    Child->bfs(links, pFrontier);
    return;
}

void node::ucs(vector<link>& links, list*& pFrontier) {
    pFrontier->MakeMePQueue(0);
    pFrontier->expand_count();
    char Myname = this->name;
    node* Child;
    if (pFrontier->is_empty()) this->Set_cost(0);
    if (!pFrontier->is_empty()) pFrontier->Remove();
    float Mycost = this->cost;
    char C_name;
    float C_cost;
    this->Push_Explored(pFrontier);
    if (this->Goal_Test(pFrontier)) {
        pFrontier->Set_FinalCost(Mycost);
        pFrontier->printResult();
        return;
    }
    for (int i = 0; i < links.size(); i++) {
        this->Get_child(links, i, Myname, C_name);
        if (C_name == '?') continue;
        Child = new node(C_name);
        C_cost = Mycost + links[i].get_linkcost();
        Child->Set_Parent(this);
        Child->Set_cost(C_cost);
        if (!Child->is_explored(pFrontier))
            Child->isQualified(pFrontier);
    }
    if (pFrontier->is_empty()) {
        cout << "No solution" << endl;
        return;
    }
    Child = pFrontier->Get_Frist();
    Child->ucs(links, pFrontier);
}

void node::greedy(vector<link>& links, list*& pFrontier) {
    pFrontier->MakeMePQueue(1);
    pFrontier->expand_count();
    char Myname = this->name;
    node* Child;
    if (pFrontier->get_expansions() == 1) this->Set_cost(0);
    float Mycost = this->cost;
    char C_name;
    float C_cost;
    float C_H;
    float H;
    this->Push_Explored(pFrontier);

    if (this->Goal_Test(pFrontier)) {
        pFrontier->Set_FinalCost(Mycost);
        pFrontier->printResult();
        return;
    }
    for (int i = 0; i < links.size(); i++) {
        this->Get_child(links, i, Myname, C_name);
        if (C_name == '?') continue;
        Child = new node(C_name);
        Child->Set_Parent(this);
        C_cost = Mycost + links[i].get_linkcost();
        Child->Set_cost(C_cost);
        C_H = pFrontier->Get_Hcost(C_name);
        Child->Set_H(C_H);
        Child->pushNodeToList(pFrontier);
    }
    Child = pFrontier->Get_Frist();
    while (Child->is_explored(pFrontier)) {
        pFrontier->Remove();
        if (pFrontier->is_empty()) {
            cout << "No solution" << endl;
            return;
        }
        Child = pFrontier->Get_Frist();
    }
    pFrontier->clear();
    Child->greedy(links, pFrontier);
    return;
}

void node::A(vector<link>& links, list*& pFrontier) {
    pFrontier->MakeMePQueue(2);
    pFrontier->expand_count();
    char Myname = this->name;
    node* Child;
    float MyH = pFrontier->Get_Hcost(Myname);
    this->Set_H(MyH);
    if (pFrontier->is_empty()) this->Set_cost(0);
    if (!pFrontier->is_empty()) pFrontier->Remove();
    float Mycost = this->cost;
    char C_name;
    float C_cost;
    float C_f;
    float C_h;
    this->Push_Explored(pFrontier);
    if (this->Goal_Test(pFrontier)) {
        pFrontier->Set_FinalCost(Mycost);
        pFrontier->printResult();
        return;
    }
    for (int i = 0; i < links.size(); i++) {
        this->Get_child(links, i, Myname, C_name);
        if (C_name == '?') continue;
        Child = new node(C_name);
        C_cost = Mycost + links[i].get_linkcost();
        Child->Set_Parent(this);
        Child->Set_cost(C_cost);
        C_h = pFrontier->Get_Hcost(C_name);
        Child->Set_H(C_h);
        C_f = C_cost + C_h;
        Child->Set_F(C_f);
        if (!Child->is_explored(pFrontier))
            Child->isQualified(pFrontier);
    }
    if (pFrontier->is_empty()) {
        cout << "No solution" << endl;
        return;
    }
    Child = pFrontier->Get_Frist();
    Child->A(links, pFrontier);
}

 */
void node::pushNodeToList(list* &pFrontier) {

    pFrontier->Push(this);
}

bool node::isGoal(char goalCity) {
    if (this->name == goalCity) {
        return true;
    } else {

        return false;
    }
}

void node::isQualified(list * pFrontier) {
    if (!pFrontier->if_exist(this->name)) {
        this->pushNodeToList(pFrontier);
    } else {
        char Myname = this->name;
        float Mycost = this->cost;
        node* it = pFrontier->Get_node(Myname);
        float Itscost = it->Get_cost();
        if (Mycost < Itscost) {
            if (pFrontier->get_type() == 'p') {
                pFrontier->discard(Myname);
                this->pushNodeToList(pFrontier);
            } else {
                pFrontier->replace(this);
            }
        }
    }
}

// My functions

void node::Get_child(vector<link>& links, int index, char my_name, char& c_name) {
    if (my_name == links[index].get_c1()) {
        c_name = links[index].get_c2();
    } else if (my_name == links[index].get_c2()) {
        c_name = links[index].get_c1();
    } else {
        c_name = '?';
    }
}

bool node::Goal_Test(list * pFrontier) {
    if (this->isGoal(pFrontier->Get_GOAL())) {
        return true;
    } else {
        return false;
    }
}

bool node::is_explored(list * pFrontier) {
    char Myname = this->name;
    char Exploring_name;
    for (int i = 0; i < pFrontier->Explored.size(); i++) {
        Exploring_name = pFrontier->Explored[i]->Get_name();
        if (Exploring_name == Myname) return (true);
    }
    return false;
}

void node::Push_Explored(list* &pFrontier) {
    if (!this->is_explored(pFrontier)) {
        pFrontier->Explored.push_back(this);
    }
}
