#include "../inc/Global.hpp"

int menu (){
    int option = 0;

	cout << "-------------------------------------------------  " << endl;
	cout << "1- Display list of cities serviced by the airline." << endl;
	cout << "2- Display list of flight departures sorted by departure time." << endl;
	cout << "3- Display list of flight arrivals sorted by arrival time." << endl;
	cout << "4- Display list of cities reached from a particular city." << endl;
	cout << "5- Display shortest path between two cities." << endl;
	cout << "6- Book flight reservation." << endl;
	cout << "7- Display passenger reservation schedule." << endl;
	cout << "8- Delete passenger reservation." << endl;
	cout << "9- Display List of passengers in particular flight." << endl;
    cout << "10- Exit System." << endl;

    cout << "Select option: ";
    cin >> option;
    cout << "----------------------------------------------------------------------" << endl;

    return option;
}

void initializeGraph (Graph* graph) {
    graph->addEdge(0, "KHI", 1, "LHR", 3);
    graph->addEdge(0, "KHI", 2, "ISL", 4);
    graph->addEdge(1, "LHR", 0, "KHI", 3);
    graph->addEdge(1, "LHR", 2, "ISL", 2);
    graph->addEdge(2, "ISL", 0, "KHI", 4);
    graph->addEdge(2, "ISL", 3, "RWP", 1);
    graph->addEdge(3, "RWP", 4, "PEW", 1);
    graph->addEdge(4, "PEW", 2, "ISL", 1);
}

void initializeFlights (Flights* flights) {
    flights->addFlight(1, 2, 5);
    flights->addFlight(2, 7, 11);
    flights->addFlight(3, 6, 9);
    flights->addFlight(4, 10, 12);
    flights->addFlight(5, 4, 8);
    flights->addFlight(6, 4, 5);
    flights->addFlight(7, 7, 8);
    flights->addFlight(8, 1, 2);
}