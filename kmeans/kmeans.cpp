// kmeans.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "algorithm.h"

const int N = 3; //Number of data pointsr

using namespace std;

int main()
{
	list<vector<double>> data;
	// Define data input
	vector<double> A, B, C, D, E, F;
	A.push_back(51.52f);
	A.push_back(-140.21f);
	A.push_back(-0.21f);
	A.push_back(2.56f);
	A.push_back(-0.456f);
	A.push_back(88.21f);
	B.push_back(84.502f);
	B.push_back(0.0512f);
	B.push_back(-5.15f);
	B.push_back(8.502f);
	B.push_back(78.12f);
	B.push_back(-15.15f);
	C.push_back(5.2f);
	C.push_back(-0.21f);
	C.push_back(1.21f);
	C.push_back(1.52f);
	C.push_back(-11.09f);
	C.push_back(0.123f);
	D.push_back(5.124f);
	D.push_back(-10.21f);
	D.push_back(-789.21f);
	D.push_back(0.005f);
	D.push_back(-47.6f);
	D.push_back(8.21f);
	E.push_back(4.52f);
	E.push_back(0.52f);
	E.push_back(5.1f);
	E.push_back(8.502f);
	E.push_back(798.12f);
	E.push_back(-1.15f);
	F.push_back(15.2f);
	F.push_back(-0.2221f);
	F.push_back(-1.21f);
	F.push_back(1.352f);
	F.push_back(-11.1109f);
	F.push_back(10.123f);

	data.push_back(A);
	data.push_back(B);
	data.push_back(C);
	data.push_back(D);
	data.push_back(E);
	data.push_back(F);

	std::cout << "WIP!\n";

	//callKmeans function on data input
	findClusters(data, 2);
	
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
