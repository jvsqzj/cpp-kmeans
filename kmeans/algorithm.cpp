#include <math.h>
#include <vector>
#include <stdio.h>
#include <list>

using namespace std;

struct cluster {
	vector<double> centroid;
	list<vector<double>>* elements;
};

double euclideanDistance(vector<double> vector1, vector<double> vector2) {
	double squares = 0;

	for (vector<double>::iterator it = vector1.begin(), jt = vector2.begin(); it != vector1.end(); ++it) {
		double component = *it - *jt;
		squares += component * component;
		++jt;
	}

	return sqrt(squares);
}

void updateCentroid(vector<double> cluster) {
	
}

void cluster(list<vector<double>> data, int clusters) {
	list<vector<double>> centroids;
	
	/*    SETS INITIAL CENTROIDS    */
	list<vector<double>>::iterator i = data.begin();

	while (centroids.size() < clusters) {
		centroids.push_back(*i);
		++i;
	}

	//	Iterate over each vector in list data
	for (list<vector<double>>::iterator i = data.begin(); i != data.end(); ++i) {

		double shortestDistance = euclideanDistance(*i, *centroids.begin());

		for (list<vector<double>>::iterator j = centroids.begin()++; j != centroids.end(); ++j) {
			double distance = euclideanDistance(*i, *j);
			shortestDistance = (distance < shortestDistance) ? distance : shortestDistance;
		}

		printf("Distancia = %f \n", shortestDistance);
	}
}