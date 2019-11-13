#include <vector>
#include <list>

using namespace std;

struct cluster;

void findClusters(list<vector<double>> data, int K);

void euclideanDistance(vector<double> vector1, vector<double> vector2);

void updateCentroid(vector<double> cluster);

void printClusters(list<vector<cluster>> cluster);
