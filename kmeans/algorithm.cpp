#include <math.h>
#include <vector>
#include <stdio.h>

using namespace std;

void cluster(vector<float> data[], int clusters) {
	//	Select first element of data
	//	Define initial centroids: 
	//vector<double> centroids[clusters - 1] = [ data[first], data[middle], data[last] ];
	
	//	Iterate over array data[] foreach data[i]:
	for (int i = 0; i <= data->size() - 1; i++) {
		printf("Value of vector = ");
		//	Iterate over vector values
		for(vector<float>::iterator it = data[i].begin(); it != data[i].end(); ++it) {
			printf("%f ", *it);
		}
		printf("\n");

		

	}
		
}

void euclideanDistance(vector<float> vector1, vector<float> vector2) {
	// ||vector1 - vector2|| 
}	

void updateCentroid(vector<float> data[], vector<double> centroid) {
	
}