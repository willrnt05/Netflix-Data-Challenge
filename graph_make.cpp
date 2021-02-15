#include "graph_make.h"

unordered_map<int, Movie> ReadTitles(string FileName)
{
    unordered_map<int, Movie> returnVal;

    fstream Movie1(FileName);

    cout << "Loading Movie Titles....." << endl;

    if (Movie1.is_open())
    {
        
        string line, number, year, title;

        while (getline(Movie1, line))
        {
            istringstream stream(line);
            getline(stream, number, ',');
            getline(stream, year, ',');
            getline(stream, title, ',');
            Movie tempMovie;
            tempMovie.title = title;
            tempMovie.year = year;
            returnVal[stoi(number)] = tempMovie;
        }
        cout << "Movie Titles finished loading." << endl;
        Movie1.close();
    }
    else
    {
        cout << "Something went wrong" << endl;
    }

    return returnVal;
}

void ReadRatings(Graph& G1, Graph& G2, Graph& G3) //O(nlog(r))
{

    int lineCount = 0;

    vector<Rating> currentIds;

    cout << "Reading Rating Data........." << endl;
    for (int i = 1; i < 5; ++i)
    {
        fstream F1("ratings_data_" + to_string(i) + ".txt");
        if (F1.is_open())
        {
            string line, customer_id, rating, date;

            while (getline(F1, line))
            {

                if (line.back() == ':')
                {
                    int id = stoi(line.substr(0, line.size() - 1));
                    cout << id << endl;
                    if (currentIds.size() > 1)
                    {
                        for (int i = 0; i < currentIds.size() - 1; ++i)
                        {
                            for (int j = i + 1; j < currentIds.size(); ++j)
                            {
                                //O(NR^2) is stuck......Goal is to elimate any Log(r).
                                //Graph 3 is if they have 2 with a 7+ rating
                                //Graph 2 is if they have 1 with a 7+ rating
                                //Graph 1 is if they have rated the same movie
                                //cout << currentIds[i].customer_id << " && " << currentIds[j].customer_id << endl;
                                G1.AddEdge(currentIds[i].customer_id, currentIds[j].customer_id);
                                if ((currentIds[i].rating >= 7) &&
                                    (currentIds[j].rating >= 7))
                                {
                                    if (G2.IsEdge(currentIds[i].customer_id, currentIds[j].customer_id))
                                    {
                                        G3.AddEdge(currentIds[i].customer_id, currentIds[j].customer_id);
                                    }
                                }
                                else if ((currentIds[i].rating >= 7) &&
                                    (currentIds[j].rating >= 7))
                                {
                                    G2.AddEdge(currentIds[i].customer_id, currentIds[j].customer_id);
                                }
                            }
                        }
                    }
                    vector<Rating> blank;
                    currentIds = blank;
                }
                else
                {

                    istringstream stream(line);

                    getline(stream, customer_id, ',');
                    getline(stream, rating, ',');
                    getline(stream, date, ',');

                    Rating tempRating;

                    tempRating.customer_id = stoi(customer_id);
                    tempRating.rating = stoi(rating);
                    tempRating.date = date;

                    currentIds.push_back((tempRating));

                    //Because customer_id's are unique and unordered_maps tend to insert and retrieve at O(1) for unique arguments, this should be O(1) generally
                    //M[MovieId].movieRatings[stoi(customer_id)] = tempRating;

                    // Real question is..... how do I now quickly find customer id's in common without insane runtime......


                }
            }

            F1.close();
        }
        else
        {
            cout << "Something went wrong" << endl;
        }
        if (currentIds.size() > 1)
        {
            for (int i = 0; i < currentIds.size() - 1; ++i)
            {
                for (int j = i + 1; j < currentIds.size(); ++j)
                {
                    //Graph 3 is if they have 2 with a 7+ rating
                    //Graph 2 is if they have 1 with a 7+ rating
                    //Graph 1 is if they have rated the same movie
                    //cout << currentIds[i].customer_id << " && " << currentIds[j].customer_id << endl;
                    G1.AddEdge(currentIds[i].customer_id, currentIds[j].customer_id);
                    if (G2.IsEdge(currentIds[i].customer_id, currentIds[j].customer_id) && ((currentIds[i].rating >= 7) &&
                        (currentIds[j].rating >= 7)))
                    {
                        G3.AddEdge(currentIds[i].customer_id, currentIds[j].customer_id);
                    }
                    if ((currentIds[i].rating >= 7) &&
                        (currentIds[j].rating >= 7))
                    {
                        G2.AddEdge(currentIds[i].customer_id, currentIds[j].customer_id);
                    }
                }
            }
        }
        cout << "Finished reading file " << i << endl;
    }
    cout << "Movie Ratings finished loading." << endl;
}


