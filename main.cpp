#include <cstdlib>
#include <iostream>
#include "vector"
#include "link.h"
#include "node.h"
#include "acquireLinks.h"
#include "functions.h"
#include "Heuristic.h"
using namespace std;

int main() {
    int choice;
PROGRAM:
    /* Get Data from user */
    cout << "How do you want to enter the links ?\n\n1-)From the file(links.dat)\n2-)From the console\n";
    cin >> choice;
    void (*acquire)(vector<link>&) = NULL;
    if (choice == 1) acquire = &acquireLinks;
    vector<link> links;
    acquireLinks(links, acquire);
    vector<Heuristic> Heuristics;
    acquireH(Heuristics);
    /* Get Data from user */
    
    /* Choosing an Algorithm */
    void(*Algorithm)(node*, vector<link> &, list* &);
    cout << "\nWhich algorithm you want to run ?\n1-)Depth First Search\n2-)Breadth First Search\n3-)Uniform Cost Search\n4-)Greedy Search\n5-)A* Search\n";
    cin >> choice;
    switch (choice) {
        case 1:
            Algorithm = &dfs;
            break;
        case 2:
            Algorithm = &bfs;
            break;
        case 3:
            Algorithm = &ucs;
            break;
        case 4:
            Algorithm = &greedy;
            break;
        case 5:
            Algorithm = &AStar;
            break;
        default:
            Algorithm = &dfs;
            break;
    }
    
    /* Choosing an Algorithm*/

    /* Get Start and Goal */
    char startCity;
    char goalCity;
    node* Start;
    cout << "Enter the start city : ";
    cin >> startCity;
    cout << "Enter the goal city : ";
    cin >> goalCity;
    /* Get start and Goal */

    /* Set frontier */
    list* frontier = new list();
    frontier->Set_GOAL(goalCity);
    frontier->Set_Start(startCity);
    frontier->Set_HS(Heuristics);
    /* Set frontier*/

    Start = new node(startCity);
    Start->expand(links, frontier, Algorithm);
    cout << "\n\nIf you want to end The program Enter 0 Otherwise Enter any number else : ";
    cin >> choice;
    exit;
    if (choice != 0) goto PROGRAM;

}
