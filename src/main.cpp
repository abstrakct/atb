
#include <iostream>
#include <sstream>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

#include <json/json.h>

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
	string departureCode, url;

	// simple argument handling for now
	if(argc <= 1) {
		cout << "Please provide departure code!" << endl;
		return 0;
	} else {
		departureCode = argv[1];
	}

	url = baseUrl + departureCode;
	cout << "Using URL: " << url << endl;

	string test = getDepartureDataJson(url);

	Json::Value root;
	Json::Reader reader;
	reader.parse(test, root);
	const Json::Value& departures = root["departures"];
	for(unsigned int i = 0; i < departures.size(); ++i) {
		std::cout << "Rute:             " << departures[i]["line"].asString() << std::endl;
		std::cout << "Destinasjon:      " << departures[i]["destination"].asString() << std::endl;
		std::cout << "Er data sanntid?  " << (departures[i]["isRealtimeData"].asBool() ? "ja" : "nei") << std::endl;
		std::cout << "Planlagt ankomst: " << departures[i]["scheduledDepartureTime"].asString().substr(11,5) << std::endl;
		std::cout << "Sanntid:          " << departures[i]["registeredDepartureTime"].asString().substr(11,5) << std::endl;

		std::cout << std::endl;
	}

	return 0;
}
