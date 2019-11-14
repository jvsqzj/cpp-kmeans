#include <math.h>
#include <vector>
#include <stdio.h>
#include <list>
#include <algorithm>

using namespace std;

vector<double> calculateMean(list<vector<double>> dataPoints) {
	//Calculate mean of elements in cluster
	//Create empty (zero value) sum vector with the size of the centroid
	vector<double> meanVector = *dataPoints.begin();
	for (vector<double>::iterator i = meanVector.begin(); i != meanVector.end(); ++i) {
		*i = 0;
	}
	//Calculate mean
	for (list<vector<double>>::iterator i = dataPoints.begin(); i != dataPoints.end(); ++i) {
		for (vector<double>::iterator j = i->begin(), k = meanVector.begin(); j != i->end(); ++j) {
			*k = *k + *j;
			++k;
		}
	}
	for (vector<double>::iterator j = meanVector.begin(); j != meanVector.end(); ++j) {
		*j = *j / dataPoints.size();
	}
	return meanVector;
}

struct cluster {
	vector<double> centroid;
	vector<double> lastCentroid;
	list<vector<double>> elements;
	bool clusterOptimized = false;
	
	void updateCentroid(){
		vector<double> meanVector = calculateMean(elements);
		if (centroid == meanVector) {
			clusterOptimized = true;
		}
		else {
			centroid = meanVector;	//-> set mean as new centroid 
			elements.clear();		//-> clear elements
		}
	}
};

void printVector(vector<double> vect) {
	for (vector<double>::iterator j = vect.begin(); j != vect.end(); ++j) {
		printf(" %f ", *j);
	}
}

void printClusters(list<cluster> data) {
	for (list<cluster>::iterator i = data.begin(); i != data.end(); ++i) {
		printf("Cluster centroid: ");
		printVector(i->centroid);
		printf("\n");
		for (list<vector<double>>::iterator j = i->elements.begin(); j != i->elements.end(); ++j) {
			printf("                  ");
			printVector(*j);
			printf("\n");
		}
	}
}

double euclideanDistance(vector<double> vector1, vector<double> vector2) {
	double squares = 0;

	for (vector<double>::iterator it = vector1.begin(), jt = vector2.begin(); it != vector1.end(); ++it) {
		double component = *it - *jt;
		squares += component * component;
		++jt;
	}

	return sqrt(squares);
}

void findClusters(list<vector<double>> data, int K, int maxIterations) {
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
	int iterations = 0;
	while (!clustersOptimized && iterations < maxIterations) {
		//	Start of algorithm
		for (list<vector<double>>::iterator i = data.begin(); i != data.end(); ++i) {		//	Iterate over each vector in list data
			double shortestDistance = euclideanDistance(*i, clusters.begin()->centroid);
			list<cluster>::iterator closest = clusters.begin();

			for (list<cluster>::iterator j = ++clusters.begin(); j != clusters.end(); ++j) {//	Iterate over cluster list to check closest centroid
				double distance = euclideanDistance(*i, j->centroid);
				bool inCluster = (distance < shortestDistance);
				if (inCluster) {
					shortestDistance = distance;
					closest = j;
				}
			}
			closest->elements.push_back(*i);
		}
		bool clustersDone = true;
		for (list<cluster>::iterator i = clusters.begin(); i != clusters.end(); ++i) {
			i->updateCentroid();
			clustersDone = clustersDone * i->clusterOptimized;
		}
		clustersOptimized = clustersDone;
		//printf("Are we done yet? %d \n", clustersOptimized);
		iterations++;
	}
	printClusters(clusters);
}