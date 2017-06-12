/*
 * Class for storing data about departures
 */

#include <iostream>
#include <json/json.h>

#include "departure.h"

using namespace std;

Departure::Departure()
{
}

Departure::~Departure()
{
}

// TODO: error checking!
bool Departure::parseJsonString(string input, unsigned int index)
{
	Json::Value root;
	Json::Reader reader;
	
	reader.parse(input, root);
	const Json::Value& departures = root["departures"];

	if(index > departures.size()) {
		cout << "Error:: Index higher than size!" << endl;
		return false;
	}

	isGoingTowardsCentrum = root["isGoingTowardsCentrum"].asBool();

	destination = departures[index]["destination"].asString();
	isRealtimeData = departures[index]["isRealtimeData"].asBool();
	line = departures[index]["line"].asString();
	registeredDepartureTime = departures[index]["registeredDepartureTime"].asString().substr(11,5);
	scheduledDepartureTime = departures[index]["scheduledDepartureTime"].asString().substr(11,5);

	return true;
}

void Departure::print()
{
	std::cout << "Rute:             " << line<< std::endl;
	std::cout << "Destinasjon:      " << destination << std::endl;
	std::cout << "Er data sanntid?  " << (isRealtimeData ? "ja" : "nei") << std::endl;
	std::cout << "Sanntid:          " << registeredDepartureTime << std::endl;
	std::cout << "Planlagt ankomst: " << scheduledDepartureTime << std::endl;

	std::cout << std::endl;
}
