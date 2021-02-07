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

int main()
{
    //MasterTest();
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

    cout << "Time to build Graph: " << minutes << " minutes " << seconds  << "s" << endl;

    cout << "\n\nPrinting the Adjacents graph: \n\n" << endl;
    //Adjacent.PrintGraph();

    cout << "\n\nPrinting with rating +7 \n\n\n";
    AdjacentRatingSeven.PrintGraph();

    cout << "\n\nPrintint with two rated 7+ \n\n\n";
    TwoAdjacentRatingSeven.PrintGraph();

    //Lets try to find who has rated the same movie...
    return 0;
}

