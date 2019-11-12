// kmeans.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "algorithm.h"

const int N = 2; //Number of data pointsr

int main()
{
	// Define data input
	vector<float> data[N];
	vector<float> A, B;
	A.push_back(51.52f);
	A.push_back(-140.21f);
	A.push_back(10.21f);
	B.push_back(84.502f);
	B.push_back(0.0512f);
	B.push_back(-5.15f);
	data[0] = A;
	data[1] = B;

	std::cout << "WIP!\n";

	//callKmeans function on data input
	cluster(data, 2);
	
	//output result
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
