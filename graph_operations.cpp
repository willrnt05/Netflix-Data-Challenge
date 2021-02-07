#include "Graph.h"


//O(V + ELog(v))
list<int> FindCycleSource(Graph& G, int s)
{
	int v = s;
	set<int> visited;
	stack<int> path;
	int currentSpot = s;

	path.push(currentSpot);

	bool ignoreWhile = false;
	int pops = 0;

	visited.insert(s);

	//Suppose Node u exists in path
	while (!path.empty())
	{
		//cout << "Current Location = " << path.top() << endl;
		bool repeatLoop = false;
		//For all neighbors of u
		for (auto it = G.Graph[path.top()].edges.begin(); it != G.Graph[path.top()].edges.end(); ++it)
		{
			//cout << "Edge: " << *it << endl;
			//If it is the node we are looking for then add it to path and leave everything. Don't pop after break
			if ((*it == v) && (path.size() > 2))
			{
				//cout << "Found the last Node" << endl;
				path.push(*it);
				ignoreWhile = true;
				repeatLoop = true;
				break;
			}
			//If it has not been visited then push it to path and move forward
			else if (visited.find(*it) == visited.end())
			{
				//cout << *it << " has not been visited. It is being added to the path and marked as visited" << endl;
				visited.insert(*it);
				path.push(*it);
				repeatLoop = true;
				break;
			}
			//How to know if at end of natural loop
		}

		if (!repeatLoop)
		{
			//cout << "It is popping the top element" << endl;
			path.pop();
		}
		if (ignoreWhile)
			break;
	}

	list<int> finalList;

	while (!path.empty())
	{
		finalList.push_front(path.top());
		path.pop();
	}
	return finalList;
};
list<int> FindCycle(Graph& G)
{
	list<int> cycle;
	for (auto it = G.allNodes.begin(); it != G.allNodes.end(); ++it)
	{
		cycle = FindCycleSource(G, *it);
		if (!cycle.empty())
			return cycle;
	}
	return cycle;
}



list<list<int>> Components(Graph& G) //O(V + Elog(V)).  Elog(E) because of insert and erase calls.
{
	set<int> visited;
	set<int> notVisited = G.allNodes;
	stack<int> path;
	list<list<int>> allComponents;


	while (!notVisited.empty()) //O(V)  All this really becomes O(V)
	{
		int currentSpot = *(notVisited.begin());

		path.push(currentSpot);
		bool ignoreWhile = false;
		list<int> currentComponent;
		visited.insert(currentSpot); //O(log(V))
		notVisited.erase(currentSpot); //O(log(V))
		currentComponent.push_back(currentSpot);

		//Suppose Node u exists in path
		while (!path.empty()) //Time Correlates to the above whileLoop.
		{

			bool repeatLoop = false;

			for (auto it = G.Graph[path.top()].edges.begin(); it != G.Graph[path.top()].edges.end(); ++it) //O(E)
			{
				//cout << "Edge: " << *it << endl;

				//If it has not been visited then push it to path and move forward
				if (visited.find(*it) == visited.end()) //O(log(V))
				{

					//cout << *it << " has not been visited. It is being added to the path and marked as visited" << endl;
					notVisited.erase(*it);
					visited.insert(*it);
					currentComponent.push_back(*it);
					path.push(*it);
					repeatLoop = true;
					break;
				}

			}

			if (!repeatLoop)
			{
				//cout << "It is popping the top element" << endl;
				path.pop();
			}
			if (ignoreWhile)
				break;
		}
		//cout << currentComponent.size() << "\n";
		allComponents.push_front(currentComponent);
		list<int> temp;
		currentComponent = temp;
	}
	return allComponents;
};


//Appears to be working correctly with basic graph
list<int> DFS(Graph& G, int s, int v)
{
	set<int> visited;
	stack<int> path;
	int currentSpot = s;

	path.push(currentSpot);

	bool ignoreWhile = false;
	int pops = 0;

	visited.insert(s);

	//Suppose Node u exists in path
	while (!path.empty()) //O(ConnectedPartofGraph)
	{
		//cout << "Current Location = " << path.top() << endl;
		bool repeatLoop = false;
		//For all neighbors of u
		for (auto it = G.Graph[path.top()].edges.begin(); it != G.Graph[path.top()].edges.end(); ++it) //O(numEdges)
		{
			//cout << "Edge: " << *it << endl;
			//If it is the node we are looking for then add it to path and leave everything. Don't pop after break
			if (*it == v)
			{
				//cout << "Found the last Node" << endl;
				path.push(*it);
				ignoreWhile = true;
				repeatLoop = true;
				break;
			}
			//If it has not been visited then push it to path and move forward
			else if (visited.find(*it) == visited.end()) //O(log(n))
			{
				//cout << *it << " has not been visited. It is being added to the path and marked as visited" << endl;
				visited.insert(*it);
				path.push(*it);
				repeatLoop = true;
				break;
			}
			//How to know if at end of natural loop
		}

		if (!repeatLoop)
		{
			//cout << "It is popping the top element" << endl;
			path.pop();
		}
		if (ignoreWhile)
			break;
	}

	list<int> finalList;

	while (!path.empty())
	{
		finalList.push_front(path.top());
		path.pop();
	}
	return finalList;
};





//Goal is to build a map with the list to each node from the source

int DijkstrasMin(set<int>& vertices, map<int, int>& dist)
{
	int min = *(vertices.begin());

	for (auto it = vertices.begin(); it != vertices.end(); ++it)
	{
		if (dist[*it] < dist[min])
		{
			min = *it;
		}
	}
	return min;
};
//Write a decode for u, v with a list return
map<int, list<int>> DijkstraDecode(int u, map<int, int>& d, map<int, int>& p)
{

	map<int, list<int>> shortestPaths;

	for (auto it = d.begin(); it != d.end(); ++it)
	{
		list<int> path;
		int start = it->first;
		int a = it->first;
		if (d[a] < 999999999)
		{
			while (p[a] != -999)
			{
				path.push_front(a);
				a = p[a];
			}
			path.push_front(a);

		}
		shortestPaths[start] = path;
	}
	return shortestPaths;
}

//O(E + V^2)
map<int, list<int>> DijkstrasAlgorithm(Graph& G, int s)
{
	set<int> vertices;
	map<int, int> dist;
	map<int, int> prev;

	for (auto it = G.Graph.begin(); it != G.Graph.end(); ++it)
	{
		dist[it->first] = 999999999;
		prev[it->first] = -999;
		vertices.insert(it->first);
	}

	//cout << "Initialized all values to inf" << endl;

	dist[s] = 0;
	prev[s] = -999;

	while (!vertices.empty())
	{
		//Find minimum dist[u] for anything in Q. Consider Priority Queue
		//Think all weights one...... Set.... Reverse map?
		//There is some easy way to do this.
		int u = DijkstrasMin(vertices, dist);

		vertices.erase(u);

		for (auto it = G.Graph[u].edges.begin(); it != G.Graph[u].edges.end(); ++it)
		{
			int alt = dist[u] + 1;
			if (alt < dist[*it])
			{
				dist[*it] = alt;
				prev[*it] = u;
			}
		}
		//cout << "Size of Vertices: " << vertices.size() << endl;

	}
	return DijkstraDecode(s, dist, prev);
};

