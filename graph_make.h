#pragma once

#include <iostream>
#include <time.h>
#include <sstream>
#include <fstream>
#include <queue>
#include "Graph.h"
#include <unordered_map>

struct Rating
{
    int customer_id;
    int rating;
    string date;
};

struct Movie
{
    string year;
    string title;
    
};

unordered_map<int, Movie> ReadTitles(string FileName);

void ReadRatings(Graph& G1, Graph& G2, Graph& G3);

