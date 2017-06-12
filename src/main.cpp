
#include <iostream>
#include <sstream>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

#include <json/json.h>

#include "departure.h"

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
	unsigned int i;

	// simple argument handling for now
	if(argc <= 1) {
		cout << "Please provide departure code!" << endl;
		return 0;
	} else {
		nodeID = argv[1];
		i = atoi(argv[2]);
	}

	url = baseUrl + nodeID;
	cout << "Using URL: " << url << endl << endl;

	string jsonString = getDepartureDataJson(url);

	Departure d;
	if(d.parseJsonString(jsonString, i)) 
		d.print();

	return 0;
}

