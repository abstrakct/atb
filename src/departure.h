/*
 * Class for storing data about departures
 */

#include <iostream>
using namespace std;

class Departure {
	public:
		Departure();
		Departure(string d, bool r, string l, string reg, string sched) : destination(d), isRealtimeData(r), line(l), registeredDepartureTime(reg), scheduledDepartureTime(sched) {}
		~Departure();

		bool parseJsonString(string input, unsigned int index);
		void print();

		string destination;
		bool isRealtimeData;
		string line;
		string registeredDepartureTime;
		string scheduledDepartureTime;
		bool isGoingTowardsCentrum;
};
