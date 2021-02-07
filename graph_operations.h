#pragma once

#include "Graph.h"

list<int> FindCycleSource(Graph& G, int s);
list<int> FindCycle(Graph& G);
list<list<int>> Components(Graph& G);
list<int> DFS(Graph& G, int s, int v);
int DijkstrasMin(set<int>& vertices, map<int, int>& dist);
map<int, list<int>> DijkstraDecode(int u, map<int, int>& d, map<int, int>& p);
map<int, list<int>> DijkstrasAlgorithm(Graph& G, int s);
