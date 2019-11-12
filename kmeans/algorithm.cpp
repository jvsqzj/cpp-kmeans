#include <math.h>
#include <vector>
#include <stdio.h>

using namespace std;

float euclideanDistance(vector<float> vector1, vector<float> vector2) {
	// ||vector1 - vector2|| 
	vector<float> vectorOut;
	float squares = 0;
	for (vector<float>::iterator it = vector1.begin(), jt = vector2.begin(); it != vector1.end(); ++it) {
		float component = *it - *jt;
		vectorOut.push_back(component);
		printf("%f - %f = %f\n", *it, *jt, component);
		++jt;
		squares += component * component;
	}
	
	return sqrt(squares);
}	

void updateCentroid(vector<float> data[], vector<float> centroid) {
	
}

void cluster(vector<float> data[], int clusters) {
	//	Select first element of data
	//	Define initial centroids: 
	vector<float> *centroids;
	centroids = new vector<float>[clusters];

	for (int i = 0; i < clusters; i++) {
		centroids[i] = data[i];
	}

	//	Iterate over array data[] foreach data[i]:
	for (int i = 0; i < data->size() - 1; i++) {
		printf("Value of vector = ");
		//	Iterate over vector's elements
		for (vector<float>::iterator it = data[i].begin(); it != data[i].end(); ++it) {
			printf("%f ", *it);
		}
		printf("\n");

		printf("Distancia = %f \n", euclideanDistance(data[i], centroids[1]));
	}

	delete [] centroids;


}