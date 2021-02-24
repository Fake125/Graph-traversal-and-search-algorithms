#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "link.h"
#include <vector>
#include <iostream>
#include "Heuristic.h"
#include "list.h"
#include "node.h"
using namespace std;
void acquireLinks(vector<link> &links,void (*AcquireTech)(vector<link>&));
void acquireH(vector<Heuristic>& HS);
void bfs(node* n,vector<link>& links, list*& pFrontier);
void dfs(node* n,vector<link>& links, list*& pFrontier);
void greedy(node* n,vector<link>& links, list*& pFrontier);
void ucs(node* n,vector<link>& links, list*& pFrontier);
void AStar(node* n,vector<link>& links, list*& pFrontier);
void Is_Links_valid(vector<link>& links);
void Is_HS_valid(vector<link>& links);
#endif

