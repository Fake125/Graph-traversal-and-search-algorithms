#include "functions.h"
using namespace std;

void acquireLinks(vector<link> &links, void (*AcquireTech)(vector<link>&)) {
    if (AcquireTech != NULL) {
        AcquireTech(links);
    } else {
        int limit = 1;
        char c1;
        char c2;
        float cost;
        link x;
        while (limit != 0) {
            cout << "Enter a Link\n\n";
            cout << "The name of First city : ";
            cin >> c1;
            cout << "The name of Second city : ";
            cin >> c2;
            cout << "The Value of Cost : ";
            cin >> cost;
            x.set(c1, c2, cost);
            links.push_back(x);
            cout << "if you want to stop The stream Enter 0 otherwise Enter any number : ";
            cin >> limit;

        }
    }
}

void acquireH(vector<Heuristic>& HS) {
    ifstream in;
    in.open("./DAT/heuristics.dat");
    string x;
    char c;
    float h;
    string temp;
    Heuristic P;
    while (in.eof() == 0) {
        getline(in, x);
        temp = "";
        c = x[0];
        for (int i = 2; i < x.size(); i++) {
            temp += x[i];
        }
        istringstream convert(temp);
        convert >> h;
        P.Set(c, h);
        HS.push_back(P);

    }
}

// Breadth First Search

void bfs(node* n, vector<link>& links, list*& pFrontier) {
    pFrontier->MakeMeQueue();
    pFrontier->expand_count();
    char Myname = n->Get_name();
    node* Child;
    if (pFrontier->is_empty()) n->Set_cost(0);
    if (!pFrontier->is_empty()) pFrontier->Remove();
    float Mycost = n->Get_cost();
    char C_name;
    float C_cost;
    n->Push_Explored(pFrontier);
    if (n->Goal_Test(pFrontier)) {
        pFrontier->Set_FinalCost(Mycost);
        pFrontier->printResult();
        return;
    }
    for (int i = 0; i < links.size(); i++) {
        n->Get_child(links, i, Myname, C_name);
        if (C_name == '?') continue;
        Child = new node(C_name);
        C_cost = Mycost + links[i].get_linkcost();
        Child->Set_Parent(n);
        Child->Set_cost(C_cost);

        if (!Child->is_explored(pFrontier) && !pFrontier->if_exist(C_name)) {
            Child->pushNodeToList(pFrontier);
            if (n->Goal_Test(pFrontier)) {
                pFrontier->Set_FinalCost(Mycost);
                pFrontier->printResult();
                return;
            }
        }
    }
    if (pFrontier->is_empty()) {
        cout << "\nNo solution" << endl;
        return;
    }
    Child = pFrontier->Get_Frist();
    bfs(Child, links, pFrontier);
    return;
}

// Depth First Search

void dfs(node* n, vector<link>& links, list*& pFrontier) {
    pFrontier->MakeMeStack();
    pFrontier->expand_count();
    char Myname = n->Get_name();
    node* Child;
    if (pFrontier->is_empty()) n->Set_cost(0);
    float Mycost = n->Get_cost();
    char C_name;
    float C_cost;
    n->Push_Explored(pFrontier);
    n->isQualified(pFrontier);

    if (n->Goal_Test(pFrontier)) {
        pFrontier->Set_FinalCost(Mycost);
        pFrontier->printResult();
        return;
    }
    // Walk Forward
    for (int i = 0; i < links.size(); i++) {
        n->Get_child(links, i, Myname, C_name);
        if (C_name == '?') continue;
        Child = new node(C_name);
        C_cost = Mycost + links[i].get_linkcost();
        Child->Set_Parent(n);
        Child->Set_cost(C_cost);
        if (!Child->is_explored(pFrontier)) {
            dfs(Child, links, pFrontier);
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
    dfs(Child, links, pFrontier);
    return;
}

void ucs(node* n, vector<link>& links, list*& pFrontier) {
    pFrontier->MakeMePQueue(0);
    pFrontier->expand_count();
    char Myname = n->Get_name();
    node* Child;
    if (pFrontier->is_empty()) n->Set_cost(0);
    if (!pFrontier->is_empty()) pFrontier->Remove();
    float Mycost = n->Get_cost();
    char C_name;
    float C_cost;
    n->Push_Explored(pFrontier);
    if (n->Goal_Test(pFrontier)) {
        pFrontier->Set_FinalCost(Mycost);
        pFrontier->printResult();
        return;
    }
    for (int i = 0; i < links.size(); i++) {
        n->Get_child(links, i, Myname, C_name);
        if (C_name == '?') continue;
        Child = new node(C_name);
        C_cost = Mycost + links[i].get_linkcost();
        Child->Set_Parent(n);
        Child->Set_cost(C_cost);
        if (!Child->is_explored(pFrontier))
            Child->isQualified(pFrontier);
    }
    if (pFrontier->is_empty()) {
        cout << "\nNo solution" << endl;
        return;
    }
    Child = pFrontier->Get_Frist();
    ucs(Child, links, pFrontier);
}
/////////// greedy

void greedy(node* n, vector<link>& links, list*& pFrontier) {
    pFrontier->MakeMePQueue(1);
    pFrontier->expand_count();
    char Myname = n->Get_name();
    node* Child;
    if (pFrontier->get_expansions() == 1) n->Set_cost(0);
    float Mycost = n->Get_cost();
    char C_name;
    float C_cost;
    float C_H;
    float H;
    n->Push_Explored(pFrontier);
    if (n->Goal_Test(pFrontier)) {
        pFrontier->Set_FinalCost(Mycost);
        pFrontier->printResult();
        return;
    }
    for (int i = 0; i < links.size(); i++) {
        n->Get_child(links, i, Myname, C_name);
        if (C_name == '?') continue;
        Child = new node(C_name);
        Child->Set_Parent(n);
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
            cout << "\nNo solution" << endl;
            return;
        }
        Child = pFrontier->Get_Frist();
    }
    pFrontier->clear();
    greedy(Child, links, pFrontier);
    return;
}

void AStar(node* n, vector<link>& links, list*& pFrontier) {
    pFrontier->MakeMePQueue(2);
    pFrontier->expand_count();
    char Myname = n->Get_name();
    node* Child;
    float MyH = pFrontier->Get_Hcost(Myname);
    n->Set_H(MyH);
    if (pFrontier->is_empty()) n->Set_cost(0);
    if (!pFrontier->is_empty()) pFrontier->Remove();
    float Mycost = n->Get_cost();
    char C_name;
    float C_cost;
    float C_f;
    float C_h;
    n->Push_Explored(pFrontier);
    if (n->Goal_Test(pFrontier)) {
        pFrontier->Set_FinalCost(Mycost);
        pFrontier->printResult();
        return;
    }
    for (int i = 0; i < links.size(); i++) {
        n->Get_child(links, i, Myname, C_name);
        if (C_name == '?') continue;
        Child = new node(C_name);
        C_cost = Mycost + links[i].get_linkcost();
        Child->Set_Parent(n);
        Child->Set_cost(C_cost);
        C_h = pFrontier->Get_Hcost(C_name);
        Child->Set_H(C_h);
        C_f = C_cost + C_h;
        Child->Set_F(C_f);
        if (!Child->is_explored(pFrontier))
            Child->isQualified(pFrontier);
    }
    if (pFrontier->is_empty()) {
        cout << "\nNo solution" << endl;
        return;
    }
    Child = pFrontier->Get_Frist();
    AStar(Child, links, pFrontier);
}
