#include "graph_simulator.h"

void makeNCycle(Graph& G, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		G.AddEdge(i, i + 1);
	}
	G.AddEdge(n - 1, 0);
}
void makeComplete(Graph& G, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			G.AddEdge(i, j);
		}
	}
}
void makeEmptyGraph(Graph& G, int n)
{
	for (int i = 0; i < n; ++i)
	{
		G.InsertEmptyNode(i);
	}
}

void makeTruncatedHeap(Graph& G, int m, int n)
{
	if (m >= n) return;
	for (int i = m; i < n; ++i)
	{
		int a = ((int)((i - 1) / 2));
		int b = (2 * i + 1);
		int c = (2 * i + 2);
		if ((a >= m) && (a < n))
			G.AddEdge(i, a);
		if ((a >= m) && (a < n))
			G.AddEdge(i, b);
		if ((a >= m) && (a < n))
			G.AddEdge(i, c);
	}
	cout << "Built the Truncated Heap" << endl;
}

void makeHeap(Graph& G, int n)
{
	makeTruncatedHeap(G, 0, n);
}

void makeMod(Graph& G, int k, int n)
{
	for (int i = 0; i < n; ++i)
	{
		int begin = i + k;
		while (begin < n)
		{
			G.AddEdge(i, begin);
			begin += k;
		}
	}
}