/*
 * Class for storing data about bus stops
 */

#include <iostream>
using namespace std;

class Busstop {
	public:
		string nodeID;
		string description;
};


void readBusstopJsonFile(vector<Busstop> busstopData);
