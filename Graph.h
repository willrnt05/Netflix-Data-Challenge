#pragma once
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <vector>

using namespace std;

void* operator new(size_t size) {
    std::cout << "System allocates " << size << " bytes\n";

    return malloc(size);
}

class Graph
{
public:
	struct Node
	{
		int data;
		set<int> edges;
	};


	int numEdges = 0;
	set<int> allNodes;
	map<int, Node> Graph;



	void AddEdge(int s, int v)
	{

		if (Graph[s].edges.find(v) != Graph[s].edges.end())
			numEdges += 1;

		Graph[s].edges.insert(v);
		Graph[s].data = s;

		Graph[v].edges.insert(s);
		Graph[v].data = v;

		allNodes.insert(s);
		allNodes.insert(v);

	};

	void PrintGraph()
	{
		for (auto i = Graph.begin(); i != Graph.end(); ++i)
		{
			
			cout << i->second.data << ": ";
			for (auto j = i->second.edges.begin(); j != i->second.edges.end(); ++j)
			{
				cout << *j << " ";
			}
			cout << endl;
			
		}
	};

	bool IsEdge(int s, int v)
	{
		if ((allNodes.find(s) != allNodes.end()) && (allNodes.find(v) != allNodes.end()))
		{
			if (Graph[s].edges.find(v) != Graph[s].edges.end())
				return true;
		}
		return false;
	};

	void InsertEmptyNode(int s)
	{
		Graph[s];
		Graph[s].data = s;
		set<int> emptyList;
		Graph[s].edges = emptyList;
		allNodes.insert(s);
	}

};
