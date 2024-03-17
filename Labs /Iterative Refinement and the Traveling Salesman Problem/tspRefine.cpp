
/*
 * Name: Harrison Holt 
 * Date Submitted: 5-1-23 
 * Lab Section: 005 
 * Assignment Name: lab 11
 */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

const int N = 14; //Number of cities in cities.txt

typedef pair<double, double> Point; //<latitude,longitude> of a city

vector<Point> P(N), best; //P - current solution, best - best solution

map<Point, int> cities; //Point (latitude,longitude) -> index of city in cities.txt order

string cityNames[] = {
    "New York City",
    "Chicago",
    "Los Angeles",
    "Toronto",
    "Houston",
    "Montreal",
    "Mexico City",
    "Vancouver",
    "Atlanta",
    "Denver",
    "San Juan",
    "New Orleans",
    "Miami",
    "Kansas City"
}; //Index of a city -> city name

//Calculates "distance"
//Units are lat./long. "degrees" on an x-y plane
//to simplify calculations (not mi/km on globe)
double dist(int i, int j)
{
    double dx = P[(i + N) % N].first - P[(j + N) % N].first;
    double dy = P[(i + N) % N].second - P[(j + N) % N].second;
    return sqrt(dx * dx + dy * dy);
}

// Returns true if a swap of edges (i,i+1) and (j,j+1) will reduce the length of the tour
bool refine(double &len)
{
    // loop through each pair of edges
    for (int i = 0; i < N; i++) {
        for (int j = i + 2; j < N; j++) {
            // check if there is a decrease in tour length if the edges are swapped with their diagonals
            if (dist(i, i + 1) + dist(j, j + 1) > dist(i, j) + dist(i + 1, j + 1)) {
                // swap the edges with their diagonals
                swap(P[i + 1], P[j]);
                // update the length of the tour
                len = 0;
                for (int k = 0; k < N; k++) {
                    len += dist(k, k + 1);
                }
                return true;
            }
        }
    }
    // return false if swapping does not decrease the tour length
    return false;
}

//Returns best length for the test case
double tspRefine()
{
    double best_len = 999999999;
    ifstream fin("cities.txt");
    for (int i = 0; i < N; i++) {
        fin >> P[i].first >> P[i].second;
        cities[P[i]] = i;
    }

    // loop and caclulate the length of the tour
    double len = 0;
    for (int i = 0; i < N; i++) {
        len += dist(i, i + 1);
    }

    // refine the tour
    while (refine(len));

    // update best_len
    if (len < best_len) {
        best_len = len;
        best = P;
    }

    for (auto p : best) {
        cout << cityNames[cities[p]] << endl;
    }
    cout << "\nTotal length: " << best_len << "\n";
    return best_len;
}

/*
int main(void)
{
    double best_len = tspRefine();
    return 0;
}
*/ 
