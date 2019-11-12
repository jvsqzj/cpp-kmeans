#include <vector>
#include <list>

using namespace std;

void cluster(list<vector<double>> data, int clusters);

void euclideanDistance(vector<double> vector1, vector<double> vector2);

void updateCentroid(vector<double> cluster);
