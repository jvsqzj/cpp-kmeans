#include <math.h>
#include <vector>
#include <stdio.h>
#include <list>
#include <ittnotify.h>

using namespace std;

struct cluster {
	vector<double> centroid;
	list<vector<double>> elements;
	bool clusterOptimized = false;
	
	void updateCentroid(){
		//Calculate mean of elements in cluster
		//Create empty sum vector with the size of the centroid
		vector<double> vectorSum = centroid;
		for (vector<double>::iterator i = vectorSum.begin(); i != vectorSum.end(); ++i) {
			*i = 0;
		}
		for (list<vector<double>>::iterator i = elements.begin(); i != elements.end(); ++i) {
			for (vector<double>::iterator j = i->begin(), k = vectorSum.begin(); j != i->end(); ++j) {
				*k = *k + *j;
				++k;
			}
		}
		for (vector<double>::iterator j = vectorSum.begin(); j != vectorSum.end(); ++j) {
			*j = *j / elements.size();
		}

		if (vectorSum == centroid) {
			clusterOptimized = true;
		}
		else {
			//-> set mean as new centroid 
			centroid = vectorSum;
			//-> clear elements
			elements.clear();
		}
	}
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

void findClusters(list<vector<double>> data, int K) {
	list<cluster> clusters;
	
	/*    SETS INITIAL CENTROIDS    */
	list<vector<double>>::reverse_iterator i = data.rbegin();
	while (clusters.size() < K) {
		cluster centroid;
		centroid.centroid = *i;
		clusters.push_back(centroid);
		++i;
	}

	bool clustersOptimized = false;

	while (!clustersOptimized) {
		//	Start of algorithm
		//	Iterate over each vector in list data
		for (list<vector<double>>::iterator i = data.begin(); i != data.end(); ++i) {

			double shortestDistance = euclideanDistance(*i, clusters.begin()->centroid);
			list<cluster>::iterator closest = clusters.begin();

			//	Iterate over cluster list to check closest centroid
			for (list<cluster>::iterator j = ++clusters.begin(); j != clusters.end(); ++j) {
				double distance = euclideanDistance(*i, j->centroid);

				bool inCluster = (distance < shortestDistance);
				if (inCluster) {
					shortestDistance = distance;
					closest = j;
				}
			}

			closest->elements.push_back(*i);
			printf("Distancia = %f \n", shortestDistance);
		}
	}

	for (list<cluster>::iterator i = clusters.begin(); i != clusters.end(); ++i) {
		i->updateCentroid();
		clustersOptimized = !clustersOptimized*i->clusterOptimized;
	}
	printf("Are we done yet? %b", clustersOptimized);
}