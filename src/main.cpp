
#include <iostream>
#include <sstream>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

#include <json/json.h>

using namespace curlpp::options;


/*
 * 16010000 trikk fra byen
 * 16011000 trikk til byen
 *
 * 16010710 buss fra byen
 * 16011710 buss til byen
 */
class departureData {
	public:
		departureData() {};
		~departureData(){};

		std::string destination;
		bool isRealtimeData;
		int line;
		std::string registeredDepartureTime;
		std::string  scheduledDepartureTime;
};

int main()
{
	std::stringstream os;

	try {
		curlpp::Cleanup myCleanup;
		curlpp::Easy myRequest;

		//myRequest.setOpt<Url>("https://atbapi.tar.io/api/v1/departures/16011000?pretty");
		//myRequest.perform();
		os << curlpp::options::Url("https://atbapi.tar.io/api/v1/departures/16011710?pretty");
		//std::cout << os.str() << std::endl;
	}

	catch(curlpp::RuntimeError &e) {
		std::cout << e.what() << std::endl;
	}

	catch(curlpp::LogicError &e) {
		std::cout << e.what() << std::endl;
	}

	os.seekg(0, std::ios::beg);

	Json::Value root;
	Json::CharReaderBuilder rbuilder;
	rbuilder["collectComments"] = false;
	std::string errs;
	bool ok = Json::parseFromStream(rbuilder, os, &root, &errs);
	if(ok)
		std::cout << "it worked" << std::endl;
	else
		std::cout << "it not workd!" << std::endl;


	std::cout << "size of root is " << root.size() << std::endl;
	Json::Value d = root["departures"];
	std::cout << "size of departures is " << d.size() << std::endl;

	Json::Value test;
	test = root["isGoingTowardsCentrum"];
	if(test.isBool()) {
		bool b = test.asBool();
		std::cout << "is going towards centrum: ";
		if(b)
			std::cout << "yep";
		else
			std::cout << "nope";
		std::cout << std::endl << std::endl;

	}

	//departureData *dd = new departureData();

	//for(auto it : root["departures"]) {
	//	Json::Value::Members m = it.getMemberNames();
	//	//dd->destination = it.get("destination", "foo");

	//	for(auto ms : m) {
	//		std::cout << ms << std::endl;
	//		std::cout << it.get(ms, "foo") << std::endl;
	//	}
	//	std::cout << std::endl;
	//}

	std::cout << " -----------------" << std::endl;

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
