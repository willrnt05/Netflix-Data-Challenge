#include "simulated_test.h"


void testGraph(Graph& G, int s)
{
    time_t time0;
    time_t time1;

    time(&time0);

    list<int> test = FindCycle(G);

    cout << "-------------------------NEW TEST------------------------" << endl;

    cout << "Cycle Finder Test" << endl;

    cout << "There are " << (test.size() && 1) << " Cycles..\n\n";

    for (auto it = test.begin(); it != test.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    time(&time1);

    double TestTime = time1 - time0;


    cout << "\nTime to run: " << TestTime << "s" << endl;

    time(&time0);

    cout << "Components Test" << endl;

    list<list<int>> test1 = Components(G);

    cout << "There are " << test1.size() << " Components \n\n";

    for (auto it = test1.begin(); it != test1.end(); ++it)
    {
        for (auto ti = (*it).begin(); ti != (*it).end(); ++ti)
            cout << *ti << " ";
        cout << endl;
    }

    time(&time1);

    TestTime = time1 - time0;

    cout << "\nTime to run: " << TestTime << "s" << endl;

    time(&time1);

    map<int, list<int>> D = DijkstrasAlgorithm(G, s);

    cout << "Dijkstra's Test" << endl;

    for (auto it = D.begin(); it != D.end(); ++it)
    {
        cout << it->first << ": ";
        for (auto ti = it->second.begin(); ti != it->second.end(); ++ti)
        {
            cout << *ti << " ";
        }
        cout << endl;
    }

    time(&time1);

    TestTime = time1 - time0;

    cout << "\nTime to run: " << TestTime << "s\n\n\n" << endl;

}

void MasterTest()
{
    Graph newGraph;

    newGraph.AddEdge(5, 2);
    newGraph.AddEdge(2, 3);
    newGraph.AddEdge(3, 5);
    newGraph.AddEdge(1, 5);
    newGraph.AddEdge(1, 6);
    newGraph.AddEdge(1, 7);
    newGraph.AddEdge(7, 8);
    newGraph.AddEdge(11, 12);
    newGraph.AddEdge(12, 13);
    newGraph.AddEdge(13, 11);
    newGraph.AddEdge(6, 9);
    newGraph.AddEdge(1, 9);

    testGraph(newGraph, 13);

    Graph testG1;
    makeNCycle(testG1, 100);

    Graph testG2;
    makeComplete(testG2, 100);

    Graph testG3;
    makeEmptyGraph(testG3, 100);

    Graph testG4;
    makeHeap(testG4, 100);

    Graph testG5;
    makeTruncatedHeap(testG5, 10, 25);

    Graph testG6;
    makeMod(testG6, 3, 100);

    testGraph(testG1);
    testGraph(testG2);
    testGraph(testG3);
    testGraph(testG4);
    testGraph(testG5, 11);
    testGraph(testG6);

    //All test good!
}