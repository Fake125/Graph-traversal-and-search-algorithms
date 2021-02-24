#include <iostream>
#include "list.h"
#include "node.h"
using namespace std;


// Constructor

list::list() {
    First = NULL;
    Last = NULL;
    size = 0;
    expansions = 0;
}
// Destructor

list::~list() {
    delete First;
    delete Last;
}
// Setting


// Adding to list

void list::PushLast(node* x) {
    if (First == NULL) {
        First = x;

    } else {
        Last->Set_Next(x);
    }
    Last = x;
}

void list::PushFirst(node* x) {
    if (First == NULL) {
        First = x;
        Last = x;
    } else {
        x->Set_Next(First);
        First = x;
    }
}

void list::Push_By_Prority(node* x) {
    node *q;
    float f_cost;
    float s_cost;

    if (First == NULL || x->Get_cost() < First->Get_cost()) {

        x->Set_Next(First);

        First = x;

    } else {

        q = First;

        while (q->Get_Next() != NULL && q->Get_Next()->Get_cost() <= x->Get_cost())
            q = q->Get_Next();

        x->Set_Next(q->Get_Next());

        q->Set_Next(x);

    }
}

void list::Push_By_Prority_H(node* x) {
    node *q;
    float f_cost;
    float s_cost;

    if (First == NULL || x->Get_H() < First->Get_H()) {

        x->Set_Next(First);

        First = x;

    } else {

        q = First;

        while (q->Get_Next() != NULL && q->Get_Next()->Get_H() <= x->Get_H())
            q = q->Get_Next();

        x->Set_Next(q->Get_Next());

        q->Set_Next(x);

    }
}

void list::Push_By_Prority_F(node* x) {
    node *q;

    if (First == NULL || x->Get_F() < First->Get_F()) {

        x->Set_Next(First);

        First = x;

    } else {

        q = First;

        while (q->Get_Next() != NULL && q->Get_Next()->Get_F() <= x->Get_F())
            q = q->Get_Next();

        x->Set_Next(q->Get_Next());

        q->Set_Next(x);

    }
}


// Removing

void list::RemoveFirst() {
    if (First == NULL) return;
    else {
        First = First->Get_Next();
    }
}

void list::RemoveLast() {
    node* current;
    node* before;
    if (First == NULL) return;
    else if (First == Last) First = Last = NULL;
    else {
        before = First;
        current = First->Get_Next();
        while (current != NULL) {
            if (current->Get_name() == Last->Get_name()) {
                before->Set_Next(NULL);
                Last = before;
            }
            before = current;
            current = current->Get_Next();
        }
    }
}

void list::discard(char name) {
    node* current;
    node* before;
    before = First;
    current = First->Get_Next();
    if (First->Get_name() == name) {
        First = First->Get_Next();
    }
    while (current != NULL) {
        if (name == current->Get_name()) {
            if (current->Get_Next() == NULL) {
                Last = before;
            } else {
                before->Set_Next(current->Get_Next());
            }
        }
        before = current;
        current = current->Get_Next();
    }



}

// General Adding and removing

void list::Push(node* x) {
    size++;
    if (type == 'q')
        this->PushLast(x);
    else if (type == 's')
        this->PushFirst(x);
    else if (type == 'p') {
        if (Flag == 0) this->Push_By_Prority(x);
        else if (Flag == 1) this->Push_By_Prority_H(x);
        else if (Flag == 2) this->Push_By_Prority_F(x);
    }
}

void list::Remove() {
    size--;
    this->RemoveFirst();
}



// Getting

node* list::Get_Frist() {
    return First;
}

node* list::Get_Last() {
    return Last;
}

char list::get_type() {
    return type;
}
// Role play;

node* list::Get_node(char name) {
    node* x;
    x = First;
    while (x != NULL) {
        if (x->Get_name() == name) {
            return x;
        }
        x = x->Get_Next();
    }
}

void list::printList() {
    cout << endl;
    node* x;
    x = First;
    char parent;
    if (x != NULL) {
        cout << "Parent" << "\t" << "Name" << "\t" << "Cost" << endl;
    }
    while (x != NULL) {
        if (x->Get_Parent() == NULL) {
            parent = '/';
        } else {
            parent = x->Get_Parent()->Get_name();
        }
        cout << parent << "\t" << x->Get_name() << "\t" << x->Get_cost() << endl;
        x = x->Get_Next();
    }

}

void list::printResult() {
    cout << "\n\n------------------------------------------\n\n";
    cout << "Frontier List : \n";
    this->printList();
    cout << "\nExplored List : \n";
    this->print_explored();
    cout << "------------------------------------------\n";
    cout << "\nSolution Path : ";
    this->Get_Path();
    for (int i = PATH.size() - 1; i>-1; i--) {
        cout << PATH[i];
        if (i != 0) cout << "->";
    }
    cout << "\nSolution cost : " << FinalCost;
    cout << "\nExpansion times : " << expansions;


}

void list::replace(node* New) {
    char Thename = New->Get_name();
    node* current;
    node* before;
    before = First;
    current = First->Get_Next();
    if (First->Get_name() == Thename) {
        New->Set_Next(First->Get_Next());
        First = New;
    }
    while (current != NULL) {
        if (Thename == current->Get_name()) {
            New->Set_Next(current->Get_Next());
            before->Set_Next(New);
        }
        before = current;
        current = current->Get_Next();
    }
}

// My functions

bool list::if_exist(char c) {
    node* current = First;
    while (current != NULL) {
        if (current->Get_name() == c) return true;
        current = current->Get_Next();
    }
    return false;
}

void list::Set_GOAL(char goal) {
    GOAL = goal;
}

char list::Get_GOAL() {
    return GOAL;
}

void list::Set_Start(char start) {
    this->Start = start;
}

char list::Get_Start() {
    return (this->Get_Start());
}

node* list::Get_From_Explored(char name) {
    node* final;
    char Exploring_name;
    for (int i = 0; i < Explored.size(); i++) {
        Exploring_name = Explored[i]->Get_name();
        if (name == Exploring_name) {
            final = Explored[i];
            return (final);
        }
    }
    return NULL;
}

void list::print_explored() {

    for (int i = 0; i < Explored.size(); i++) {
        cout << Explored[i]->Get_name() << endl;
    }
}

void list::Get_Path() {
    node* current = this->Get_From_Explored(GOAL);
    char current_name;
    while (current != NULL) {
        current_name = current->Get_name();
        PATH.push_back(current_name);
        current = current->Get_Parent();
    }
}

void list::Set_FinalCost(float cost) {
    FinalCost = cost;
}

void list::expand_count() {
    expansions++;
}

bool list::is_empty() {
    if (First == NULL) return true;
    else return false;
}

void list::clear() {
    size = 0;
    First = Last = NULL;
}

int list::get_expansions() {
    return expansions;
}

void list::Set_HS(vector<Heuristic> HSS) {
    HS = HSS;
}

float list::Get_Hcost(char name) {
    for (int i = 0; i < HS.size(); i++) {
        if (HS[i].get_City() == name) {
            return (HS[i].get_H());
            break;
        }
    }
    return 0;
}

// Data structures

void list::MakeMeStack() {
    type = 's';
}

void list::MakeMeQueue() {
    type = 'q';
}

void list::MakeMePQueue(int z) {
    type = 'p';
    Flag = z;
}

