
#include <iostream>
#include <fstream>
#include <vector>
#include <json/json.h>

#include "busstop.h"

using namespace std;

void readBusstopJsonFile(vector<Busstop> busstopData)
{
	ifstream ifs("busstops.json");
	Json::Reader reader;
	Json::Value root;

	reader.parse(ifs, root);

	Json::Value& stops = root["stops"];

	for(unsigned int i = 0; i < stops.size(); ++i) {
		Busstop b;
		b.nodeID = stops[i]["nodeId"].asString();
		b.description = stops[i]["description"].asString();
		busstopData.push_back(b);
	}
}
