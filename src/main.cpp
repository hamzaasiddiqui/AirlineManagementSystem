/*
Project Name: Airline Management System
Author: Hamza Akhtar Siddiqui

27/01/2022

*Note
to execute[in console]:
c++ src/main.cpp src/Flight.cpp src/Passenger.cpp src/Reservations.cpp src/Graph.cpp src/Global.cpp -o AirlineManagement.exe
./AirlineManagement.exe
*/

#include "../inc/Flight.hpp"
#include "../inc/Passenger.hpp"
#include "../inc/Reservations.hpp"
#include "../inc/Graph.hpp"
#include "../inc/Global.hpp"

int main () {
    string city[5] = {"KHI", "LHR", "ISL", "RWP", "PEW"};

    Graph *graph = new Graph(5, city);
    Flights* flight = new Flights;
    Reservations* res = new Reservations;

    initializeGraph(graph);
    initializeFlights(flight);

    bool quit = false;
    int option;
    string strOption;

    cout << "-- AIRLINE MANAGEMENT SYSTEM --" << endl;

    do {
        option = menu();

        switch (option) {
            case 1: {
                graph->displayCities(city);

                break;
            }
            case 2: {
                flight->selectionSort_departure();
                flight->displayFlights();

                break;
            }
            case 3: {
                flight->selectionSort_arrival();
                flight->displayFlights();

                break;
            }
            case 4: {
                cout << "Enter city you want to search from: " << endl;
                cin >> strOption;

                int i;
                for (i = 0; i < 5; i++) {
                    if (strOption == city[i]) {
                        break;
                    }
                }

                graph->reachAdjCity(i, city);

                break;
            }
            case 5: {
                string source, destination;
                cout << "Enter the source city: ";
                cin >> source;
                cout << "Enter destination city: ";
                cin >> destination;

                graph->dijkstra(source, city, destination);
                
                break;
            }
            case 6: {
                res->makeReservation();

                break;
            }
            case 7: {
                int ID;

                cout << "Enter passenger ID to print his/her reservations: ";
                cin >> ID;

                res->findReservation(ID);

                /* Giving memory error */
                break;
            }
            case 8: {
                int fID, pID;

                cout << "Enter passenger ID to delete his/her reservations: ";
                cin >> pID;

                flight->displayFlightIDs();

                cout << "Enter flight ID to delete his/her reservations: ";
                cin >> fID;

                res->deleteReservation(pID, fID);

                break;
            }
            case 9: {
                int fID;

                flight->displayFlightIDs();
                cout << endl;

                cout << "Enter flight ID: ";
                cin >> fID;

                cout << endl;
                res->passengerOnFlight(fID);

                /* Not showing the last passenger */
                break;
            }
            case 10: {
                cout << "Thank you & Good Bye!" << endl;
                quit = true;

                break;
            }
            default: {
                cout << "Invalid Input!. Try Again!" << endl;

                break;
            }
        }
    } while (quit == false);
}
