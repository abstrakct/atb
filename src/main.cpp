
#include <iostream>
#include <sstream>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

#include <json/json.h>

#include "departure.h"
#include "busstop.h"

using namespace curlpp::options;
using namespace std;

const string baseUrl = "https://atbapi.tar.io/api/v1/departures/";

string getDepartureDataJson(string url)
{
	std::stringstream os;

	try {
		curlpp::Cleanup myCleanup;
		
		os << curlpp::options::Url(url);
	}

	catch(curlpp::RuntimeError &e) {
		std::cout << e.what() << std::endl;
	}

	catch(curlpp::LogicError &e) {
		std::cout << e.what() << std::endl;
	}

	return os.str();
}

int main(int argc, char *argv[])
{
	string nodeID, url;
	Departure d;
	vector<Busstop> busstopData;

	// simple argument handling for now
	if(argc <= 1) {
		cout << "Please provide nodeID for bus stop!" << endl;
		return 0;
	} else {
		nodeID = argv[1];
	}

	url = baseUrl + nodeID;

	cout << endl << "Neste fem avganger:" << endl << endl;

	string jsonString = getDepartureDataJson(url);

	for(unsigned int j = 0; j < 5; ++j) {
		if(d.parseJsonString(jsonString, j)) {
			d.printNatural();
		}
	}

	cout << "Reading busstop json data...";
	readBusstopJsonFile(busstopData);
	cout << " done." << endl;

	cout << endl;
	return 0;
}

