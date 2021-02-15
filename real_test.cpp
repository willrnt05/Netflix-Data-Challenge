#include <iostream>
#include <time.h>
#include <sstream>
#include <fstream>
#include <queue>
#include <unordered_map>

#include "Graph.h"
#include "graph_make.h"
#include "graph_operations.h"
#include "simulated_test.h"


using namespace std;

void* operator new(size_t size) {
    std::cout << "System allocates " << size << " bytes\n";

    return malloc(size);
}

int main()
{
    
    MasterTest();
   unordered_map<int, Movie> TitleKey = ReadTitles("movie_titles.csv");

    time_t time1;
    time_t time0;
    time(&time0);
  

    Graph testGraph;

    cout << "Building Graph of Adjacent People" << endl;

    Graph Adjacent, AdjacentRatingSeven, TwoAdjacentRatingSeven;

    ReadRatings(Adjacent, AdjacentRatingSeven, TwoAdjacentRatingSeven);
  

    time(&time1);
    int minutes = (time1 - time0) / 60;
    int seconds = (time1 - time0) - (60 * minutes);


    /*Adjacency Defintions:
    Share a movie they have rated
    Share a movie they have both rated 7+
    Share 2 movies they have both rated 7+
    */

    cout << "Time to build Graph: " << minutes << " minutes " << seconds  << "s" << endl;

    cout << "\n\nPrinting Components of the Adjacents graph: \n\n" << endl;

    list<list<int>> test1 = connected_components(Adjacent);

    cout << "There are " << test1.size() << " Components \n\n";

    for (auto it = test1.begin(); it != test1.end(); ++it)
    {
        for (auto ti = (*it).begin(); ti != (*it).end(); ++ti)
            cout << *ti << " ";
        cout << endl;
    }

    cout << "\n\nPrinting Components with rating +7 \n\n\n";

    test1 = connected_components(AdjacentRatingSeven);

    cout << "There are " << test1.size() << " Components \n\n";

    for (auto it = test1.begin(); it != test1.end(); ++it)
    {
        for (auto ti = (*it).begin(); ti != (*it).end(); ++ti)
            cout << *ti << " ";
        cout << endl;
    }

    cout << "\n\nPrintint Components with two rated 7+ \n\n\n";
    connected_components(TwoAdjacentRatingSeven);

    test1 = connected_components(TwoAdjacentRatingSeven);

    cout << "There are " << test1.size() << " Components \n\n";

    for (auto it = test1.begin(); it != test1.end(); ++it)
    {
        for (auto ti = (*it).begin(); ti != (*it).end(); ++ti)
            cout << *ti << " ";
        cout << endl;
    }
    
    
    //Checking if malloc displays memory used
    Object* obj = new Object;
    //Lets try to find who has rated the same movie...
    return 0;
}

